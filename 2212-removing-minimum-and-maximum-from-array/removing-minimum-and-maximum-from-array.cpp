class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto maxi=max_element(nums.begin(),nums.end());
        auto mini=min_element(nums.begin(),nums.end());
        int max_idx=distance(nums.begin(),maxi);
        int min_idx=distance(nums.begin(),mini);
        int n=nums.size();
        int both_front=0;
        int both_back=0;
        int front_back=0;
         if(max_idx<min_idx){
            swap(max_idx,min_idx);
         }
           both_front=max_idx+1;
           both_back=n-min_idx;
           front_back=min_idx+1+(n-max_idx);
        
        return min({front_back,both_front,both_back});
    }
};