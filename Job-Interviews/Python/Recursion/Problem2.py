#Swap nodes on paris

class Node:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

List =Node(1, next = Node(2, next=Node(3, next = Node(4, next = None))))

def solution (List):
    swap(List)
    return List
def swap(List):
    if List is None:

        return
    if List.next is not None:
        List.next.val, List.val = List.val, List.next.val
        swap(List.next.next) 

def printLinkedList(Node):
    if Node is not None:
        print(Node.val)
        printLinkedList(Node.next) 
print("First List")
printLinkedList(List) 
res = solution(List)
print("output")   
printLinkedList(res)

