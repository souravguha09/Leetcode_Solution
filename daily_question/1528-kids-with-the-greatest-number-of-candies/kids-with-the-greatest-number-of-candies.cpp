class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& cand, int ex) {
        int n=cand.size();
        int maxi=cand[0];
        for(int i=0;i<n;i++) maxi=max(maxi,cand[i]);
        vector<bool>ans(n);
        for(int i=0;i<n;i++){
            if(cand[i]+ex>=maxi) ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};