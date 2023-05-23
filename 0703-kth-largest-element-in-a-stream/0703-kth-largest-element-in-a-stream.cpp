class KthLargest {
public:
    multiset<int> MS;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto it : nums) {
            MS.insert(it);
            if(MS.size() > k) 
                MS.erase(MS.begin());
        }
    }
    
    int add(int val) {
        MS.insert(val);
        if(MS.size() > K) MS.erase(MS.begin());  // removes only one occ
        return *MS.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */