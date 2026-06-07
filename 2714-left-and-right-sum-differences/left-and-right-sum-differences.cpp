class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            rsum-=nums[i];
            int x=nums[i];
            nums[i]=abs(rsum-lsum);
            lsum+=x;
        }
        return nums;
    }
};