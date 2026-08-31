class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
         auto isconnected=[&](int u,int v){
            unordered_set<int>vis;
            stack<int>q;
            q.push(u);
            while(!q.empty()){
                int node=q.top();
                q.pop();
                if(vis.count(node)) continue;
                vis.insert(node);
                if(node==v) return true;
                for(int negh:adj[node]){
                    q.push(negh);
                }
            }
            return false;
         };

        for(auto & edge:edges){
            if(adj.count(edge[0]) && adj.count(edge[1]) && isconnected(edge[0],edge[1])) return edge;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return {};
    }
};