class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int in = find(intervals.begin(),intervals.end(),newInterval) - intervals.begin();
        int s = newInterval[0], e = newInterval[1];
        int j = in+1, i = in-1;
        while(j<n) {
            if(e>=intervals[j][0]) {
                intervals[in][1] = max(intervals[in][1], intervals[j][1]);
                intervals[in][0] = min(intervals[in][0], intervals[j][0]);
                intervals[j][0]=intervals[j][1]=-1;
                j++; 
            }
            else break;
        }
        while(i>=0) {
            if(s<=intervals[i][1]) {
                intervals[in][0] = min(intervals[in][0], intervals[i][0]);
                intervals[in][1] = max(intervals[in][1], intervals[i][1]);
                intervals[i][0]=intervals[i][1]=-1;
                i--; 
            }
            else break;
        }
        vector<vector<int>> ans;
        for(auto i:intervals) {
            if(i[0]!=-1 && i[1]!=-1)
                ans.push_back(i);
        }
        return ans;
    }
};