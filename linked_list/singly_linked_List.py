class node:
    def __init__(self, val):
        self.data = val
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None
    
    def createNode(self, val):
        "I create Node."
        return node(val)
    
    def insertNode(self, val):
        "I insert node in the begining."
        temp = self.createNode(val)
        if self.head:
            temp.next = self.head        
        return temp
    
    def Print(self):
        "I print all the element of the linked list."
        temp = self.head
        while temp:
            print(temp.data, end =" ")
            temp = temp.next
        print()
    
    def Reverse(self):
        pass

if __name__ == "__main__":
    obj = linkedList()
    arr = [8, 3, 10, 1, 6, 4, 7, 14]
    for i in arr:
        obj.head = obj.insertNode(i)    
    obj.Print()

