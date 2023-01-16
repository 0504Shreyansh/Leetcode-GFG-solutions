class Solution {
/*1. Insert the given interval and sort to obtain the desired position of the interval{s,e}.
  2. Move forward and keep checking for overlapping intervals
     (e>=nextInterval[0])
  3. Move backward and keep checking for overlapping intervals
     (s<=nextInterval[1])
  4. While u encounter another interval that needs to be merged, replace it with {-1,-1}.
  5. Update both s and e to min(s,interval[0]) and max(e,,interval[1]).
*/
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int in = find(intervals.begin(),intervals.end(),newInterval) - intervals.begin();
        int s = newInterval[0], e = newInterval[1];
        int j = in+1, i = in-1;
        //Forward check
        while(j<n) {
            if(e>=intervals[j][0]) {
                intervals[in][1] = max(intervals[in][1], intervals[j][1]);
                intervals[in][0] = min(intervals[in][0], intervals[j][0]);
                intervals[j][0]=intervals[j][1]=-1;
                j++; 
            }
            else break;
        }
        //Backward check
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
            //Take intervals other than {-1,-1}
            if(i[0]!=-1 && i[1]!=-1)
                ans.push_back(i);
        }
        return ans;
    }
};