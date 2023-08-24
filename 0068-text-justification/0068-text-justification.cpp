class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i = 0;
        while (i < n) {
            int j = i + 1;
            int lettersCount = words[i].size();
            int spaces = 0;
            while (j < n && lettersCount + words[j].size() + spaces + 1 <= maxWidth) {
                lettersCount += words[j].size();
                spaces++;
                j++;
            }
            int leftSpaces = maxWidth - lettersCount;
            int commonSpace = (spaces == 0) ? 0 : leftSpaces / spaces;
            int extraSpace = (spaces == 0) ? 0 : leftSpaces % spaces;
            if (j == n) {
                commonSpace = 1;
                extraSpace = 0;
            }
            // cout << "I -> " << i << endl;
            // cout << "J -> " << j << endl;
            // cout << "lettersCount -> " << lettersCount << endl;
            // cout << "spaces -> " << spaces << endl;
            // cout << "leftSpaces -> " << leftSpaces << endl;
            // cout << "commonSpace -> " << commonSpace << endl;
            // cout << "extraSpace -> " << extraSpace << endl;
            string res;
            for (int k = i; k < j; k++) {
                res += words[k];
                int curSpace = commonSpace;
                if (extraSpace) {
                    curSpace++;
                    extraSpace--;
                }
                while (k != j - 1 && curSpace--) res += ' ';
            }
            while (res.size() < maxWidth) {
                res += ' '; 
            }
            ans.push_back(res);
            i = j;
        }
        return ans;
    }
};