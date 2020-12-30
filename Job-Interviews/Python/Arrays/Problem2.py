#Get the union and intersection of two sorted arrays 

l1 = [1,2,3,4,5,6]
l2 = [4,5,6,7,9,10]
def union(l1, l2):
    i=0
    j=0
    res = []
    while i< len(l1) and j<len(l2):
        if l1[i]==l2[j]:
            res.append(l1[i])
            i+=1
            j+=1
        elif l1[i]<l2[j]:
            res.append(l1[i])
            i+=1
        else:
            res.append(l2[j])
            j+=1
    while i<len(l1):
        res.append(l1[i])
        i+=1
    while j< len(l2):
        res.append(l2[j])
        j+=1
    return res

print(union(l1,l2))

def intersection(l1,l2):
    i=0
    j=0
    res = []
    while i< len(l1) and j<len(l2):
        if l1[i]==l2[j]:
            res.append(l1[i])
            i+=1
            j+=1
        elif l1[i]<l2[j]:
            i+=1
        else:
            j+=1
    
    return res
print(intersection(l1,l2))