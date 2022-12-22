class Solution {
public:
    /*Concept -> Sabse kam plantTime wale ko last mei lo, store {g,p}
    {(2,3),(2,1),(1,2),(1,2)}
    1. time-> 3+2-> 5
    2. time-> (3)+1+2-> 6
    3. time-> (3+1+2)+1-> 7
    4. time-> (3+1+2+2)+1->9
    */
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>> vp;
        int n = plantTime.size();
        
        for(int i=0;i<n;i++)             
            vp.push_back({growTime[i],plantTime[i]});
        sort(vp.rbegin(),vp.rend());
        
        // for(auto i:vp) cout<<i.first<<" "<<i.second<<endl; cout<<endl;
        
        int ans = 0, initGrow = 0;
        for(int i=0;i<vp.size();i++) {
            int ugne_ka_samay = vp[i].first;
            int beej_lagane_ka_samay = vp[i].second;
            initGrow += beej_lagane_ka_samay;
            ans = max(ans, initGrow+ugne_ka_samay);
            // cout<<initGrow<<" "<<ans<<endl;
            // initGrow += ugne_ka_samay;
        }        
        // cout<<endl<<endl;
        return ans;
    }
};