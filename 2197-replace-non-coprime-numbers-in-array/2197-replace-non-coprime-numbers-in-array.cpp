class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        vector<int> ans;
        stack<int> st;
        
        for(auto i:nums) {
            // if(st.empty())
            //     st.push(i);                
            //keep pushing the lcm of the current ele and the top else simply push
            //and keep updating the current ele to push
            while(st.size()) {
                // cout<<"GCD : "<<i<<' '<<top<<' '<<gcd(i,top)<<endl;
                if(__gcd(i,st.top())>1) {
                    int top = st.top();
                    st.pop();
                    i = lcm(i,top);
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