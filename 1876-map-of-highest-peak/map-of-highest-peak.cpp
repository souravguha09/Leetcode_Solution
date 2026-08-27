class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1) {
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(q.size()>0){
          auto [r,c]=q.front();
          q.pop();
          if(r-1>=0 && ans[r-1][c]==-1){
            ans[r-1][c]=ans[r][c]+1;
            q.push({r-1,c});
            }
          if(r+1<m && ans[r+1][c]==-1) {
            ans[r+1][c]=ans[r][c]+1;
            q.push({r+1,c});
            }
            if(c-1>=0 && ans[r][c-1]==-1) {
            ans[r][c-1]=ans[r][c]+1;
            q.push({r,c-1});
            }
            if(c+1<n && ans[r][c+1]==-1) {
            ans[r][c+1]=ans[r][c]+1;
            q.push({r,c+1});
            }
        }
        return ans;
    }
};