class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        // T --> F
        int i = 0, j = 0;
        int curr1 = 0;
        int n = answerKey.size();
        deque<int> dq;
        for(int j = 0; j < n; ++j) {
            if(answerKey[j] == 'F') {
                if(dq.size() < k) {
                    dq.push_back(j);
                }
                else {
                    while(dq.size() == k && i <= j) {
                        if(dq.front() == i) {
                            dq.pop_front();
                        }
                        i++;
                    }
                    dq.push_back(j);
                }
            }
            curr1 = max(curr1, j - i + 1);
        }


        // F --> T
        int i2 = 0, j2 = 0;
        deque<int> dq2;
        int curr2 = 0;
        for(int j2 = 0; j2 < n; ++j2) {
            if(answerKey[j2] == 'T') {
                if(dq2.size() < k) {
                    dq2.push_back(j2);
                }
                else {
                    while(dq2.size() == k && i2 <= j2) {
                        if(dq2.front() == i2) {
                            dq2.pop_front();
                        }
                        i2++;
                    }
                    dq2.push_back(j2);
                }
            }
            curr2 = max(curr2, j2 - i2 + 1);
        }

        // cout << curr1 << ' ' << curr2 << endl;
        int ans = max(curr1, curr2);
        return ans;
    }
};