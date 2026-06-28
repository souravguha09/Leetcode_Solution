class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int>freq(26,0);
        for(char c: r){
            freq[c-'a']++;
        }
        for(char c: m){
            if(freq[c-'a']!=0) freq[c-'a']--;
        }
       for(int i=0;i<26;i++){
        if(freq[i]!=0) return false;
       }
       return true;
    }
};