class Solution {
public:
    void rotate(vector<vector<int>>&grid,int l,int r,int n){
        while(l<r){
            int r1=l/n,c1=l%n;
            int r2=r/n,c2=r%n;
            swap(grid[r1][c1],grid[r2][c2]);
            l++;
            r--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        k%=m*n;
        if(k==0) return grid;
        rotate(grid,0,m*n-1,n);
        rotate(grid,0,k-1,n);
        rotate(grid,k,m*n-1,n);
        return grid;
    }
};