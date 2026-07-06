class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;
        int n=nums.size();
        int sum=0;
     int i=0,j=0;
     while(j<n){
            sum+=nums[j++];

            while(sum>=target){
            minlen=min(minlen,j-i);
            sum-=nums[i++];
        }
     }

     return minlen==INT_MAX?0:minlen;
    }
};