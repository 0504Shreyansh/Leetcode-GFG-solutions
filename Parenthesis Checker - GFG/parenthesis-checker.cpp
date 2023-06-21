//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool valid(char c1, char c2) {
        return ((c1=='('&&c2==')') || (c1=='{'&&c2=='}') || (c1=='['&&c2==']'));
    }
    bool ispar(string x)
    {
        stack<char> st;
        for(auto &it : x)
        {
            if(it=='('||it=='{'||it=='[') {
                st.push(it);
            }
            else {
                if(st.size() && valid(st.top(), it)) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.size() == 0;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends