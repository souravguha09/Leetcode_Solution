class Solution {
public:
    string removeStars(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                s.erase(i-1,2);
                i-=2;
             }
        }
        return s;
    }
};