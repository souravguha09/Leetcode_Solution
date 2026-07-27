class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=-1;
        int smax=-1;
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                smax=maxi;
                maxi=nums[i];
            }else {
                if(smax<nums[i])
             smax=nums[i];
            }
        }
        return (maxi-1)*(smax-1);
    }
};