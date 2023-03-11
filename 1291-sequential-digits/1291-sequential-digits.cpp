class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        queue<int> q({1,2,3,4,5,6,7,8,9}); 
        vector<int> ans;
        
        while(!q.empty()) {
            int cur = q.front(); 
            q.pop();
            if(cur > high) 
                break; 
            if(cur >= low && cur <= high) 
                ans.push_back(cur);
            
            int num = cur % 10;           
            int next = cur * 10 + (++num);
            if(num < 10) 
                q.push(next);
        }
        return ans;
    }
};