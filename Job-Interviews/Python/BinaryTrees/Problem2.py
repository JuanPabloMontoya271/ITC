class Tree:
    def __init__(self, val,left = None, right = None):
        self.val = val
        self.left = left
        self.right = right
root = Tree(4, left = Tree(3), right=Tree(5, left= Tree(4)))

#InOrderTraversal
def InOrderTraversal(root, res = []):
    if root is None:
        return res
    
    InOrderTraversal(root.left, res)
    InOrderTraversal(root.right, res)
    res.append(root.val)
    return res
print("In order:", InOrderTraversal(root))
#PreOrderTraversal
def PreOrderTraversal(root, res = []):
    if root is None:
        return res
    res.append(root.val)
    InOrderTraversal(root.left, res)
    InOrderTraversal(root.right, res)
    
    return res
print("Pre order:", PreOrderTraversal(root))
#PostOrderTraversal
def PostOrderTraversal(root, res = []):
    if root is None:
        return res
    
    InOrderTraversal(root.left, res)
    res.append(root.val)
    InOrderTraversal(root.right, res)
    
    return res
print("Post order:", PostOrderTraversal(root))
def LevelOrderTraversal(root, res =[ ]):
    if root is None:
        return res 
    queue = []
    queue.append(root)
    while len(queue)>0:
        res.append(queue[0].val)
        node = queue.pop(0)
        if node.left is not None:
            queue.append(node.left)
        if node.right is not None:
            queue.append(node.right)
    return res
print("Level order Traversal: ", LevelOrderTraversal(root))