class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();
        priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long,int>>> busy;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> idel;
        for (int i = 0; i < m; i++)
            idel.emplace(servers[i], i);
        long long ts = 0;
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto& [t, idx] = busy.top();
                idel.emplace(servers[idx], idx);
                busy.pop();
            }
        };
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ts = max(ts,(long long) i);
            release();
            if (idel.empty()) {
                ts = busy.top().first;
                release();
            }
            auto& [w, idx] = idel.top();
            ans.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idel.pop();
        }

        return ans;
    }
};