#Sum of nodes depths

class Tree:
    def __init__(self, val,left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
root = Tree(4, left = Tree(3), right=Tree(5, left= Tree(4)))

def SumDepths(root, d):
    if root is None:
        
        return 0
    
    result =  d+ SumDepths(root.left, d+1)+ SumDepths(root.right,d+1)
    
    return result

print(SumDepths(root, 0))