class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size(), i = 0;
        sort(skill.begin(),skill.end());
        int sum = skill[0]+skill[n-1];
        
        while(i<n/2) {
            if(sum!=skill[i]+skill[n-1-i]) 
                return -1;
            i++;
        }
        
        long long ans = 0;
        i=0;
        while(i<n/2) {
            ans += (skill[i]*skill[n-1-i]);
            i++;
        }
        return ans;
    }
};
