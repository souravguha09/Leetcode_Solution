class Solution {
public:
    using ll = long long;

    struct Node {
        ll cnt;   
        ll wav;   
    };

    string s;
    Node dp[17][11][11][2][2];
    bool vis[17][11][11][2][2];

    Node dfs(int pos, int prev2, int prev1, bool started, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started][0]) {
            return dp[pos][prev2][prev1][started][0];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else if (!started) {
                Node nxt = dfs(pos + 1, 10, d, true, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                int add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node nxt = dfs(pos + 1, prev1, d, true, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started][0] = true;
            dp[pos][prev2][prev1][started][0] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};