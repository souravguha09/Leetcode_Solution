class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asd) {
        sort(asd.begin(),asd.end());
        int n=asd.size();
        long long ma=mass;
        for(int i=0;i<n;i++){
           if(ma>=asd[i]){
            ma+=asd[i];
           }else
           return false;
        }
        return true;
    }
};