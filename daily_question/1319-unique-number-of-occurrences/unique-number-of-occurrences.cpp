class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int num:arr){
          mp[num]++;
        }
        unordered_set<int>st;
        for(auto n:mp) st.insert(n.second);
        return mp.size()==st.size();
    }
};