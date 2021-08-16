#Pascal's triangle

def PascalTriangleValue(row, column):
    if column ==0 or row == column:
        return 1
    if column >row:
        return
    return PascalTriangleValue(row-1, column-1) +PascalTriangleValue(row-1, column)
print(PascalTriangleValue(9,3))

def PascalTriangleList(rowIdx):
    if rowIdx ==0:
        return [1]
    prev = PascalTriangleList(rowIdx-1)
    curr = [1]
    for i in range(rowIdx):
        if i>0:
            curr.append(prev[i-1]+prev[i])
        if i==len(prev)-1:
            curr = curr+[1]
    return curr
print(PascalTriangleList(9))
    
    