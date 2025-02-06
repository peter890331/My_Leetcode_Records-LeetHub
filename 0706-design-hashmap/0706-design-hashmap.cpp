class MyHashMap {
private:
    vector<int> myhashmap;                 // 在類別內宣告 myhashmap
public:
    MyHashMap() {
        myhashmap.resize(1000001, -1);     // 然後在構造函數內初始化。
    }
    
    void put(int key, int value) {
        myhashmap[key] = value;
    }
    
    int get(int key) {
        return myhashmap[key];
    }
    
    void remove(int key) {
        myhashmap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */