class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &x:roads){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool>visited(n+1,false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        int ans=INT_MAX;
        while(!q.empty()){
           int i=q.front();
           q.pop();
           for(auto &[neg,wt]:adj[i]){
            ans=min(ans,wt);
            if(!visited[neg]){
                visited[neg]=true;
                q.push(neg);
            }
           }
        }
        return ans;
    }
};