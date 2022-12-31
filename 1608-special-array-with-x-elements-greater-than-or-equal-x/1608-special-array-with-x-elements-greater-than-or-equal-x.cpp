class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1){
             if(!nums[0]) return -1;
             else return 1;
        }
         if(n==2){
             if(nums[0]==1||nums[1]==0) return -1;
             else return 2;
        }
        
        int lo=0, hi=n, mid, ans=-1, t=8;
        
        while(t--){
            mid=(lo+hi)/2;
            int midv=n-(lower_bound(nums.begin(),nums.end(),mid)-nums.begin());
            if(midv==mid) return mid;
            else if(midv<mid) hi=mid-1;
            else lo=mid+1;
        }
        return ans;
    }
};