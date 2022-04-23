/*
Find mid of the linked list.
- First approach is to traverse a linked two times, first to get total number of elements,
second time to get the mid.

- Second (optimised) approach, take two pointers - fast and slow, fast takes two step at a time,
where as second takes one step, when fast reaches at the end of the linked list slow will be at the mid.
*/

#include <iostream>
using namespace std;

class node{
    int data = 0;
    node *next = NULL;
    public:
    node(int val=0, node *next=NULL): data(val), next(next) {}
    int find_mid_brute_force(node*);
    int find_mid_optimised(node* );

    node* insert_at_head(node*, int);
    void Print(node *);
};

int main()
{
    node obj, *head=NULL;
    for(int i=0; i<10; i++)
    head = obj.insert_at_head(head, i);

    obj.Print(head);
    cout<<obj.find_mid_brute_force(head)<<endl;
    cout<<obj.find_mid_optimised(head)<<endl;
}

int node::find_mid_optimised(node *head)
{
    node *fast, *slow;
    fast = slow = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int node::find_mid_brute_force(node *head)
{
    int count=0;
    node *temp = head;
    while(temp)
    {
        count++;
        temp = temp->next;
    }

    for(int i=0; i < (count/2); i++)
    head = head->next;

    return head->data;
}

node* node::insert_at_head(node* head, int val)
{
    node *temp = new node(val);
    if(head)
    temp->next = head;

    head = temp;

    return head;
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