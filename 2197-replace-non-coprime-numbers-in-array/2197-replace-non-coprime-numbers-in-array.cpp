class Solution {
public:
    long long gcd(long long a, long long b) {
        if(a==0) return b;
        return gcd(b%a,a);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        vector<int> ans;
        stack<long long> st;
        
        for(auto i:nums) {
            // if(st.empty())
            //     st.push(i);                
            //keep pushing the lcm of the current ele and the top else simply push
            //and keep updating the current ele to push
            while(st.size()) {
                // cout<<"GCD : "<<i<<' '<<top<<' '<<gcd(i,top)<<endl;
                if(gcd(i,st.top())>1) {
                    long long top = st.top();
                    st.pop();
                    i = (i*top)/gcd(i,top);
                } else 
                    break;
            }
            st.push(i);
            // cout<<st.top()<<endl;
        }
        
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
    
        reverse(ans.begin(),ans.end());
        return ans;
    }
};