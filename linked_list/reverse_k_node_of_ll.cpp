#include <iostream>
using namespace std;

class node
{
    int data=0;
    node* next = NULL;
    public:
    node(int val=0)
    {
        data = val;
    }
    node* insert_at_head(node*, int);
    node* reverse_k_node(node*, int);
    void Print(node*);

};

int main()
{
    node* head = NULL;
    node obj;
    for(int i=0; i<10; i++)
    head = obj.insert_at_head(head, i);

    obj.Print(head);

    head = obj.reverse_k_node(head, 3);
    obj.Print(head);

    return 0;

}
node* node::insert_at_head(node* head, int val)
{
    if(!head)
    head = new node(val);
    
    else
    {
        node* temp = new node(val);
        temp->next = head;
        head = temp;
    }
    return head;
}

node* node::reverse_k_node(node* head, int k)
{
    node* prev = NULL;
    node* curr = head;
    node* future = NULL;
    int count = k;

    while(curr && --count)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;      
    }
    if(future)
    head->next = reverse_k_node(curr, k);
    return prev;
}

void node::Print(node* head)
{
    while(head)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
