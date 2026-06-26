class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size(), pref = n;

        vector<int> freq(2 * n + 1);
        freq[n] = 1;

        long long less = 0, ans = 0;

        for (int num : nums) {
            if (num == target)
                less += freq[pref++];
            else
                less -= freq[--pref];

            ++freq[pref];
            ans += less;
        }

        return ans;
    }
};