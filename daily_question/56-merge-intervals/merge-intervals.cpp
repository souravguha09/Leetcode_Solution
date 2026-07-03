class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>prev=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i][0]<=prev[1]){
                prev[1]=max(prev[1],nums[i][1]);
            }else{
                ans.push_back(prev);
                prev=nums[i];
            }
           
        }
        ans.push_back(prev);
        return ans;
    }
};