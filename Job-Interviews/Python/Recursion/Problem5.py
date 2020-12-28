#Search a binary Tree with BFS recursively


class Tree:
    def __init__(self, val,left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
# root = Tree(2, left= Tree(1, left = Tree(0)), right = Tree(6, left = Tree(4), right = Tree(8)), right = Tree(4, left = Tree(2), right = Tree(6)))

root = Tree(4, left = Tree(3), right=Tree(5))
def BFS(root, num):
    if root is None:
        return None
    if root.val ==num:
        return True
    if root.val<num:
        return BFS(root.right, num)
    else:
        return BFS(root.left, num)
    
print(BFS(root,5)) 