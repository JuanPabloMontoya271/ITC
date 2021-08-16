#Find smallest difference

def smallestDifference(arrayOne, arrayTwo):
    # Write your code here.
    arrayOne = sorted(arrayOne)
    arrayTwo = sorted(arrayTwo)
    i = 0
    j = 0
    smallest = float("inf")
    current = float("inf")
    pair = []
    while i<len(arrayOne) and j <len(arrayTwo):
    	sn = arrayOne[i]
    	fn = arrayTwo[j]
    	if sn< fn:
    		current = fn-sn 
    		i+=1
    	elif fn<sn:
    		current = sn-fn
    		j+=1
    	else:
    		return [sn, fn]
    	if current< smallest:
    		smallest = current
    		pair = [sn, fn]
    return pair

l1 = [1,3,5,2,7,5,6,3,5]
l2 = [4,3,2,5,0,6,7,5,4]
print(smallestDifference(l1,l2))