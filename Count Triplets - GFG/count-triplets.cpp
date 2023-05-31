//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    struct Node *curr = head;
    vector<int> a;
    while(curr) {
        a.push_back(curr->data);
        curr = curr->next;
    }
    sort(begin(a),end(a));
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        int s = 0, e = a.size() - 1;
        if(s == i) s++;
        if(e == i) e--;
        while(s < e) {
            if(a[i] + a[s] + a[e] == x) {
                ans++;
                s++, e--;
            }
            else if(a[i] + a[s] + a[e] > x) {
                e--;
            }
            else {
                s++;
            }
            if(s == i) s++;
            if(e == i) e--;
        }
    }
    return ans / 3;
} 