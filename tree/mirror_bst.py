'''
Given a Binary Tree, convert it into its mirror.
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

'''
class node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class bst:
    def __init__(self):
        self.head = None
    
    def insertNode(self, root, val,):
        "Creating and Inserting node in the BST"
        if root == None:
            return node(val)
        if root.data >= val:
            root.left = self.insertNode(root.left, val)        
        else:
            root.right = self.insertNode(root.right, val)        
        return root
    
    def Print(self, root):
        "Inorder Traversal"
        if not root:
            return        
        self.Print(root.left)
        print(root.data, end= " ")
        self.Print(root.right)
    
    def Mirror(self):
        "Interchange the left and right child's of a bst."
        if not self.head:
            return
        queue = []
        queue.append(self.head)
        while queue:
            temp = queue.pop()
            if temp.right:
                queue.append(temp.right)
            if temp.left:
                queue.append(temp.left)
            temp.left, temp.right = temp.right, temp.left

if __name__ == "__main__":
    obj = bst()
    arr = [50, 30, 70, 20, 40, 60, 80]
    for i in arr:
        obj.head = obj.insertNode(obj.head, i)   
    obj.Print(obj.head)
    print()

    obj.Mirror()

    obj.Print(obj.head)
    print()

