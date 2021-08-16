#Find duplicate number in array of integers bounding 1 and n being n the lenght of the array

#Most optimal solution: 
#Time: O(n)
#Space: O(1)
def firstDuplicateValue(array):
    
    for i in range(len(array)):
        absValueIndex = abs(array[i])-1
		if array[absValueIndex]<0:
			return abs(array[i])
		else:
			array[absValueIndex]*=-1
	return -1

#Solution using sets:
#Time: O(n)
#Space: O(n)

def firstDuplicateValue(array):
    # Write your code here.
	seen  = set()
	for value in (array):
		if value in seen:
			return value
		else:
			seen.add(value)
	
    return -1