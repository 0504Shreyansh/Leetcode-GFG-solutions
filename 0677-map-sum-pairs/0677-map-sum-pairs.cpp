class MapSum {
public:
    unordered_map<string,int> map;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        int res = 0;
        for (auto [str, cnt] : map) 
            if (prefix == str.substr(0, n))
                res += cnt;
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */