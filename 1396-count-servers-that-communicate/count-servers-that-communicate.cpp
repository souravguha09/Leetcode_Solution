
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {

                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;

                    int sz = 0;

                    while(!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        sz++;
                        for(int x = 0; x < m; x++) {
                            if(grid[x][c] == 1 && !vis[x][c]) {
                                vis[x][c] = 1;
                                q.push({x, c});
                            }
                        }

                        for(int y = 0; y < n; y++) {
                            if(grid[r][y] == 1 && !vis[r][y]) {
                                vis[r][y] = 1;
                                q.push({r, y});
                            }
                        }
                    }

                    if(sz > 1) {
                        cnt += sz;
                    }
                }
            }
        }

        return cnt;
    }
};
