class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        unordered_map<int,vector<string>> mp;
        for(auto i:nums)
            mp[i.size()].push_back(i);
        
        for(auto i:mp)
            sort(i.second.begin(),i.second.end());
        
        priority_queue<pair<int,vector<string>>> pq;
        for(auto i:mp) {
            sort(i.second.begin(),i.second.end());
            pq.push({i.first,i.second});
        }
        
        while(k>0) {
            if(pq.top().second.size() < k) {
                k -= pq.top().second.size();
                pq.pop();
            }else break;
        }
        vector<string> v = pq.top().second;
        while(--k) {
            cout<<v.back()<<endl;
            v.pop_back();
        }
        return v.back();
    }
};