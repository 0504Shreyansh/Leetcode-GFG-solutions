class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        //cout << s1 << " " << s2 << endl;
        bool f = false, ff = false;
        
        for(int i=0;i<s1.size();i++) {
            if(s2[i]>s1[i]) f=true;
            if(s1[i]>s2[i]) ff=true;
        }
        
        return (f!=ff);
    }
};
