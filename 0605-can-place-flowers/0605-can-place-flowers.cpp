class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        // Get all indices of the 1's
        vector<int> inds;
        int size = flowerbed.size();
        for (int i = 0; i < size; i++)
            if (flowerbed[i] == 1)
                inds.push_back(i);
        
        if (inds.size()==0) 
            return n<=(size+1)/2;
        // 0, 0, 0, 0, 0, 1 -> (5/2) 0's
        if (inds[0] >= 2)
            n -= (inds[0]) / 2;
        
        // 1, 0, 0, 0, 0, 0, 0 -> (6/3) 0's
        if (inds.back() < size-2)
            n -= (size - inds.back()) / 2;
        
        // 1, 0, 0, 1 -> (3-0-2)/2 flowers
        // 1, 0, 0, 0, 1 -> (4-0-2)/2 flowers
        for (int i = 1; i < inds.size(); i++) 
            if (inds[i] - inds[i-1] - 2 >= 0) n -= (inds[i] - inds[i-1] - 2) / 2;
    
        return !(n>0);
    }
};