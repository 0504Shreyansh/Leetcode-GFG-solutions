//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
private:
    Node* reverse(Node* head) {
        Node* cur = head, *prev = NULL, *f;
        while (cur) {
            f = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = f;
        }
        return prev;
    }
public:
    Node *compute(Node *head)
    {
        if (!head) return NULL;
        head = reverse(head);
        Node *cur = head;
        while (cur -> next) {
            Node* curN = cur -> next;
            if (curN -> data < cur -> data) {
                cur -> next = curN -> next;
            } else {
                cur = cur -> next;
            }
        }
        return reverse(head);
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends