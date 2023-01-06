class WordDictionary {
public:
    unordered_map<int,vector<string>> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        int n = word.size();
        for(auto &i : mp[word.size()]) {
            bool f = true;
            for(int j=0;j<n;j++) {
                if(word[j]=='.') continue;
                if(word[j]!=i[j]) {
                    f = false; break;
                }
            }
            if(f) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */