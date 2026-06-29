class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int cal=0;
        int mini=nums[0];
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            cal+=nums[i];
        }
        int ans=sum-cal;
        if(cal==sum) ans=n;
        if(mini!=0) ans=0;
        return ans;
    }
};