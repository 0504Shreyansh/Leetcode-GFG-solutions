class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        // T --> F
        int n = answerKey.size();
        int i = 0;
        int ans = 0;
        deque<int> dq;
        for(int j = 0; j < n; ++j) {
            if(answerKey[j] == 'F') {
                while(dq.size() == k && i <= j) {
                    if(dq.front() == i) {
                        dq.pop_front();
                    }
                    i++;
                }
                dq.push_back(j);    
            }
            ans = max(ans, j - i + 1);
        }

        // F --> T
        i = 0;
        dq.clear();
        for(int j = 0; j < n; ++j) {
            if(answerKey[j] == 'T') {
                while(dq.size() == k && i <= j) {
                    if(dq.front() == i) {
                        dq.pop_front();
                    }
                    i++;
                }
                dq.push_back(j);
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};