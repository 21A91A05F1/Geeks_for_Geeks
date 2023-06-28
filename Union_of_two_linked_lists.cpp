/*
Given two linked lists, your task is to complete the function makeUnion(), that returns 
the union list of two linked lists. This union list should include all the distinct elements
only and it should be sorted in ascending order.
=========================================
Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
=====
Code:::
=====
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        Node* temp1=head1;
        set<int>s;
        while(temp1!=NULL)
        {
          s.insert(temp1->data);
          temp1=temp1->next;
        }
        Node* temp2=head2;
        while(temp2!=NULL)
        {
            s.insert(temp2->data);
            temp2=temp2->next;
        }
        Node* head=NULL;
        Node* tail=NULL;
        for(auto it:s)
        {
            Node* nn=new Node(it);
            if(head==NULL)
            {
                head=nn;
                tail=nn;
            }
            else
            {
                tail->next=nn;
                tail=tail->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
