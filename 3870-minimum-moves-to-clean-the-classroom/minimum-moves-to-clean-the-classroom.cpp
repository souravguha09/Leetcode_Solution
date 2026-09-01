
class Solution {
    vector<pair<int,int>> dir = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int si = -1, sj = -1;
        int cnt = 0;


        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int totalMask = (1 << cnt) - 1;

        vector<vector<vector<int>>> best(
            n,
            vector<vector<int>>(m, vector<int>(1 << cnt, -1))
        );

      
        queue<array<int, 4>> q;

        q.push({si, sj, energy, 0});
        best[si][sj][0] = energy;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [i, j, en, mask] = q.front();
                q.pop();

                if (mask == totalMask)
                    return steps;

                for (auto [di, dj] : dir) {
                    int ni = i + di;
                    int nj = j + dj;

                    if (ni < 0 || ni >= n ||
                        nj < 0 || nj >= m)
                        continue;

                    if (classroom[ni][nj] == 'X')
                        continue;

                    if (en == 0)
                        continue;

                    int newEnergy = en - 1;
                    int newMask = mask;

                    if (classroom[ni][nj] == 'L') {
                        newMask |= (1 << id[ni][nj]);
                    }

                    if (classroom[ni][nj] == 'R') {
                        newEnergy = energy;
                    }

                    if (newEnergy <= best[ni][nj][newMask])
                        continue;

                    best[ni][nj][newMask] = newEnergy;

                    q.push({
                        ni,
                        nj,
                        newEnergy,
                        newMask
                    });
                }
            }

            steps++;
        }

        return -1;
    }
};

