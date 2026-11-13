class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.length();
        vector<vector<string>> ans;
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i] && j == -1)
                j = i;
            if (s1[i] == s2[i] && j != -1) {
                ans.push_back({s1.substr(j, i - j), s2.substr(j, i - j)});
                j = -1;
            }
        }
        if (j != -1) {
            ans.push_back({s1.substr(j), s2.substr(j)});
        }
        return ans;
    }
};