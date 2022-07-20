#include <iostream>
using namespace std;

class Node
{
   int data;
   Node *next;

public:
   Node(int val = 0, Node *ptr = NULL) : data(val), next(ptr) {}
   Node *createNode(int);
   Node *insertNode(int, Node * = NULL);
   Node *deleteNode(int, Node *);
   Node *reverse_ll_recursive(Node *, Node * = NULL);
   Node *reverse_ll_iterative(Node *);
   Node *reverse_k_Node(Node *, int);
   Node *reverse_sublist(Node *, int, int);
   Node *merge_sorted_list(Node *, Node *);
   int find_mid_brute_force(Node *);
   int find_mid_optimised(Node *);
   void Print(Node *);
};

Node *Node::createNode(int val)
{
   return new Node(val);
}

Node *Node::insertNode(int val, Node *head)
{
   // Inserting Node at head
   Node *temp1 = createNode(val);
   if (head)
      temp1->next = head;
   head = temp1;
   return head;
}

Node *Node::deleteNode(int val, Node *head)
{
   Node *temp1 = NULL, *temp2 = head;
   int flag = 1;
   while (temp2)
   {
      if (temp2->data == val)
      {
         // To delete intermidiate or last Node.
         if (temp1)
            temp1->next = temp2->next;

         // To delete first Node.
         else
            head = temp2->next;

         delete temp2;
         flag = 0;
         cout << "Node with value " << val << " deleted." << endl;
         break;
      }
      temp1 = temp2; // Points to previous Node
      temp2 = temp2->next;
   }
   if (flag)
      cout << "No such element to delete." << endl;
   return head;
}

int Node::find_mid_optimised(Node *head)
{
   Node *fast, *slow;
   fast = slow = head;

   while (fast && fast->next)
   {
      slow = slow->next;
      fast = fast->next->next;
   }

   return slow->data;
}

int Node::find_mid_brute_force(Node *head)
{
   int count = 0;
   Node *temp = head;
   while (temp)
   {
      count++;
      temp = temp->next;
   }

   for (int i = 0; i < (count / 2); i++)
      head = head->next;

   return head->data;
}

Node *Node::reverse_ll_recursive(Node *head, Node *prev)
{
   // Method:- 1
   // Node *temp = head->next;
   // head->next = prev;
   // if(temp)
   // return reverse_ll_recursive(temp, head);
   // return head;

   // Method:- 2
   if (!head || !head->next)
      return head;

   Node *newHead = reverse_ll_recursive(head->next);
   head->next->next = head;
   head->next = NULL;

   return newHead;
}

Node *Node::reverse_ll_iterative(Node *head)
{
   Node *prev = NULL;
   Node *curr = head;
   Node *future = NULL;

   while (curr)
   {
      future = curr->next;
      curr->next = prev;
      prev = curr;
      curr = future;
   }

   return prev;
}

Node *Node::reverse_k_Node(Node *head, int k)
{
   Node *prev = NULL;
   Node *curr = head;
   Node *future = NULL;
   int count = k;

   while (curr && --count)
   {
      future = curr->next;
      curr->next = prev;
      prev = curr;
      curr = future;
   }
   if (future)
      head->next = reverse_k_Node(curr, k);
   return prev;
}

Node *Node::merge_sorted_list(Node *root_one, Node *root_two)
{
   if (!root_one)
      return root_two;

   if (!root_two)
      return root_one;

   if (root_one->data > root_two->data)
   {
      root_two->next = merge_sorted_list(root_two->next, root_one);
      return root_two;
   }

   root_one->next = merge_sorted_list(root_one->next, root_two);
   return root_one;
}

/* Question:
Given a linked list and positions m and n. Reverse the linked list from position m to n.

Example 1:
    Input :
    N = 10
    Linked List = 1->7->5->3->9->8->10->2->2->5->NULL
    m = 1, n = 8
    Output : 2 10 8 9 3 5 7 1 2 5
    Explanation :
    The Nodes from position 1 to 8 are reversed, resulting in 2 10 8 9 3 5 7 1 2 5.

Example 2:
    Input:
    N = 6
    Linked List = 1->2->3->4->5->6->NULL
    m = 2, n = 4
    Output: 1 4 3 2 5 6
    Explanation:
    Nodes from position 2 to 4 are reversed resulting in 1 4 3 2 5 6.
*/
Node *Node::reverse_sublist(Node *head, int m, int n)
{
   // If head is null OR list have only one Node OR m == n
   if (!head || !head->next || m == n)
      return head;

   Node *temp = head, *start = NULL;

   // Keeping the pointers to the Node previous to starting Node and the starting Node
   for (int i = 0; i < m - 1; i++)
   {
      start = temp;
      temp = temp->next;
   }

   Node *prev, *curr, *future;
   prev = curr = future = NULL;

   curr = temp;

   // Reversing the n-m+1 elements with three pointer approach
   for (int i = 0; curr, i < n - m + 1; i++)
   {
      future = curr->next;
      curr->next = prev;
      prev = curr;
      curr = future;
   }

   // If m == 1, reverse started from begining of the list
   // After reversal prev is the head of the reversed list
   if (!start)
      head = prev;
   else
      start->next = prev;

   // curr points to the Node that was next to prev before reversal
   temp->next = curr;

   return head;
}

void Node::Print(Node *head)
{
   while (head)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << endl;
}

// Driver Code
int main()
{
   return 0;
}
