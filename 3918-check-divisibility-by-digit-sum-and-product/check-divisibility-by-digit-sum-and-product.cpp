class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        int dsum=0,dpro=1;
        while(x>0){
            dsum+=x%10;
            dpro*=x%10;
            x/=10;
        }
        return n % (dsum+dpro)==0;
    }
};