class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        // for(auto i:points) cout<<i[0]<<' '<<i[1]<<endl; 
        int last = points[0][1];
        int ans = 1;
        for(auto &i: points){
            if(i[0] > last){
                ans++;
                last = i[1];
            }
            last = min(last, i[1]);
            // cout<<last<<' ';
        }
        return ans;
    }
};