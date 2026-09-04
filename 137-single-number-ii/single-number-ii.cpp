class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto & num:nums){
            freq[num]++;
        }
        for(auto &[key,count]: freq){
            if(count==1) return key;
        }
        return -1;
    }
};