class RandomizedSet {
private:
    set<int> store;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (store.find(val) != store.end()) {
            return false;
        }
        store.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (store.find(val) == store.end()) {
            return false;
        }
        store.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = store.begin();
        advance(it, rand() % (int)store.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */