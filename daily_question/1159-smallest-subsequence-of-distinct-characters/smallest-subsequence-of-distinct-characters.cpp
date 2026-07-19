class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(27,0);
        vector<bool>seen(27,0);
        string res="";
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:s){
            freq[c-'a']--;
            if(seen[c-'a']) continue;
            while(!res.empty() && res.back()>c && freq[res.back()-'a']>0){
                seen[res.back()-'a']=false;
                res.pop_back();
            }
            res+=c;
            seen[c-'a'] = true;
        }
        return res;
    }
};