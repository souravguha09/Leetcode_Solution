class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp;
        stringstream ss(s);

        while (ss >> temp)
            words.push_back(temp);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_set<string> seen;

        for (int i = 0; i < pattern.size(); i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (seen.count(words[i]))
                    return false;
                mp[pattern[i]] = words[i];
                seen.insert(words[i]);
            }
            else if (mp[pattern[i]] != words[i]) {
                return false;
            }
        }

        return true;
    }
};