class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(string &w:patterns){
            if(word.find(w)!=string::npos) cnt++;
        }
        return cnt;
    }
};