class Solution {
public:
    string getHint(string secret, string guess) {
        
        int A = 0, B = 0;
        unordered_map<char,int> mp, mpp;
        for(int i = 0; i < guess.size(); i++) { 
            if(secret[i]==guess[i])
                A++;
            else 
                mp[secret[i]]++, mpp[guess[i]]++;
        }

        for(auto [x, y] : mp) 
            if(mpp[x])
                B += min(mpp[x],y);
        
        // cout<<A<<' '<<B<<endl;
        string ans;
        ans += to_string(A) + "A" + to_string(B) + "B";
        return ans;
    }
};