class ProductOfNumbers {
public:
    vector<int> arr;

    ProductOfNumbers() {
        arr.clear();
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for (int i = arr.size() - 1, cnt = 0; i >= 0 && cnt < k; i--, cnt++)
            ans *= arr[i];

        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */