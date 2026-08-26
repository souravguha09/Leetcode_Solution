class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int minlen=INT_MAX;
        int l=0,r=0,n=s.size();
        int ones=0;
        string ans="";
        while(r<n){
            if(s[r]=='1') ones++;
            while(ones>k){
                if(s[l]=='1') ones--;
                l++;
            }
            if(ones==k){
                while(l<=r && s[l]=='0') l++;
                int currlen=r-l+1;
                string curr=s.substr(l,currlen);
                if((currlen<minlen) || (currlen==minlen && ans>curr)){
                    minlen=currlen;
                    ans=curr;
                }
            }
          r++;
        }
        return ans;
    }
};