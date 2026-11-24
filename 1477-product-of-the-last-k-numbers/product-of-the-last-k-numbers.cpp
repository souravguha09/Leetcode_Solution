class ProductOfNumbers {
          vector<int>arr;
public:
    ProductOfNumbers() {
  
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        int n=arr.size();
        for(int i=n-1;i>=n-k;i--) prod*=arr[i];
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */