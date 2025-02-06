class MyHashSet {
private:
    vector<bool> myhashset;                 // 在類別內宣告 myhashset。
public:
    MyHashSet() {
        myhashset.resize(1000001, false);   // 然後在構造函數內初始化。
    }
    
    void add(int key) {
        myhashset[key] = true;
    }
    
    void remove(int key) {
        myhashset[key] = false;
    }
    
    bool contains(int key) {
        return myhashset[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

 // Reference from Akbar's solution.