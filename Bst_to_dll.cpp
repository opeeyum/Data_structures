/*Incomplete*/
#include <iostream>
using namespace std;

class Node
{
   int data;
   Node *next /*Right*/, *prev /*left*/;

   public:
        Node(int val = 0, Node *ptr = NULL, Node *adj = NULL): data(val), next(ptr), prev(adj){}
        Node* createNode(int);
        Node* insertNode(int, Node* = NULL);
        Node* createBst(Node*, int);
        Node* bstToDll(Node*);
        void Print(Node*, int);
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
   {
       head->prev = temp1;
       temp1->next = head;
   }
   
   head = temp1;
   return head;
}

Node* Node::createBst(Node *head, int val)
{
    if(!head)
    return createNode(val);

    else if(head->data >= val)
    head->prev = createBst(head->prev, val);

    else
    head->next = createBst(head->next, val);

    return head;
}

void Node::Print(Node *head, int mode)
{
    if(!mode)
    {
        cout<<"Forward:  ";
        while(head)
        {
            cout<<head->data<<" ";
            if(!head->next)
            break;
            head=head->next;        
        }
        cout<<endl;

        cout<<"Backward: ";
        while(head)
        {
            cout<<head->data<<" ";
            head=head->prev;
        }
        cout<<endl;    
    }

    else
    {
        if(!head)
        return;

        Print(head->prev, mode);
        cout<<head->data<<" ";
        Print(head->next, mode);
    } 
}

Node* Node::bstToDll(Node *root)
{
    if(!root)
    return NULL;
    
    Node *head = createNode(root->data);
    head->prev = bstToDll(root->prev);
    head->next = bstToDll(root->next);
    
    return head;
}

int main()
{
    Node obj, *head=NULL, *root = NULL;

    int arr[] = {8, 3, 10, 1, 6, 4, 7, 14};
    for(int i=7; i>=0; i--)
    {
        head = obj.insertNode(arr[i], head);
        root = obj.createBst(root, arr[i]);
    }    

    obj.Print(head, 0);
    cout<<"Inorder:  ";
    obj.Print(root, 1);
    cout<<endl;

    return 0;
}
