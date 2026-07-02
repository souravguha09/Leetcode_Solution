class Solution {
public:
bool isvowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
    int maxVowels(string s, int k) {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<k;i++) {
            if(isvowel(s[i])) cnt++;
        }
        int maxi=cnt;
        int j=k;
        int i=0;
        while(j<n){
            if(isvowel(s[i++])) cnt--;
            if(isvowel(s[j++])) cnt++;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};