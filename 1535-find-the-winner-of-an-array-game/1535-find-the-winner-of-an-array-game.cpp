class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n) return *max_element(begin(arr), end(arr));
        if (k == 1) return max(arr[0], arr[1]);
        deque<int> q;
        for (int &x : arr) 
            q.push_back(x);
        int count = 0;
        while (1) {
            int top1 = q.front(); q.pop_front();
            int top2 = q.front(); q.pop_front();
            if (top1 > top2) {
                if (++count >= k) return top1;
                q.push_front(top1);
                q.push_back(top2);
            } else {
                count = 1;
                q.push_front(top2);
                q.push_back(top1);
            }
        }
        return -1;
    }
};