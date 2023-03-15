class Solution {
public:
    string originalDigits(string s) {
        string ans;
        map<char, int> dig;
        for(auto x : s)
            dig[x]++;
        // 0 (z only in 0)
        while(dig['z']&&dig['e']&&dig['r']&&dig['o'])
            ans+="0", dig['z']--, dig['e']--, dig['r']--, dig['o']--;
        // 2 (w only in 2)
        while(dig['t']&&dig['w']&&dig['o'])
            ans+="2", dig['t']--, dig['w']--, dig['o']--;
        // 4 (u only in 4)
        while(dig['f']&&dig['o']&&dig['u']&&dig['r'])
            ans+="4", dig['f']--, dig['o']--, dig['u']--, dig['r']--;
        // 6 (x only in 6)
        while(dig['x'])
            ans+="6", dig['s']--, dig['i']--, dig['x']--;
        // 8 (g only in 8)
        while(dig['e']&&dig['i']&&dig['g']&&dig['h']&&dig['t'])
            ans+="8", dig['e']--, dig['i']--, dig['g']--, dig['h']--, dig['t']--;
        // 7 
        while(dig['s']&&dig['v']&&dig['n']&&dig['e']>1)
            ans+="7", dig['s']--, dig['v']--, dig['n']--, dig['e']-=2;
        // 5
        while(dig['f']&&dig['i']&&dig['v']&&dig['e'])
            ans+="5", dig['f']--, dig['i']--, dig['v']--, dig['e']--;
        // 1
        while(dig['o']&&dig['n']&&dig['e'])
            ans+="1", dig['o']--, dig['n']--, dig['e']--;
        // 3
        while(dig['t']&&dig['h']&&dig['r']&&dig['e']>1)
            ans+="3", dig['t']--, dig['h']--, dig['r']--, dig['e']-=2;
        // 9
        while(dig['i']&&dig['e']&&dig['n']>1)
            ans+="9", dig['i']--, dig['e']--, dig['n']-=2;
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};