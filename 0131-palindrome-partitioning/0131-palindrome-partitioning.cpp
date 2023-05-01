class Solution {
public:
    // Function to check if a string is palindrome
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void solve(int cur, int prev, string &s, vector<string>& parts, vector<vector<string>>& ans) {

        if(cur==s.size()) {
            // Check for the last substring if it is a palindrome
            string newString = s.substr(prev, cur-prev);
            if(newString.size() && isPalindrome(newString)) {
                parts.push_back(newString);
                ans.push_back(parts);
                parts.pop_back();
            }
            return ;
        }

        // No partition done
        solve(cur+1, prev, s, parts, ans);
        string newString = s.substr(prev, cur-prev);
        // Check if a string is a palindrome or not
        // Partition only if it is a palindrome
        if(newString.size() && isPalindrome(newString)) {
            parts.push_back(newString);
            solve(cur+1, cur, s, parts, ans);
            parts.pop_back();
        }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        solve(0, 0, s, parts, ans);
        return ans;
    }
};