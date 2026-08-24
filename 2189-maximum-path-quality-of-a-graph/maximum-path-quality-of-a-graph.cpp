class Solution {
private:
    void dfs(vector<int>& values, vector<vector<pair<int,int>>>& graph,vector<int>&vis,int &res,int node,int score,int time, int maxTime){
        if(time>maxTime) return;
        if(vis[node]==0) score+=values[node];
        vis[node]++;
        if(node==0) res=max(res,score);
        for(auto &it:graph[node]){
            int neigh=it.first;
            int newtime=time+it.second;
            dfs(values,graph,vis,res,neigh,score,newtime,maxTime);
        }
        vis[node]--;
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>>graph(n);
        for(auto &it:edges){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});  
        }
        int res=values[0];
        vector<int>vis(n,0);
        dfs(values,graph,vis,res,0,0,0,maxTime);
        return res;
    }
};