class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<rooms.size();i++){
            for(auto &x:rooms[i]){
                adj[i].push_back(x);
            }
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};