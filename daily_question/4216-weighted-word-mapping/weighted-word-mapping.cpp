class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string word="";
        for(auto &s:words){
            int val=0;
           for(int i=0;i<s.length();i++)
           val+=weights[s[i]-'a'];
          int q= val%26;
           word+=(char)('z'-q);
        }
        return word;
    }
};