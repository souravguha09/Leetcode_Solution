class Solution {
public:
    bool canPlaceFlowers(vector<int>& flo, int n) {
    int k=n;
        for(int i=0;i<flo.size();i++){
          if(flo[i]==1)
          i++;
          else
          {
           if ((i != flo.size() - 1 && flo[i + 1] == 0) ||
    (i == flo.size() - 1 && flo[i] == 0))
 {
                k--;
                flo[i]=1;
          i++;
            }
          }
        }
        if(k<=0) return true;
        else
        return false;
    }
};