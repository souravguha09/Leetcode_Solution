class Solution {
    int cnt=0;
public:
   void dfs(int i,vector<vector<int>>& adj,vector<bool>&vis){
        vis[i]=true;
        for(auto &it:adj[i]){
            if(!vis[it]){
                vis[it]=true;
                dfs(it,adj,vis);
            }
        }
   }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>>adjls(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};