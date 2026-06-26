class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        string ans="";
        int i=0,j=0;
        while(i<n1 && j<n2){
            ans.push_back(s1[i++]);
            ans.push_back(s2[j++]);
        }
       while(i<n1) ans.push_back(s1[i++]);
       while(j<n2) ans.push_back(s2[j++]);
       return ans;
    }
};