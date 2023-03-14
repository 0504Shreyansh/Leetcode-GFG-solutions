class CombinationIterator {
public:
    string s;
    int k, pointer = 0;
    vector<string> combinations;
    void findCombinations(int i, string cur, int k) {
        if (k==0) 
        {
            combinations.push_back(cur);
            return ;
        }
        for (int j = i; j < s.size(); j++)
        {
            findCombinations(j+1, cur+s[j], k-1);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        k = combinationLength;
        findCombinations(0, "", k);
    }
    
    string next() {
        return combinations[pointer++];
    }
    
    bool hasNext() {
        return (pointer < combinations.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */