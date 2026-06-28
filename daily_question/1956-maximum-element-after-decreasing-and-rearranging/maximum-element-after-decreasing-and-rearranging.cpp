class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int max_ele=1;
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])<=1) max_ele=max(max_ele,arr[i]);
            else {
                max_ele=max(max_ele,arr[i-1]+1);
                arr[i]=arr[i-1]+1;
        }
        }
        return max_ele;
    }
};