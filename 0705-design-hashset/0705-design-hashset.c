// 定義一個 HashSet 結構體
typedef struct {
    bool *data;             // 使用動態陣列來模擬 HashSet
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));     // 動態分配一個 MyHashSet 結構體，並取得指標
    // if (!obj) return NULL;                                   // 確保記憶體分配成功，若失敗則返回 NULL
    obj->data = (bool*)calloc(1000001, sizeof(bool));           // 使用 calloc 分配 1000001 個 `bool` 空間，每個初始化為 `false`
    // if (!obj->data) {                                        // 如果記憶體分配失敗，釋放已分配的結構體，並返回 NULL
    //     free(obj);
    //     return NULL;
    // }
    return obj;                                                 // 返回指向 HashSet 的指標
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->data[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->data[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->data[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/