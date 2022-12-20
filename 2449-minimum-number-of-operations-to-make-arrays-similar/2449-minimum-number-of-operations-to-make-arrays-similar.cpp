class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        
        long long ans = 0;
        int n = nums.size();
        vector<int> e1,e2,o1,o2;
        
        for(auto i:nums) {
            if(i&1) o1.push_back(i);
            else e1.push_back(i);
        }
        for(auto i:target) {
            if(i&1) o2.push_back(i);
            else e2.push_back(i);
        }
        
        sort(e1.begin(),e1.end());
        sort(o1.begin(),o1.end());
        sort(e2.begin(),e2.end());
        sort(o2.begin(),o2.end());
        
        // for(auto i:e1) cout<<i<<" "; cout<<endl;
        // for(auto i:e2) cout<<i<<" "; cout<<endl;
        // for(auto i:o1) cout<<i<<" "; cout<<endl;
        // for(auto i:o2) cout<<i<<" "; cout<<endl;
        
        for(int i=0;i<e1.size();i++) {
            if(e2[i]>e1[i])
                ans += (e2[i]-e1[i])/2;
        }
        for(int i=0;i<o1.size();i++) {
            if(o2[i]>o1[i])
                ans += (o2[i]-o1[i])/2;
        }
        return ans;
    }
};