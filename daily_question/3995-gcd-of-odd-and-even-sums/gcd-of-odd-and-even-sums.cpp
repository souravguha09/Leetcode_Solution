class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;
        for(int i=1;i<=2*n-1;i+=2){
            sumodd+=i;
            sumeven+=i+1;
        }
        return gcd(sumodd,sumeven);
    }
};