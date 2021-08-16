#Compute the max depth of a binary tree
class Tree:
    def __init__(self, val,left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
root = Tree(4, left = Tree(3), right=Tree(5, left= Tree(4)))

def maxDepth(root):
    if root is None:
        return 0
    return max(maxDepth(root.left)+1, maxDepth(root.right)+1)
print(maxDepth(root))