class Bitset {
public:
    string org, flipped;
    unordered_map<int,int> countOnes;
    bool isFlipped = false;
    Bitset(int size) {
        org.resize(size);
        fill(begin(org),end(org),'0');
        flipped.resize(size);
        fill(begin(flipped),end(flipped),'1');
    }
    
    void fix(int idx) {
        if(!isFlipped) {
            org[idx] = '1', flipped[idx] = '0';
            countOnes[idx] = 1;
        }
        else {
            flipped[idx] = '1', org[idx] = '0';
            countOnes.erase(idx);
        }
    }
    
    void unfix(int idx) {
        if(!isFlipped) {
            org[idx] = '0', flipped[idx] = '1';
            countOnes.erase(idx);
        }
        else {
            flipped[idx] = '0', org[idx] = '1';
            countOnes[idx] = 1;
        }
    }
    
    void flip() {
        isFlipped = !isFlipped;
    }
    
    bool all() {
        if(!isFlipped) 
            return countOnes.size()==org.size();
        return countOnes.size()==0;
    }
    
    bool one() {
        if(!isFlipped) 
            return countOnes.size() != 0;
        return countOnes.size() != org.size();
    }
    
    int count() {
        if(!isFlipped)
            return countOnes.size();
        return org.size() - countOnes.size();
    }
    
    string toString() {
        return (!isFlipped) ? org : flipped;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */