class NumberContainers {
public:
    unordered_map<int,int> store;
    map<int,set<int>> inds;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = store.find(index);
        if(it != store.end())
            inds[it->second].erase(index);
        store[index] = number;
        inds[number].insert(index);
    }
    
    int find(int number) {
        return (inds[number].size()==0) ? -1 : *inds[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */