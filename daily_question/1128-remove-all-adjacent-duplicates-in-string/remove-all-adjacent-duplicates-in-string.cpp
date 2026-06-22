class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
      for(char c:s){
       if(res=="") res.push_back(c);
       else  if(res.back()==c) res.pop_back();
        else res.push_back(c);
      }
      return res;
    }
};