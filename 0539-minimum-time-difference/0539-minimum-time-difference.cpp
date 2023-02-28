class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> time;
        for(auto t: timePoints) {
            string h = t.substr(0, 2), m = t.substr(3, 2);
            time.push_back(stoi(h)*60+stoi(m));
            time.push_back(stoi(h)*60+stoi(m)-1440);
        }
        
        int ans = 1440;
        sort(time.begin(), time.end());
        for(int i = 1; i < time.size(); i++) 
            ans = min(ans, time[i]-time[i-1]);    
        return ans;
    }
};