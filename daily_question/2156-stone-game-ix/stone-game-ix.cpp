class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int rem0=0,rem1=0,rem2=0;
        for(int x:stones){
            if(x%3==0) rem0++;
            else if(x%3==1) rem1++;
            else rem2++;
        }
        if(rem0%2==0) return rem1>0 && rem2>0;
        else return abs(rem1-rem2)>2;
       
    }
};