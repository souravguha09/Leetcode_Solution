class Solution {
public:
    bool canReach(string s, int minj, int maxj) {
        int n= s.length();
        if(s.back()&1) return false;
        s[0]='v';
        int reach=0,maxr=maxj;
        for(int i=minj;i<n;i++){
            if(i>maxr) return false;
             reach+=s[i-minj]=='v';
             reach-=(i>maxj) && s[i-maxj-1]=='v';
             if(reach && (~s[i] & 1 )){
                s[i]='v';
                maxr=maxj+i;
             }
        }
       return reach; 
    }
};