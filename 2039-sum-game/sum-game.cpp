class Solution {
public:
    bool sumGame(string num) {
        double ans=0.0;
        int n=num.size();
        for(int i=0;i<n;i++){
            double sign;
            if(i<n/2) sign=1;
            else sign=-1;
            double value;
            if(num[i]=='?') value=4.5;
            else value=num[i]-'0';
            ans+=sign*value;
        }
        if(ans!=0.0) return true;
        else return false;
    }
};