class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        
        int lim = 1 << ((int)log2(mx) + 2);             

        vector<bool> s1(lim, false);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> s2(lim, false);

        for (int x = 0; x < lim; x++) {
            if (!s1[x]) continue;
            for (int v : nums) {
                s2[x ^ v] = true;
            }
        }

        int cnt = 0;
        for (bool x : s2)
            cnt += x;

        return cnt;
    }
};