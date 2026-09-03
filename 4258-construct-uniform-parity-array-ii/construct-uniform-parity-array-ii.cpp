class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
           int odd=0,mn=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] & 1) odd++;
            mn=min(mn,nums1[i]);
        }
       return mn % 2 || odd==0; 
    }
};