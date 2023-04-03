class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        int n = s.size();
        // Suffix sum array
        for(int i = n-1; i > 0; i--)
            shifts[i-1] = (shifts[i-1] + shifts[i]) % 26;
        
        // Simply shift the letters and take use of %.
        for(int i = 0; i < n; i++) 
            s[i] = ((s[i]-'a') + (shifts[i])%26)%26 + 'a';
        
        return s;
    }
};