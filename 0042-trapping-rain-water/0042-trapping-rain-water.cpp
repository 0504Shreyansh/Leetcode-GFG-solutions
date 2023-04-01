class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> dpMaxLeftHeight(height);
        vector<int> dpMaxRightHeight(height);
        
        // Find prefix left maximum height
        for(int i = 1; i < n; i++)
            dpMaxLeftHeight[i] = max(dpMaxLeftHeight[i-1], height[i]);
        
        // Find suffix right maximum height
        for(int i = n-2; i >= 0; i--)
            dpMaxRightHeight[i] = max(dpMaxRightHeight[i+1], height[i]);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += min(dpMaxLeftHeight[i], dpMaxRightHeight[i]) - height[i];
        
        return ans;
    }
};