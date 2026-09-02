class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        vector<pair<int,int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        for(int i=0;i<n;i++){
           if(board[i][0]=='O'){
            vis[i][0]=1;
            q.push({i,0});
           }
           if(board[i][m-1]=='O'){
            vis[i][m-1]=1;
            q.push({i,m-1});
           }
        }
          for(int i=0;i<m;i++){
           if(board[0][i]=='O'){
            vis[0][i]=1;
            q.push({0,i});
           }
           if(board[n-1][i]=='O'){
            vis[n-1][i]=1;
            q.push({n-1,i});
           }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=it.first+dir[i].first;
                int ncol=it.second+dir[i].second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]) board[i][j]='X';
            }
        }
    }
};