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
    Node *bst_to_dll(Node *);
    Node *flatten_the_tree(Node *);
    Node *kth_smallest_element(Node *, int);
    bool bst_or_not(Node *);
    void print(Node *);
};
Node *Node::create_node(int a)
{
    Node *temp = new Node();
    temp->data = a;
    return temp;
}

Node *Node::insert_node(Node *root, int a)
{
    if (root == NULL)
    {
        root = create_node(a);
        return root;
    }
    else if (root->data >= a)
        root->left = insert_node(root->left, a);
    else
        root->right = insert_node(root->right, a);
    return root;
}

Node *Node::bst_to_dll(Node *root)
{
    if (!root)
        return NULL;

    Node *head = create_node(root->data);
    head->left = bst_to_dll(root->left);
    head->right = bst_to_dll(root->right);

    return head;
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

        // Push the children of recently popped node into the stack
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
int main()
{
    Node obj;
    Node *head = NULL;
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        head = obj.insert_node(head, a);
    }
    cout << "Breadth first traversal : ";
    obj.print(head);
    return 0;
}
