class Solution {
public:
    int maxScore(string s) {
        int zeros=0;
        int ones=count(s.begin(),s.end(),'1');
        int ans=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='1') ones-=1;
            if(s[i]=='0') zeros+=1;
            ans=max(ans,ones+zeros);
        }
        return ans;
    }
};