class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        vector<int> vis(arr.size());
        queue<int> q({start});
        while(q.size()) {
            int x = q.size();
            while(x--) {
                int index = q.front();
                q.pop();
                if(arr[index]==0)
                    return true;
                if(index+arr[index]<arr.size() && !vis[index+arr[index]])
                    q.push(index+arr[index]), vis[index+arr[index]]++;
                if(index-arr[index]>=0 && !vis[index-arr[index]])
                    q.push(index-arr[index]), vis[index-arr[index]]++;
            }
        }
        
        return false;
    }
};