class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        long long num=0;
        while(n>0){
            int x=n%10;
            if(x!=0){
               num*=10;
               num+=x;
               sum+=x;
            }
            n/=10;
        }
        long long num2=0;
        while(num>0){
            int x=num%10;
            num2*=10;
            num2+=x;
            num/=10;
        }
        return num2*sum;
    }
};