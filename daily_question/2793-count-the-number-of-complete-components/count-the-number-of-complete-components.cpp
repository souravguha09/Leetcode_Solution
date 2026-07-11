class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans=0;
        vector<int>vis(n);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int node=0;
            int edgecnt=0;
            queue<int>q;
            q.push(i);
            vis[i]=true;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                node++;
                edgecnt+=adj[u].size();
                for(int negh:adj[u]){
                    if(!vis[negh]){
                        vis[negh]=true;
                        q.push(negh);
                    }
                }
            }
            edgecnt/=2;
            if(edgecnt==node*(node-1)/2) ans++;
        }
        return ans;
    }
};