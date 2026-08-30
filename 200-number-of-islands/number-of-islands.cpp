class Solution {
private:
void bfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int i,int j){
    vis[i][j]=true;
    int n=grid.size(),m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        for(int i=0;i<4;i++){
                int nrow=it.first+dir[i].first;
                int ncol=it.second+dir[i].second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};