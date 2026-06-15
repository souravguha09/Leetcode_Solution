class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int mod=1000000007;
        long long lcm= (a*b)/__gcd(a,b);
        long long left=min(a,b),right=n*1LL*min(a,b);
        long long ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long pre=mid/a+mid/b-mid/lcm;
            if(pre<n) left=mid+1;
            else{
                ans=mid%mod;
                right=mid-1;
            }
        }
        return (int)ans;
    }
};