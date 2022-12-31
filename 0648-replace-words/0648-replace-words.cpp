class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {  //648
        sort(dictionary.begin(),dictionary.end());
        // for(auto i:dictionary) cout<<i<<" "; cout<<endl;
        sentence += ' ';
        int n = sentence.size();
        string temp, ans;
        
        for(int i=0;i<n;i++) {
            if(sentence[i]!=' ') 
                temp += sentence[i];    
            else {
                bool f = false;
                for(int k=0;k<dictionary.size();k++) {
                    int x = dictionary[k].size();
                    // cout<<dictionary[k]<<" "<<temp.substr(0,x)<<endl;
                    if(dictionary[k]==temp.substr(0,x)) {
                       f = true; ans += dictionary[k]; break;
                    }
                }
                if(!f) ans += temp;
                ans += ' ';
                temp.clear();
                // cout<<endl;
            }
        }
        ans.pop_back();
        return ans;
    }
};