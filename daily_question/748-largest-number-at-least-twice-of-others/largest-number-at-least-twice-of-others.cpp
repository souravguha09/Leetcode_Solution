class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int l=nums[0];
        int sl=-1;
        int idx=0;
        for(int i=0;i<n;i++){
           if(nums[i]>l){
            sl=l;
            l=nums[i];
            idx=i;
           }else if(nums[i]<l && nums[i]>sl) sl=nums[i];
        }
        if(sl*2<=l) return idx;
        return -1;
    }
};