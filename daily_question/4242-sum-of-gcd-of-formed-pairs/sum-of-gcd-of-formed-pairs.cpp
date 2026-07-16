class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefgcd(n);
        int mx=INT_MIN;
        for(int i=0;i<n;i++) {
            mx=max(mx,nums[i]);
            prefgcd[i]=__gcd(mx,nums[i]);
        }
        sort(prefgcd.begin(),prefgcd.end());
        long long sum=0;
        for(int i=0;i<n/2;i++) sum+=__gcd(prefgcd[i],prefgcd[n-1-i]);
        return sum;
    }
};