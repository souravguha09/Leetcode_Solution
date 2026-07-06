class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int end=points[0][1];
        int arrow=1;
        for(auto &it:points){
            if(it[0]>end) {
                arrow++;
                end=it[1];
            }else end=min(end,it[1]);
        }
        return arrow;
    }
};