class MyHashSet {
public:
    vector<int> found;
    MyHashSet() {
        found.resize(1000001);
    }
    
    void add(int key) {
        found[key] = 1;
    }
    
    void remove(int key) {
        found[key] = 0;
    }
    
    bool contains(int key) {
        return found[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */