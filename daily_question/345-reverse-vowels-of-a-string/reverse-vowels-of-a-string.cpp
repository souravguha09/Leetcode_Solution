class Solution {
public:
bool isvowel(char c) {
    c = tolower(c);
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
    string reverseVowels(string s) {
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(isvowel(s[i]) && isvowel(s[j])) {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            if(!isvowel(s[i])) i++;
            if(!isvowel(s[j])) j--;
        }
        return s;
    }
};