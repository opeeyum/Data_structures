#include <iostream>
#include <queue>
using namespace std;

class Node
{
   int data;
   Node *left, *right;

   public:
      Node(int val=0, Node *ptr1=NULL, Node *ptr2=NULL): data(val), left(ptr1), right(ptr2){}
      Node* createNode(int);
      Node* insertNode(int, Node* = NULL);
      void Print(Node*);
};

Node* Node::createNode(int val)
{
   return new Node(val);
}

Node* Node::insertNode(int val, Node *root)
{
   if(!root)
   return createNode(val);
   queue <Node*> q;
   q.push(root);
   while(!q.empty())
   {
      Node* temp = q.front();
      q.pop();
      if(temp->left)
      q.push(temp->left);
      else if(!temp->left)
      {
         temp->left = createNode(val);
         break;
      }
      if(temp->right)
      q.push(temp->right);
      else if(!temp->right)
      {
         temp->right = createNode(val);
         break;
      }     
   }
   return root;
}

void Node::Print(Node *root)
{
   if(!root)
   return;
  
   cout<<root->data<<" ";
   Print(root->left);
   Print(root->right);   
   
}

int main()
{
   Node obj, *root=NULL;

   for(int i=0; i<10; i++)
   root = obj.insertNode(i, root);

   obj.Print(root);
   cout<<endl;
      
   return 0;
}
