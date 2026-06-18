class Solution {
public:
int minpair(vector<int>&nums){
    int pos=-1;
    int minsum=INT_MAX;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]+nums[i+1]<minsum){
            minsum=nums[i]+nums[i+1];
            pos=i;
        }
    }
    return pos;
}
void mergepair(vector<int>&nums,int pos){
    nums[pos]+=nums[pos+1];
    nums.erase(nums.begin()+pos+1);
}
    int minimumPairRemoval(vector<int>& nums) {
      int  cnt=0;
      while(!is_sorted(nums.begin(),nums.end())){
        mergepair(nums,minpair(nums));
        cnt++;
      }
      return cnt;
    }
};