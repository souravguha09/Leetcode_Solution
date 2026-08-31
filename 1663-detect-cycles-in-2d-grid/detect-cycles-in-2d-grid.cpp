class Solution {
private:
 bool detect(int i,int j,char &c,vector<vector<char>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&dir){
    vis[i][j]=1;
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,pair<int,int>>>q;
    q.push({{i,j},{-1,-1}});
    while(!q.empty()){
        int di=q.front().first.first;
        int dj=q.front().first.second;
        auto previ=q.front().second.first;
        auto prevj=q.front().second.second;
        q.pop();
        for(int i=0;i<4;i++){
          int nrow=di+dir[i].first;
          int ncol=dj+dir[i].second;
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==c){
            if(!vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},{di,dj}});
            }else if(previ!=nrow || prevj!=ncol) return true;
          }
        }
    }
    return false;
 }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    bool cycle=detect(i,j,grid[i][j],grid,vis,dir);
                    if(cycle) return true;
                }
            }
        }
        return false;
    }
};