class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>com(n,0);
        int co=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) co++;
            com[i]=co;
        }
         for( auto &it:queries){
            ans.push_back(com[it[0]]==com[it[1]]);
         }
         return ans;
    }
};