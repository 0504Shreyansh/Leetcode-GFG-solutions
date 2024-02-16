class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> freq;
        for (auto &x : arr)
            freq[x]++;
        priority_queue<int> pq;
        for (auto &x : freq)
            pq.push(-x.second);
        while (!pq.empty() && k >= -pq.top()) {
            k += pq.top();
            pq.pop();
        }
        return pq.size();
    }
};