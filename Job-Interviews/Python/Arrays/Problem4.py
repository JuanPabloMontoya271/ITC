#find leaders
l1= [16,17,4,3,5,2]
def leaders(l1):
    res = [ ]
    maxval = None
    for i in range(1, len(l1)+1):
        val = l1[-i]
        if maxval is None:
            res.append(val)
            maxval = val
        else:
            if maxval <val:
                res.append(val)
                maxval = val
    return res
                    
print(leaders(l1))