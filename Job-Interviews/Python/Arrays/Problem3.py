#Find the missing number on an array from 1-n inclusive


#First solution using array sum n(n+1)/2
l1 = [1,2,4,5,6,7]
def findNumber(l1):
    n = len(l1)+1
    suma = n*(n+1)/2
    for i in l1:
        suma-=i
    return suma
print(findNumber(l1))
#The solution using XOR
def xorSolution(l1):
    x1 = l1[0]
    x2 = 1
    n = len(l1)
    for i in range(x2+1, n+2):
        x2^=i
    for i in range(1, len(l1)):
        x1^=l1[i]
    return x2^x1
print(xorSolution(l1))