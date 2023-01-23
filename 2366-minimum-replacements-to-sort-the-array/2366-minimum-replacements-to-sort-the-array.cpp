class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        //Consider splitting the last ele. That would not be optimal at all
        //So consider it to be the largest ele in the sorted list
        long long ans = 0;
        int prevLargest = nums.back();
        
        for(int i=nums.size()-1;i>=0;i--) {
            //Most optimal way is to split in al most equals i.e.
            //Consider case1 - _,_,24,6
            //_,_,6,6,6,6,6 => ans += 4 (ceil(24/6))
            //Consider case2 - _,_28,6
            //_,_,4,6,6,6,6,6 => ans += 5 (ceil(28/6))
            //So, splits = ceil(nums[i]/prevLargest)
            if(nums[i]>prevLargest) {
                int splits = ((nums[i]+prevLargest-1)/prevLargest);
                //splits-1 bcoz one was the number itself
                ans += splits-1;
                //update prevLargest to new smaller value
                prevLargest = nums[i]/splits;
                // cout<<prevLargest<<' '<<ans<<endl;
            }
            //if an ele is found smaller than var, then update it.
            else 
                prevLargest = nums[i];
        }
        
        return ans;
    }
};