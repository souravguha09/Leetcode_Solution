class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
       sort(nums.begin(),nums.end());
      int maxi=*max_element(nums.begin(),nums.end());
      vector<int>dp(maxi+2,0);
     
      int ans=INT_MIN;
      for(int x:nums){
        dp[x+1]=max(dp[x]+1,dp[x+1]);
        dp[x]=max(dp[x],dp[x-1]+1);
        ans=max({ans,dp[x],dp[x+1]});
      }
      return ans;
    }
};