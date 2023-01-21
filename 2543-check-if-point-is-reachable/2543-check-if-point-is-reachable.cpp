class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        
        while(!(targetX&1)) targetX /= 2;
        while(!(targetY&1)) targetY /= 2;
        
        return (__gcd(targetX,targetY)==1);
        
    }
};