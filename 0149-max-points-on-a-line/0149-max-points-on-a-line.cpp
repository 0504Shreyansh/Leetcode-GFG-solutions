class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 0, n = points.size();
        if(n==1) 
            return 1;
        for(int i=0;i<n-1;i++) {
            long x1 = points[i][0], y1 = points[i][1];
            
            for(int j=i+1;j<n;j++) {
                
                int curr = 0;
                long x2 = points[j][0], y2 = points[j][1];
                int a = y2-y1, b = x2-x1;
                long eq = (x1*(y2-y1) - y1*(x2-x1));
                
                for(int k=0;k<n;k++) {
                    int x = points[k][0], y = points[k][1];
                    if(a*x - b*y == eq) {
                        cout<<a<<' '<<b<<' '<<x<<' '<<y<<endl;
                        curr++;
                    }
                }
                cout << endl;
                ans = max(ans,curr);
            }
        }cout << endl;
        return ans;
    }
};