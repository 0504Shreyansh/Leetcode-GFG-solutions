class SnapshotArray {
public:
    int snap_count = 0;
    unordered_map<int, map<int,int>> snaps;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        snaps[index][snap_count] = val;
    }
    
    int snap() {
        return snap_count++;
    }
    
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id);
        return it == begin(snaps[index]) ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */