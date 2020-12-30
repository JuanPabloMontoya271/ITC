#Find successor in a binary tree

#Solution 1 
#Time: O(n),
#Space: O(n)
class Tree:
    def __init__(self, val,left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
root = Tree(4, left = Tree(3), right=Tree(5, left= Tree(4)))
node = Tree(3)
def findSuccessor(tree, node):
    # Write your code here.
	order = inorderTraversal(tree)
	for idx, curr in enumerate(order):
		if curr != node:
			continue
		if idx == len(order)-1:
			return None
		
		return order[idx+1] 
	
	
def inorderTraversal(tree, order = [ ]):
    if tree is None:
        return order
	
    inorderTraversal(tree.left, order)
    order.append(tree)
    inorderTraversal(tree.right, order)
		
	
    return order

print(findSuccessor(root, root))