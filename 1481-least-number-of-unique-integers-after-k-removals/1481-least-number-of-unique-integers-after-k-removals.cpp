class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        map<int,int> mp;
        for(auto i:arr)
            mp[i]++;
        //greedily create minHeap so that minCount is at the top
        priority_queue<int> pq;
        for(auto i:mp)
            pq.push(-i.second);
        while(pq.size()) {
            if(k >= -pq.top()) {
                k += pq.top();
                pq.pop();
            }
            else break;
        }
        
        return pq.size();
    }
};