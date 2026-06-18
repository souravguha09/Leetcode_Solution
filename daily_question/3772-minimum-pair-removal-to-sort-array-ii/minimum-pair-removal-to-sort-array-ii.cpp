class Solution {
public:
    struct Node {
        long long sum;
        int i;
        bool operator>(const Node& other) const {
            if (sum == other.sum) return i > other.i;
            return sum > other.sum;
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<long long> val(nums.begin(), nums.end());
        vector<int> prv(n), nxt(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prv[i] = i - 1;
            nxt[i] = (i + 1 < n ? i + 1 : -1);
        }

        int bad = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (val[i] > val[i + 1]) bad++;
        }

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        for (int i = 0; i + 1 < n; i++) {
            pq.push({val[i] + val[i + 1], i});
        }

        int ans = 0;

        while (bad > 0) {
            Node cur;

            while (true) {
                cur = pq.top();
                pq.pop();

                int i = cur.i;
                int j = nxt[i];

                if (i != -1 && j != -1 &&
                    alive[i] && alive[j] &&
                    cur.sum == val[i] + val[j])
                    break;
            }

            int i = cur.i;
            int j = nxt[i];

            int L = prv[i];
            int R = nxt[j];

            if (L != -1 && val[L] > val[i]) bad--;
            if (j != -1 && val[i] > val[j]) bad--;
            if (R != -1 && val[j] > val[R]) bad--;

            val[i] += val[j];
            alive[j] = false;

            nxt[i] = R;
            if (R != -1) prv[R] = i;

            if (L != -1 && val[L] > val[i]) bad++;
            if (R != -1 && val[i] > val[R]) bad++;

            if (L != -1)
                pq.push({val[L] + val[i], L});

            if (R != -1)
                pq.push({val[i] + val[R], i});

            ans++;
        }

        return ans;
    }
};