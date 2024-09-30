class CustomStack {
public:
    vector<int> mystack;
    int size, max;

    CustomStack(int maxSize) {
        mystack = vector<int>(maxSize, -1);
        size = 0;
        max = maxSize;
    }
    
    void push(int x) {
        if (size < max){
            mystack[size] = x;
            size++;
        }
    }
    
    int pop() {
        if (size == 0) return -1;
        int temp = mystack[size - 1];
        mystack.pop_back();
        size--;
        return temp;
    }
    
    void increment(int k, int val) {
        int temp = min(k, size);
        for (int i=0; i<temp; i++){
            mystack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */