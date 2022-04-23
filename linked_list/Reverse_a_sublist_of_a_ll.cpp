/* Question:
Given a linked list and positions m and n. Reverse the linked list from position m to n.

Example 1:
    Input :
    N = 10
    Linked List = 1->7->5->3->9->8->10->2->2->5->NULL
    m = 1, n = 8
    Output : 2 10 8 9 3 5 7 1 2 5 
    Explanation :
    The nodes from position 1 to 8 are reversed, resulting in 2 10 8 9 3 5 7 1 2 5.

Example 2:
    Input:
    N = 6
    Linked List = 1->2->3->4->5->6->NULL
    m = 2, n = 4
    Output: 1 4 3 2 5 6
    Explanation:
    Nodes from position 2 to 4 are reversed resulting in 1 4 3 2 5 6.
*/

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

    public:
        Node(int val = 0, Node *ptr = NULL): data(val), next(ptr){}
        Node* createNode(int);
        Node* insertNode(int, Node*);
        Node* reverse_sublist(Node*, int, int);
        void Print(Node*);
};

Node* Node::createNode(int val)
{
   return new Node(val);
}

Node* Node::insertNode(int val, Node *head)
{
   //Inserting node at head
   Node* temp1 = createNode(val);
   if(head)
   temp1->next = head;
   head = temp1;
   return head;
}

void Node::Print(Node *head)
{
   while(head)
   {
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<"NULL"<<endl;
}

Node* Node::reverse_sublist(Node* head, int m, int n)
{
    //If head is null OR list have only one node OR m == n
    if(!head || !head->next || m==n)
    return head;
    
    Node *temp = head, *start = NULL;

    // Keeping the pointers to the node previous to starting node and the starting node
    for(int i=0; i<m-1; i++)
    {
        start = temp;
        temp = temp->next;
    }    

    Node *prev, *curr, *future;
    prev = curr = future = NULL;

    curr = temp;  

    // Reversing the n-m+1 elements with three pointer approach    
    for(int i=0; curr, i<n-m+1; i++)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;        
    }
    
    // If m == 1, reverse started from begining of the list
    // After reversal prev is the head of the reversed list
    if(!start)
    head = prev;    
    else
    start->next = prev;
    
    // curr points to the node that was next to prev before reversal
    temp->next = curr;
    
    return head; 
}

int main()
{
    Node obj, *head=NULL;

    int arr[10] = {1, 7, 5, 3, 9, 8, 10, 2, 2, 5};
    for(int i=9; i>=0; i--)
    head = obj.insertNode(arr[i], head);

    obj.Print(head);

    head = obj.reverse_sublist(head, 1, 8);
    obj.Print(head);
   
    return 0;
}
