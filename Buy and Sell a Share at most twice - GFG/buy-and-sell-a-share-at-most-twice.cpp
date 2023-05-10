//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>& prices) {
        // Declaration
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));


        // base case 
        // 1. if (cap==0) means i and buy can be any thing 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=1;j++)
            {
                dp[i][j][0]=0;
            }
        }
        // if(i==n)
        for(int buy=0;buy<2;buy++)
        {
            for(int cap=0;cap<3;cap++)
            {
                dp[n][buy][cap]=0;
            }
        }


        for(int i=n-1;i>=0;i--)
        {   
           
            for(int j=0;j<=1;j++)
            {
                 
                for(int cap=1;cap<3;cap++)
                {
                    if(j==0)
                    {
                        dp[i][j][cap]= max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                    else
                    {
                        dp[i][j][cap]= max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }
                }
                
            } 
        }
        return dp[0][1][2];
    }

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends