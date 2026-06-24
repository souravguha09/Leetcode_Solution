class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res; 
        int l = 0; 

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || (long long)nums[i+1] - nums[i] != 1) {
                if (l == i) {
                    res.push_back(to_string(nums[l]));
                } else {
                    res.push_back(to_string(nums[l]) + "->" + to_string(nums[i]));
                }
                l = i + 1; 
            }
        }
        
        return res;
    }
};