//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class DLL {
public:
    int key, value;
    DLL *next, *prev;
    DLL(int _key, int _value) {
        key = _key;
        value = _value;
        next = prev = NULL;
    }
};

class LRUCache
{
    private:
    unordered_map<int, DLL*> m;
    DLL *head = new DLL({-1, -1});
    DLL *tail = new DLL({-1, -1});
    
    void addNode(DLL* node) {
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
        node -> prev = head;
    }
    
    void removeNode(DLL* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
    public:
    //Constructor for initializing the cache capacity with the given value.
    int C;
    LRUCache(int cap)
    {
        C = cap;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void SET(int key, int value) {
        if (m.find(key) != m.end()) {
            removeNode(m[key]);
            m.erase(key);
        }
        if (m.size() == C) {
            DLL* node = m[tail -> prev -> key];
            m.erase(node -> key);
            removeNode(tail -> prev);
        }
        addNode(new DLL(key, value));
        m[key] = head -> next;
    }
    
    int GET(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        DLL *node = m[key];
        int ans = node -> value;
        removeNode(node);
        addNode(node);
        m[key] = head -> next;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends