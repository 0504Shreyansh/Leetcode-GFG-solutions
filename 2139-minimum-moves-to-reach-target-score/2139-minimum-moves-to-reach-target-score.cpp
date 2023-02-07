class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int moves = 0;
        //Go by the second move first to shorten the problem
        while(maxDoubles-- && target!=1) {
            //If it is odd, we need to decrement(first move) 
            if(target&1)
                moves++;
            target >>= 1;
            moves++;
        }
        //After applying required operations, just consider simple decrementing
        //the target value by 1 (target=6 => numberOfOperations=5(target-1))
        return moves+target-1;
    }
};