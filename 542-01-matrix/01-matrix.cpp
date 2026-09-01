class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        vector<pair<int,int>> dir = {
            {-1,0}, {0,-1}, {1,0}, {0,1}
        };


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i,j}, 0});
                }
            }
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int step = it.second;

            for(int i = 0; i < 4; i++) {
                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = step + 1;

                    q.push({{nrow,ncol}, step + 1});
                }
            }
        }

        return dist;
    }
};