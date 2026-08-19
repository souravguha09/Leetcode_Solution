class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>>mp;
 
        for(auto &it:reservedSeats){
            mp[it[0]].push_back(it[1]);
        }
        int ans = (n - mp.size()) * 2;
        for(auto &it:mp){
            vector<int>&col=it.second;
            vector<bool>seat(11,false);
            for(auto &a:col){
                seat[a]=true;
            }
            bool left=!seat[2]&&!seat[3]&&!seat[4]&&!seat[5];
            bool mid=!seat[6]&&!seat[7]&&!seat[4]&&!seat[5];
            bool right=!seat[6]&&!seat[7]&&!seat[8]&&!seat[9];
            if(left && right) ans+=2;
            else if(left || right || mid) ans+=1;
        }
        return ans;
    }
};