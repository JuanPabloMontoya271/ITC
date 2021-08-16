class Node:
    def __init__(self, name , children = []):
        self.name = name 
        self.children  = children
    def addChild(self, child):
        self.children.append(child)
    

graph = Node("A", children = [Node("B", children=[Node("C")]), Node("D", children = [Node("E", children=[Node("F")])])])

def DFS(root, res = []):
    if root is None:
        return
    res.append(root.name)
    for child in root.children:
        
        DFS(child, res)
        
    return res        

print(DFS(graph))

def BFS (root, res = []): 
    if root is None:
        return res
    queue = [root]

    while len(queue)>0:
        res.append(queue[0].name)
        node = queue.pop(0)
        for child in node.children:
            queue.append(child)
    return res
print(BFS(graph))