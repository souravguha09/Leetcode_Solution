class Solution {
private:
void bfs(vector<vector<int>>& image,vector<vector<bool>>& vis,int i,int j,int color,int inicolor){
    int n=image.size();
    int m=image[0].size();
    vis[i][j]=true;
    image[i][j]=color;
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
                if(image[nrow][ncol]==inicolor && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int inicolor=image[sr][sc];
        vector<vector<int>>copy=image;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        bfs(copy,vis,sr,sc,color,inicolor);
        return copy;
    }
};