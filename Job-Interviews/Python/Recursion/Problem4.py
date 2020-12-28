#Reverse Linked List
"""
1->2->3->4->None
4->3->2->1->None

"""
class Node:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next


def ReverseLinkedList(head):
    if not head or not head.next:
        return head
    p = ReverseLinkedList(head.next)
    head.next.next = head
    head.next = None
    return p

def ReverseLinkedListIteratively(head):
    prev, curr= None, head
    while curr:
        curr.next, prev, curr = prev, curr, curr.next


    return prev
def printLinkedList(Node):
    if Node is not None:
        print(Node.val)
        printLinkedList(Node.next) 

print("Recursiva")
List =Node(1, next = Node(2, next=Node(3, next = Node(4, next = None))))
p = ReverseLinkedList(List)
printLinkedList(p)
print("Interativa")
List =Node(1, next = Node(2, next=Node(3, next = Node(4, next = None))))        

reversed = ReverseLinkedListIteratively(List)
printLinkedList(reversed)