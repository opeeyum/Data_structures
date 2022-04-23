#include <iostream>
using namespace std;

class node
{
    int data = 0;
    node *next = NULL;
    public:
    node* create_linked_list(int*, int);
    node* create_node(int);
    node* reverse_ll_recursive(node*, node* = NULL);
    node* reverse_ll_iterative(node*);
    void Print(node*);
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, len = 5;
    node obj, *head = NULL;
    head = obj.create_linked_list(arr, len);
    obj.Print(head);
    head = obj.reverse_ll_recursive(head);
    obj.Print(head);
    head = obj.reverse_ll_iterative(head);
    obj.Print(head);
}

node* node::reverse_ll_recursive(node* head, node* prev)
{
    // Method:- 1
    // node *temp = head->next;
    // head->next = prev;
    // if(temp)
    // return reverse_ll_recursive(temp, head);
    // return head;

    // Method:- 2
    if(!head || !head->next)
    return head;

    node* newHead = reverse_ll_recursive(head->next);
    head->next->next = head;
    head->next = NULL;    

    return newHead;
}

node* node::reverse_ll_iterative(node* head)
{
    node* prev = NULL;
    node* curr = head;
    node* future = NULL;

    while(curr)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }

    return prev;
}

node* node::create_linked_list(int* arr, int len)
{
    node *temp_head = NULL;
    for(int i=0; i<len; i++)
    {
        node *temp = this->create_node(arr[i]);
        if(!temp_head)
        temp_head = temp;
        else
        {            
            temp->next = temp_head;
            temp_head = temp;
        }
    }
    return temp_head;
}

node* node::create_node(int val)
{
    node *temp = new node();
    temp->data = val;
    return temp;
}

void node::Print(node *head)
{
    while(head)
    {
        cout<<head->data<<"->";        
        head = head->next;
    }
    cout<<"NULL"<<endl;
}