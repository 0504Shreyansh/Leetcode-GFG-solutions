class MagicDictionary {
public:
    unordered_map<string,int> map;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto str : dictionary)
            map[str]++;
    }
    
    bool search(string searchWord) {
        for(auto [str, cnt] : map) {
            if(str.size() == searchWord.size()) {
                int change = 0;
                for(int i = 0; i < str.size(); i++) {
                    if(str[i] != searchWord[i]) {
                        change++;
                    }
                }
                if(change == 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */