class Solution {
public:
    int longestBalanced(string s) {
        int maxstr=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int maxfreq=0;
            int uni=0;
            for(int j=i;j<n;j++){
                int x=s[j]-'a';
                if(freq[x]==0) uni++;
                freq[x]++;
                if(freq[x]>maxfreq) maxfreq=freq[x];
            
            if(uni*maxfreq==(j-i+1)) maxstr=max(maxstr,j-i+1);
            }
        }
        return maxstr;
    }
};