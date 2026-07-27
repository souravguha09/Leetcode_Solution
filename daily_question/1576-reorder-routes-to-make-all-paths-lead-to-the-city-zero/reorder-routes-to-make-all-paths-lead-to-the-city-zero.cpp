class Solution {
public:
    int dfs(vector<vector<int>>& adj,vector<bool>&vis,int i){
     int changes=0;
        vis[i]=true;
        for(auto &it:adj[i]){
            if(!vis[abs(it)])
            changes+=dfs(adj,vis,abs(it))+(it>0);
        }
        return changes;
    }
    int minReorder(int n, vector<vector<int>>& con) {
    
        vector<bool>vis(n);
        vector<vector<int>>adj(n);
        for(auto &c:con){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        return dfs(adj,vis,0);

    }
};