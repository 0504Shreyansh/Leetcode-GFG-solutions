class Solution {
public:
    int ans = INT_MAX;
    void recSol(int i, int n, int k, vector<int>& cookies, vector<int>& countOfCookies) {
        // Base case 
        if(i==-1) {
            // Take out the maximum count of the cookies accquired by any child
            // This maxima should be minimised
            // Hence, try all possibilities
            int maxi = INT_MIN;
            for(auto x : countOfCookies)
                maxi = max(maxi, x);
            if(maxi != 0) 
                if(ans > maxi)
                    ans = maxi;
            return ; 
        }
        for(int j = 0; j < k; j++) {
            countOfCookies[j] += cookies[i];  //Pick 
            recSol(i-1, n, k, cookies, countOfCookies);
            countOfCookies[j] -= cookies[i];  //NotPick
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> countOfCookies(k, 0);
        recSol(n-1, n, k, cookies, countOfCookies);
        return ans;
    }
};