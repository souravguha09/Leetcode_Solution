class Solution {
public:
    int firstUniqChar(string s) {
        queue<char>q;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.length();i++){
             q.push(s[i]);
            mp[s[i]-'a'].push_back(i);
        }
        while(!q.empty()){
            char c=q.front();
            q.pop();
            if(mp[c-'a'].size()==1) {
                auto v=mp[c-'a'];
                return v[0];
            }
        }
        return -1;
    }
};