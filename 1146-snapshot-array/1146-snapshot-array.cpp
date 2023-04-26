class SnapshotArray {
public:
    int snapCount = 0;
    unordered_map<int,map<int,int>> data;
    
    SnapshotArray(int length) {
    
    }
    
    void set(int index, int val) {
        data[index][snapCount] = val;
    }
    
    int snap() {
        return snapCount++;
    }
    
    int get(int index, int snap_id) {
        auto it = data[index].upper_bound(snap_id);
        return it == begin(data[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */