class Solution {
public:
    long long minimumReplacement(vector<int>& A) {
        //Consider splitting the last ele --> bad option
        //So consider it to be the largest ele in the sorted list
        long long res = 0;
        int n = A.size();
        int prevLargest = A.back();
        for (int i = n - 2; i >= 0; i--) {
            //Most optimal way is to split in al most equals i.e.
            //Consider case1 - _,_,24,6
            //_,_,6,6,6,6,6 => ans += 4 (ceil(24/6)) - 1
            //Consider case2 - _,_28,6
            //_,_,4,6,6,6,6,6 => ans += 5 (ceil(28/6)) - 1
            //So, splits = ceil(nums[i]/prevLargest)
            if(A[i] > prevLargest) {
                int splits = (A[i] - 1) / prevLargest;
                //splits-1 bcoz one was the number itself
                res += splits;
                prevLargest = A[i] / (splits + 1);
            } else { 
                //if an ele is found smaller than var, then update it.
                prevLargest = A[i];
            }
        }
        return res;
    }
};