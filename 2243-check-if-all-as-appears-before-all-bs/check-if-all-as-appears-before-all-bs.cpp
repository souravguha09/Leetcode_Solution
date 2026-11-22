class Solution {
public:
    bool checkString(string s) {
        bool flag=true;
        for(char c:s){
           if(c=='b') flag = false;
           if(!flag && c=='a') return false;
        }
        return true;
    }
};