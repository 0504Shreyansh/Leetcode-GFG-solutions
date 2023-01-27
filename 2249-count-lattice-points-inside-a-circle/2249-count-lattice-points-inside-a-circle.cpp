class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        
        set<pair<int,int>> st;
        for(auto k:circles) {
            int x = k[0], y = k[1], r = k[2];
            for(int i=x-r;i<=x+r;i++) {
                for(int j=y-r;j<=y+r;j++) {
                    //Condition of a point lying inside the circle
                    if((i-x)*(i-x)+(j-y)*(j-y) <= r*r) 
                        st.insert({i, j});
                }
            }
        }
        return st.size();
    }
};