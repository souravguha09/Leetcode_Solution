class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        vector<int>ans;
        int i=1;
        for(int x:nums){
            if(mp.find(x)==mp.end()) mp[x]=i++;
        }
        for(int x:arr){
            ans.push_back(mp[x]);
        }
      return ans;
    }
};