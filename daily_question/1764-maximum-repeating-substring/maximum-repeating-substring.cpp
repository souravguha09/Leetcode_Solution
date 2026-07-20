class Solution {
public:
    int maxRepeating(string seq, string word) {
        int m=seq.size(),n=word.size();
        int k=0;
        vector<int>dp(m+1,0);
        for(int i=n;i<=m;i++){
            if(seq.substr(i-n,n)==word){
                dp[i]=dp[i-n]+1;
                k=max(k,dp[i]);
            }
        }
        return k;
    }
};