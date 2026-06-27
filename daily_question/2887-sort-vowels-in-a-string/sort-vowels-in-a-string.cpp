class Solution {
public:
    bool isvowel(char c){
        c=tolower(c);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char>vowel;
        for(char c:s){
            if(isvowel(c)) vowel.push_back(c);
        }
        sort(vowel.begin(),vowel.end());
        int n=s.length();
        string t="";
        
        int j=0;
        for(int i=0;i<n;i++){
            if(!isvowel(s[i])) t.push_back(s[i]);
            else t.push_back(vowel[j++]);
        }
        return t;
    }
};