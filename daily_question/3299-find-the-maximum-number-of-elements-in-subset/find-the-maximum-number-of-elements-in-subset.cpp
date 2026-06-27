class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        int ans=1;
        if(mp.count(1)){
            int x= mp[1];
            ans=max(ans, x % 2 ? x : x-1);
        }
        for(auto &[num,f]: mp){
            if(num==1) continue;
            int len=0;
            long long x=num;
            while(mp.count(x) && mp[x]>=2){
                len+=2;
                if(x>INT_MAX) break;
                x*=x;
            }
            if(mp.count(x)) len++;
            else len--;
            ans=max(ans,len);
        }
        return ans;
    }
};