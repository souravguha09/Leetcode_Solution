class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans,t;
      while(ss >> t){
        reverse(t.begin(),t.end());
         if (!ans.empty()) ans += " ";
         ans+=t;

      }
        return ans;
    }
};