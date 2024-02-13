class Solution {
private:
    bool isPalindrome(string word) {
        int i = 0, j = word.size() - 1;
        while (i < j) {
            if (word[i] != word[j]) return false;
            i++, j--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (string &word: words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};