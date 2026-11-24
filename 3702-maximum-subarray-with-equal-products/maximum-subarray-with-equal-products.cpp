class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;

            for (int j = i; j < n; j++) {
                if (prod > LLONG_MAX / nums[j])
                    break;

                prod *= nums[j];

                long long g = 0;
                for (int k = i; k <= j; k++) {
                    g = gcd(g, (long long)nums[k]);
                }

                long long l = 1;
                for (int k = i; k <= j; k++) {
                    l = l / gcd(l, (long long)nums[k]) * nums[k];
                }

                if (prod == l * g)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};