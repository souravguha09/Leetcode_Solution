class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int tarcnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) tarcnt++;
                int len=j-i+1;
             if(tarcnt>len/2) cnt++;
            }
        }
      return cnt;
    }
};