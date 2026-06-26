class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string t) {
        vector<string>ans;
        for(auto s: words){
        if (s.size() != t.size()) continue;;

        vector<int> mp(256, -1);
        vector<bool> used(256, false);
       bool ok=true;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == -1) {
                if (used[t[i]]) {
                    ok=false;
                    break;
                }
                mp[s[i]] = t[i];
                used[t[i]] = true;
            } else if (mp[s[i]] != t[i]) {
                ok=false;
                break;
            }
        }
        if(ok)
        ans.push_back(s);
        }
        return ans;
    }
};