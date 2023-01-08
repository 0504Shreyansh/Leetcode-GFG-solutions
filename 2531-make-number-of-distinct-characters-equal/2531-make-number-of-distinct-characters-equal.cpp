class Solution {
public:
    bool isItPossible(string word1, string word2) {
        // map<char,int> mp,mpp;
        // for(auto i : word1) {
        //     mp[i]++;
        //     // mpp[i]--;
        // }
        // for(auto i : word2) {
        //     mpp[i]++; 
        //     // mp[i]++;
        // }
        // cout << mp.size() << ' ' << mpp.size() << endl;
        // if(mp.size() == mpp.size()) {
        //     cout<<mp.size()<<' '<<mpp.size()<<endl;
        //     return true;
        // }
        // char ch;
        // bool f = false, ff = false;
        // for(auto i : mp) {
        //     if(i.second > 1) {
        //         chh.push_back(i.first); f = true;
        //         break;
        //     }
        // }
        // for(auto i : mpp) {
        //     if(i.second > 1) {
        //         chhh.push_back(i.first); ff = true;
        //         break;
        //     }
        // }
        // for(auto i : mpp) {
        //     for(auto j : chh) {
        //         if(j!=i.first && i.second > 1)
        //             return true;
        //     }
        // }
        // for(auto i : mp) {
        //     for(auto j : chhh) {
        //         if(j!=i.first && i.second > 1)
        //             return true;
        //     }
        // }
        // for(auto i : mp) {
        //     if(i.second > 1 && mpp[i.first] > 1) {
        //         cout<<i.first<<' '<<i.second<<' '<<mpp[i.first]<<endl; 
        //         return true;
        //     }
        // }
        // return false;
        vector<int> freq(26,0), freqq(26,0);
        for(auto i : word1) freq[i-'a']++;
        for(auto i : word2) freqq[i-'a']++;
        
        for(auto i : freq) cout<<i<<' '; cout<<endl;
        for(auto i : freqq) cout<<i<<' '; cout<<endl;
        
        for(int i=0;i<26;i++) {
            for(int j=0;j<26;j++) {
                if(freq[i]>=1 && freqq[j]>=1) {
                    freq[i]--; freq[j]++;
                    freqq[j]--; freqq[i]++;
                    int c1 = 0, c2 = 0;
                    for(int k=0;k<26;k++) {
                        if(freq[k]>=1) 
                            c1++;
                        if(freqq[k]>=1) 
                            c2++; 
                    }
                    if(c1 == c2) return true;
                    freq[i]++; freq[j]--;
                    freqq[j]++; freqq[i]--;
                }
            }
        }
        
        return false;
    }
};