class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            int x = 0;

            for(char c : s) {
                x += c - '0';
            }

            nums[i] = x;
        }

        return *min_element(nums.begin(), nums.end());
    }
};