class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size() ;  
        vector<vector<int>>rows ; 
        vector<vector<int>>column ; 
        for(int i=0;i<n;i++){
            vector<int>arr ;
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]) ; 
            }
            rows.push_back(arr); 
        }
        for(int j=0;j<n;j++){
            vector<int>arr ;
            for(int i=0;i<n;i++){
                arr.push_back(grid[i][j]) ; 
            }
            column.push_back(arr); 
        }
        map<vector<int>,int>freq1 ;
        for(auto & it: rows){
            freq1[it]++; 
        } 
        map<vector<int>,int>freq2 ; 
        for(auto & it: column){
            freq2[it]++; 
        } 
        int cnt = 0  ;
        for(auto& it:freq1){
            if(freq2[it.first]>0){
                cnt+= freq2[it.first]*freq1[it.first];  
            }
        }
        return cnt ; 
    }
};