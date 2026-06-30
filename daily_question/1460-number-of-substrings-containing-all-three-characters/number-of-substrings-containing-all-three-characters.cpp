class Solution {
public:
    int numberOfSubstrings(string s) {
      int n=s.length();
      vector<int>freq(3,0);
      int i=0,j=0,ans=0;
      while(j<n){
        freq[s[j]-'a']++;
        while(freq[0] && freq[1] && freq[2]){
             ans+=n-j;
             freq[s[i++]-'a']--;
        }
        j++;
      } 
      return ans; 
    }
};