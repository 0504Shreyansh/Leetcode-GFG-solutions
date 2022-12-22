class Solution {
public:
    /*Concept -> Sabse kam growTime wale ko last mei lo, store {g,p}
    {(2,3),(2,1),(1,2),(1,2)}
    1. time-> 3+2-> 5
    2. time-> (3)+1+2-> 6
    3. time-> (3+1+2)+1-> 7
    4. time-> (3+1+2+2)+1->9
    */
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size(), ans = 0, initialTime = 0;
        priority_queue<pair<int,int>> pq;        
        for(int i=0;i<n;i++)
            pq.push({growTime[i],plantTime[i]});
        // while(pq.size()) {
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        // cout<<endl;
        while(pq.size()) {
            int gTime = pq.top().first, pTime = pq.top().second;
            pq.pop();
            initialTime += pTime;
            ans = max(ans, initialTime+gTime);
            // cout<<initialTime<<" "<<ans<<endl;
        }// cout<<endl<<endl;
        return ans;
    }
};