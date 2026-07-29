class Solution {
    long long countPermutations(const vector<int>& counts) {
        long long res=1;
        int max_c=0;
        for (int c:counts) {
            if (c>max_c) max_c = c;
        }
        bool max_skipped=false;
        int sum=max_c; 
        for (int c:counts) {
            if (c==0) continue;
            if (c==max_c&&!max_skipped) {
                max_skipped=true;
                continue; 
            }
            for (int i=1;i<=c;i++) {
                res=res*(sum+1)/i; 
                sum++;
                if(res>1000000) return 1000001;
            }
        }
        return res;
    }
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c:s) {
            freq[c-'a']++;
        }
        vector<int> counts(26, 0);
        char mid=0;
        for (int i=0;i<26;i++) {
            if (freq[i]%2==1) {
                mid=i+'a';
            }
            counts[i] = freq[i] / 2;
        }
        if (countPermutations(counts) < k) {
            return "";
        }
        string half = "";
        int N = s.length() / 2;
        for (int pos = 0; pos < N; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (counts[i] == 0) continue;
                counts[i]--; 
                long long W = countPermutations(counts);
                if (W >= k) {
                    half += (char)(i + 'a');
                    break;
                } else {
                    k -= W;
                    counts[i]++;
                }
            }
        }
        string result = half;
        if (s.length() % 2 != 0) {
            result += mid;
        }
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        result += rev_half;
        return result;
    }
};