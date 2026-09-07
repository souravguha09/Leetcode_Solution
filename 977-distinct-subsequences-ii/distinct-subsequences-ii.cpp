class Solution {
public:
    static const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int>dp(26,0);
        int sum=0;
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            int cur=(1+sum-dp[idx]+MOD) % MOD;  
            sum=(sum+cur) % MOD;
            dp[idx] = (dp[idx]+cur) % MOD;
        }
        return sum;
    }
};