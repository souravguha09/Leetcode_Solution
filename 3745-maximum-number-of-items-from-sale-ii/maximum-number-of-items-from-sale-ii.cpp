#define ll long long
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int cheapest=INT_MAX,maxfac=INT_MIN,n=items.size();
        for(int i=0;i<n;i++){
            maxfac=max(maxfac,items[i][0]);
            cheapest=min(cheapest,items[i][1]);
        }
        vector<int>freq(maxfac+1,0);
        for(int i=0;i<n;i++)
            freq[items[i][0]]++;
        for(int i=1;i<=maxfac;i++){
            if(freq[i]>0){
              for(int idx=2*i;idx<=maxfac;idx+=i)
              freq[i]+=freq[idx];
            }
        }
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            int cost=items[i][1];
            int count=freq[items[i][0]]-1;
            if(count>0 && 2*cheapest>=cost)
            mp[cost]+=count;
        }
        int total=0;
        for(auto & [cost,count]:mp){
            int include=min<ll>(budget/cost,count);
            budget-=include*cost;
            total+=include*2;
        }
        total+=budget/cheapest;
        return total;
    }
};