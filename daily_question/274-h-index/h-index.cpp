class Solution {
public:
    int hIndex(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=n-i)
            maxi=max(maxi,n-i);
        }
        return maxi;
    }
};