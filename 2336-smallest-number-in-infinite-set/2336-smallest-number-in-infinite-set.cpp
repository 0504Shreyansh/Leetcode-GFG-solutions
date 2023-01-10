class SmallestInfiniteSet {
public:
    vector<bool> vec;
    SmallestInfiniteSet() {
        vec.resize(1001);
        for(int i=0;i<vec.size();i++)
            vec[i] = true;
    }
    
    int popSmallest() {
        for(int i=1;i<vec.size();i++) {
            if(vec[i]) {
                vec[i] = false;
                return i;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        vec[num] = true;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */