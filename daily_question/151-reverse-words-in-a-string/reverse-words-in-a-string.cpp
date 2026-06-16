class Solution {
public:
    string reverseWords(string s) {
       string res="";
       stack<string>st;
       string s1="";
       for(char c:s){
        if(c==' ' && s1.empty()) continue;
        if(c==' ' && !s1.empty()){
            st.push(s1);
            s1="";
       }if(c!=' ')
       s1+=c;
       }
       if(!s1.empty())
       st.push(s1);
       while(!st.empty()){
         string m=st.top();
         st.pop();
         res+=m;
         res+=' ';
       }
       res.pop_back();
       return res;
    }
};