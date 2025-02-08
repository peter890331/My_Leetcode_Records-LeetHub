class NumberContainers {
public:
    unordered_map<int, int> indexandnumber;
    unordered_map<int, set<int>> numberandindex;

    NumberContainers() {  
    }
    
    void change(int index, int number) {
        if (!indexandnumber[index]){
            indexandnumber[index] = number;
            numberandindex[number].insert(index);
        }
        else {
            int temp = indexandnumber[index];
            numberandindex[temp].erase(index);
            if (numberandindex[temp].empty()){
                numberandindex.erase(temp);
            }
            indexandnumber[index] = number;
            numberandindex[number].insert(index);
        }
    }
    
    int find(int number) {
        if (!numberandindex[number].empty()){
            return *numberandindex[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */