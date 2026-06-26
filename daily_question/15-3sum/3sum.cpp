class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum,l,r;
        vector<vector<int>>tp;
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
             l=i+1;
             r=n-1;
            while(l<r){
            sum=nums[i]+nums[l]+nums[r];
            if(sum==0) {
                tp.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) l++;
                while (l < r && nums[r] == nums[r + 1]) r--;
            }
            else if(sum<0) l++;
            else r--;
            }
        }
        return tp;
    }
};