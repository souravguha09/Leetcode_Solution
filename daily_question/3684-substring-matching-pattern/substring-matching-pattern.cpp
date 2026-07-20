class Solution {
public:
    bool hasMatch(string s, string p) {
       int idx=p.find('*');
       string a=p.substr(0,idx);
        int left=s.find(a);
        if(left==string::npos) return false;
        string b=p.substr(idx+1); 

        int right=s.find(b,left+a.size());
        return right!=string::npos;
    }
};