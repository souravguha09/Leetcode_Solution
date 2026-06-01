class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int sum=0;
        int cnt=0;
        int n=cost.size();
        for(int i=0;i<cost.size();i++){
            cnt++;
            if(cnt<=2)
            sum+=cost[n-1-i];
           else
           cnt=0;
        }
        return sum;
    }
};