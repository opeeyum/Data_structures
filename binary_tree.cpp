#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;

public:
    Node *create_node(int);
    Node *insert_node(Node *, int);
    Node *flatten_the_tree(Node *);
    Node *mirror_the_tree(Node *);
    int find_height(Node *);
    void BFS_traversal(Node *);
    void DFS_traversal(Node *);
    void RecursiveInorder(Node *);
    void IterativeInorder(Node *);
    void print(Node *);
};

Node *Node::create_node(int a)
{
    Node *temp = new Node();
    temp->data = a;
    return temp;
}

// Level wise insertion
// Idea is to find the node do not having either left or right child
Node *Node::insert_node(Node *root, int val)
{
    if (!root)
        return create_node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        else if (!temp->left)
        {
            temp->left = create_node(val);
            break;
        }
        if (temp->right)
            q.push(temp->right);
        else if (!temp->right)
        {
            temp->right = create_node(val);
            break;
        }
    }
    return root;
}

Node *Node::flatten_the_tree(Node *root)
{
    // Create the stack
    stack<Node *> s;

    // Push the root into the stack
    s.push(root);

    // Pointer to keep track of previous pop
    Node *prev = NULL;
    while (!s.empty())
    {
        // Pointer to keep track of latest pop
        Node *temp = s.top();
        // Pop the top of the stack
        s.pop();

        // Push the children of recently popped Node into the stack
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);

        // If previous pop exists update its child
        if (prev)
        {
            prev->right = temp;
            prev->left = NULL;
        }

        // Update Previous pop
        prev = temp;
    }
    return root;
}

/*Given a Binary Tree, convert it into its mirror.
Example 1:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2

Example 2:

Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.

*/
Node *Node::mirror_the_tree(Node *root)
{
    if (!root)
        return root;

    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);

        swap(temp->left, temp->right);
    }
    return root;
}

int Node::find_height(Node *root)
{
    if (!root)
        return -1;
    if (!root->left && !root->right)
        return 0;
    return max(find_height(root->left), find_height(root->right)) + 1;
}
void Node::BFS_traversal(Node *head)
{
    if (!head)
        return;
    queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        cout << temp->data << " ";
    }
}
void Node::DFS_traversal(Node *head)
{
    if (!head)
        return;
    stack<Node *> s;
    s.push(head);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
        cout << temp->data << " ";
    }
}

void Node::print(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

// Driver Code
int main()
{
    return 0;
}
