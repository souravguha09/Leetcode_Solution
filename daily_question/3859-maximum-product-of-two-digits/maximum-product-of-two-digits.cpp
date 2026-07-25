class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int maxi=-1,smx=-1;
        for(char c:s){
            if(c-'0'>=maxi){
                smx=maxi;
                maxi=c-'0';
            }else if(smx<c-'0' && c-'0'<maxi) smx=c-'0';
        }
     return maxi*smx;
    }
};