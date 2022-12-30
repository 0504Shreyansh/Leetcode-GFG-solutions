class Allocator {
public:
    // map<int,int> mp;
    // map<int,int> freee;
    // int count = 0, currSize = 0;
    // int arr[];
    vector<int> v;
    int maxSize = 0;
    
    Allocator(int n) {
        v.resize(1001,0);
        maxSize = n;
    }
    
    int allocate(int size, int mID) {
        for(int i=0;i<maxSize;i++) {
            if(v[i]==0) {
                int len = 0, j = i;
                while(v[i]==0 && len<size && i<maxSize) {
                    i++; len++;
                }
                if(size==len) {
                    for(int k=j;k<i;k++) {
                        v[k] = mID;
                    }
                    return j;
                }
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for(int i=0;i<maxSize;i++) {
            if(v[i]==mID) {
                v[i] = 0;
                cnt++;
            }
        }
        // for(auto i:v) cout<<i<<" "; cout<<endl;

        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */