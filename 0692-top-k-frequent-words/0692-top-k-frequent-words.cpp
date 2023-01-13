class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //mp stores count of the strings
        unordered_map<string,int> mp;
        for(int i=words.size()-1;i>=0;i--) {
            mp[words[i]]++;
        }
        //mpp map stores -count so that most freq(-maxCount) is at the top as it will be the smallest
        //also lexicographic order needs to be maintained within same count strings
        map<int,priority_queue<string,vector<string>,greater<string>>> mpp;
        for(auto i:mp) {
            mpp[-i.second].push(i.first);
        }
        //push the pair{count,-index}
        //count first in order to keep the most freq at the top
        //-index bcoz the lowest -ve value and the most fre will be at the top
        vector<string> ans;
        for(auto i:mpp) {
            priority_queue<string,vector<string>,greater<string>> pq=i.second;
            while(pq.size() && k--) {
                ans.push_back(pq.top());
                pq.pop();
                if(k==0) 
                    return ans;
            }

        }
        

        return ans;
    }
};