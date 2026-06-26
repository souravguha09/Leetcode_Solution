class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> mp(256, -1);
        vector<bool> used(256, false);

        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == -1) {
                if (used[t[i]]) return false;
                mp[s[i]] = t[i];
                used[t[i]] = true;
            } else if (mp[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};