class Solution {
public:
    /*Concept -> 1. Push +ve numbers.
    2. If -ve is encountered, then keep popping the smaller +ve magnitudes.
    3. If the stack is empty, then push the -ve number.
    4. If same magnitude numbers then pop the +ve number.
    */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        vector<int> ans;
        
        for(auto i:asteroids) {
            while(!st.empty() && st.top()>0 && i<0) {
                int diff = i + st.top();
                if(abs(i)>st.top())  //Pop as the -ve val is greater than the +ve val
                    st.pop();
                else if(st.top()>abs(i)) //Break here so as to push the val 
                    i = 0;
                else { //Equal wala case
                    i = 0;
                    st.pop();
                }
            }
            if(i!=0) 
                st.push(i);
        }
    
        while(st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};