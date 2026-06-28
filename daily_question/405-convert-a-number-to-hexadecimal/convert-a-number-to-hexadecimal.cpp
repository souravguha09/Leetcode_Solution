class Solution {
public:
    string toHex(int num) {
        string ans="";
        long long n=num;
        if(n==0) return "0";
        if(n<0){
            n=4294967296+n;
        }
        while(n>0){
            int x= n%16;
            n/=16;
          if(x>9){
            x=x%10;
            char c='a'+x;
            ans.push_back(c);
          }
          else ans.push_back('0'+x);
        }
        
         reverse(ans.begin(),ans.end());
         return ans;
    }
};