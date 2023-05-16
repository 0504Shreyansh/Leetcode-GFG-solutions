//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

struct TrieNode {
    TrieNode *childNode[26];
    bool containsKey(char ch) {
        return childNode[ch - 'a'] != NULL;
    }
    void put(char ch, TrieNode *root) {
        childNode[ch - 'a'] = root;
    }
    TrieNode* get(char ch) {
        return childNode[ch - 'a'];
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int N = s.size();
    int ans = 1;
    TrieNode* root = new TrieNode();
    for(int i = 0; i < N; i++) {
        TrieNode *node = root;
        for(int j = i; j < N; j++) {
            if(!node->containsKey(s[j])) {
                ans++;
                node->put(s[j], new TrieNode());
            }
            node = node->get(s[j]);
        }
    }
    return ans;
}