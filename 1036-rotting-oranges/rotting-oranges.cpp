class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        int min=-1;
        if(q.empty() && fresh==0) return 0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                for(auto &d:dir){
                    int dx=it.first+d.first;
                    int dy=it.second+d.second;
                    if(dx>=0 && dx<m &&dy>=0 &&dy<n){
                        if(grid[dx][dy]==1){
                            grid[dx][dy]=2;
                            fresh--;
                            q.push({dx,dy});
                        }
                    }
                }
            }
            min++;
        }
        if(fresh==0) return min;
        return -1;

    }
};