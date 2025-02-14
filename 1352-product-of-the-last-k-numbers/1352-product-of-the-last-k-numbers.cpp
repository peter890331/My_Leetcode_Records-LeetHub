class ProductOfNumbers {
private:
    vector<int> nums;
public:
    ProductOfNumbers() {

    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        int ans = 1;
        while (k){
            ans *= nums[n-k];
            k--;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */