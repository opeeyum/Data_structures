#include <iostream>
using namespace std;

class Node
{
   int data;
   Node *next;

   public:
      Node(int val = 0, Node *ptr = NULL): data(val), next(ptr){}
      Node* createNode(int);
      Node* insertNode(int, Node* = NULL);
      Node* deleteNode(int, Node*);
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

Node* Node::deleteNode(int val, Node *head)
{
   Node *temp1 = NULL, *temp2 = head;
   int flag = 1;
   while(temp2)
   {      
      if(temp2->data == val)
      {  
         //To delete intermidiate or last node.
         if(temp1)
         temp1->next = temp2->next;
         
         //To delete first node.
         else
         head = temp2->next;

         delete temp2;
         flag = 0;
         cout<<"Node with value "<<val<<" deleted."<<endl;
         break;
      }
      temp1 = temp2; //Points to previous node
      temp2 = temp2->next;
   }
   if(flag)
   cout<<"No such element to delete."<<endl;
   return head;
}

void Node::Print(Node *head)
{
   while(head)
   {
      cout<<head->data<<" ";
      head=head->next;
   }
   cout<<endl;
}

int main()
{
   Node obj, *head=NULL;

   for(int i=1; i<10; i++)
   head = obj.insertNode(i, head);

   obj.Print(head);
   head = obj.deleteNode(1, head);
   obj.Print(head);
   head = obj.deleteNode(9, head);
   obj.Print(head);
   head = obj.deleteNode(10, head);
   obj.Print(head);
   
   return 0;
}
