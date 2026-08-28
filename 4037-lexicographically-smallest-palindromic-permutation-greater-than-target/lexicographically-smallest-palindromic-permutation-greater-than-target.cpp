class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        
        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        if (odd_count > (n % 2)) return "";

        int m = n / 2;
        vector<int> half_pool(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_pool[i] = count[i] / 2;
        }
        auto build_palindrome = [&](const string& first_half) -> string {
            string full = first_half;
            if (n % 2 != 0) {
                full += (char)('a' + odd_char);
            }
             string second_half = first_half;
            reverse(second_half.begin(), second_half.end());
            full += second_half;
            return full;
        };

   
       vector<int> pool = half_pool;
        bool can_match_half = true;
        for (int i = 0; i < m; ++i) {
            int c = target[i] - 'a';
            if (pool[c] > 0) {
                pool[c]--;
            } else {
                can_match_half = false;
                break;
            }
        }

        if (can_match_half) {
            string candidate = build_palindrome(target.substr(0, m));
            if (candidate > target) {
                return candidate;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            pool = half_pool;
            bool prefix_possible = true;
            for (int j = 0; j < i; ++j) {
                int c = target[j] - 'a';
                if (pool[c] > 0) {
                    pool[c]--;
                } else {
                    prefix_possible = false;
                    break;
                }
            }

            if (!prefix_possible) continue;

       
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (pool[c] > 0) {
                    string first_half = target.substr(0, i);
                    first_half += (char)('a' + c);
                    pool[c]--;

                    for (int k = 0; k < 26; ++k) {
                        while (pool[k] > 0) {
                            first_half += (char)('a' + k);
                            pool[k]--;
                        }
                    }

                    return build_palindrome(first_half);
                }
            }
        }

        return "";

        
    }
};