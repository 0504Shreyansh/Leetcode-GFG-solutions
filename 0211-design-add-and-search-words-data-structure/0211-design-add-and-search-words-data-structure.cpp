class WordDictionary {
public:
    vector<vector<string>> store;
    WordDictionary() {
        store.resize(26);
    }
    
    void addWord(string word) {
        store[word.size()].push_back(word);
    }
    
    bool search(string word) {
        int n = word.size();
        for (int i = 0; i < store[n].size(); i++) {
            int diff = 0;
            for (int j = 0; j < n; j++) {
                if (word[j] == '.') continue;
                if (word[j] != store[n][i][j]) {
                    diff = 1; break;
                }
            }
            if (diff==0) return true;
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