class Solution {
    int cheapest=INT_MAX;
    int t[1001][1501];
    int solve(int n,int budget,vector<vector<int>>&items,vector<int>&copies){
        if(n==0) return budget/cheapest;
        int take=0,skip=0,price=items[n-1][1];
        if(t[n][budget]!=-1) return t[n][budget];
        if(price<=budget){
            take=1+copies[n-1]+solve(n-1,budget-price,items,copies);
        }
           skip=solve(n-1,budget,items,copies);
           return t[n][budget]=max(take,skip);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>copies(n,0);
       
        for(int i=0;i<n;i++){
            int copy=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0]==0) copy++;
            }
            copies[i]=copy;
            cheapest=min(cheapest,items[i][1]);
        }
         memset(t,-1,sizeof(t));
        return solve(n,budget,items,copies);
    }
};