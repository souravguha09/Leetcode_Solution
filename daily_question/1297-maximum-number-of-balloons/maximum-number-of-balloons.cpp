class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        for(char c:text){
            freq[c-'a']++;
        }
        return min(freq[0],min(min(freq[1],freq[11]/2),min(freq[14]/2,freq[13])));
    }
};