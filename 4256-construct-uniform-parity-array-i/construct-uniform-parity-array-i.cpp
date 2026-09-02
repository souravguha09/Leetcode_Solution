class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0,even=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] & 1) odd++;
            else even++;
        }
        if(!even || !odd) return true;
        int diff=abs(odd-even);
        if(diff & 1 && (odd & 1==0)) return false;
        else return true;
    }
};