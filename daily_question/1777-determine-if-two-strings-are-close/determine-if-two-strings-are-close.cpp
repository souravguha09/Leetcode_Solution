class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        set<int>st;
        for(char c:word1){
            arr1[c-'a']++;
            st.insert(c-'a');
        }
        for(char c:word2){
            arr2[c-'a']++;
            if(!st.count(c-'a')) return false;
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<26;i++) {
            if(arr1[i]!=arr2[i]) return false;
        }
        return true;
    }
};