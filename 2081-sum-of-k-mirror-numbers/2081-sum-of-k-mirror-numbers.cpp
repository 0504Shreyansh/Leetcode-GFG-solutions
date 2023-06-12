class Solution {
public:
    pair<bool, long long> check(string &s, int &k) {
        long long num = 0, factor = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            num += (s[i] - '0') * factor;
            factor *= k;
        }
        long long tmp = num;
        long long revNum = 0;
        
        // Check for base-10 palindrome
        while(tmp) {
            revNum = (10 * revNum) + tmp % 10;
            tmp /= 10;
        }
        return make_pair((num == revNum), num);
    }
    
    string generateCurrPalindrome(string& cur, int &lengthWanted) {
        string s(cur), r(cur);
        if(lengthWanted & 1) s.pop_back();
        reverse(begin(r),end(r));
        s += r;
        return s;
    }

    void generatePalindromes(string& cur, int &k, int &n, int &lengthWanted, long long &ans) {

        // all n numbers have been taken
        if(n == 0) {     
            return ;
        }

        // not valid case
        if(cur.size() > 0 && cur[0] == '0') {
            return ;
        }

        // build the palindrome number of the base-k 
        // when half is alredy built
        if(cur.size() * 2 >= lengthWanted) {
            string s = generateCurrPalindrome(cur, lengthWanted);
            pair<bool, long long> currCondition = check(s, k);
            if(currCondition.first) {
                n--;
                ans += currCondition.second;
            }
            return ;
        }
        
        // build the number 
        for(char ch = '0'; ch <= '0' + (k - 1); ch++) {
            cur.push_back(ch);
            generatePalindromes(cur, k, n, lengthWanted, ans);
            cur.pop_back();
        }
    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        for(int len = 1; len <= 32 && n > 0; len++) {
            string cur = "";
            generatePalindromes(cur, k, n, len, ans);
        }
        return ans;
    }
};