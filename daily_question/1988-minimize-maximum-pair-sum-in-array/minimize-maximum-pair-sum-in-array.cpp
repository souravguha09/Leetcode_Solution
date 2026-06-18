class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=INT_MIN;
        for(int i=0;i<n/2;i++){
            sum=max(sum,nums[i]+nums[n-1-i]);
        }
        return sum;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();