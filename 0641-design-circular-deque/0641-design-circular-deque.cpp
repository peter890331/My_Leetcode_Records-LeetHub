class MyCircularDeque {
public:
    vector<int> mydeque;
    int head, tail, size, max;

    MyCircularDeque(int k) {
        mydeque = vector<int>(k, -1);
        head = 0;
        tail = 0;
        size = 0;
        max = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        if (head == 0){
            head = max-1;
        }
        else {
            head--;
        }
        mydeque[head] = value;
        size++;
        return true;
        
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;

        mydeque[tail] = value;
        if (tail == max-1){
            tail = 0;
        }
        else {
            tail++;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        mydeque[head] = -1;
        if (head == max-1){
            head = 0;
        }
        else {
            head++;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        if (tail == 0){
            tail = max-1;
        }
        else {
            tail--;
        }
        mydeque[tail] = -1;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return mydeque[head];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        if (tail == 0) {
            return mydeque[max-1];
        }
        else {
            return mydeque[tail-1];
        }
        
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == max);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

 // Reference from Rarma's solution.
 // Reference from 雙端佇列 Deque - Rust Algorithm Club, https://rust-algo.club/collections/deque/.

 // initialize.
 //  h
 //  t 
 // [x, x, x, x, x, x, x] =>
 // -------------------------
 // insertFront.
 //                    h
 //  t 
 // [x, x, x, x, x, x, 1] =>
 // -------------------------
 // insertLast.
 //                    h
 //     t 
 // [1, x, x, x, x, x, 1] =>
 // -------------------------
 // insertFront.
 //                 h
 //     t 
 // [1, x, x, x, x, 1, 1] =>
 // -------------------------
 // insertLast.
 //                 h
 //        t 
 // [1, 1, x, x, x, 1, 1] =>
 // -------------------------
 // deleteFront.
 //                    h
 //        t 
 // [1, 1, x, x, x, x, 1] =>
 // -------------------------
 // deleteLast.
 //                    h
 //     t 
 // [1, x, x, x, x, x, 1] =>
 // -------------------------