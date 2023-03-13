class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        
        while(q.size()) {
            int N = q.size();
            while (N--) {
                string cur = q.front();
                q.pop();
                if (cur==endWord)
                    return steps;
                for (int k = 0; k < cur.size(); k++) {
                    char original = cur[k];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        cur[k] = ch;
                        if(st.count(cur)) {
                            st.erase(cur);
                            q.push(cur);
                        }
                    }
                    cur[k] = original;
                }
            }
            steps++;
        }
        
        return 0;
    }
};