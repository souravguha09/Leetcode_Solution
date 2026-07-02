class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len=0;
        int zero=0,j=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0) zero++;
           if(zero>k){
            if(nums[j++]==0) zero--;
           }
           max_len=max(max_len,i-j+1);
        }
        return max_len;
    }
};