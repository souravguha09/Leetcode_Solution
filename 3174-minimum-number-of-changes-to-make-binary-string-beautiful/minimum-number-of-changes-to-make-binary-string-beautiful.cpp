class Solution {
public:
    int minChanges(string s) {
      int cnt=0;
      int i=0;
      int len=0;
      int prev;
      while(i<s.length()){
        if(len==0){
        prev=s[i];
            len++;
        }
        else if(prev!=s[i]){
             len=0;
             cnt++;
        }else len=0;
 
        i++;
      }  
      return cnt;
    }
};