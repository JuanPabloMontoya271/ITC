#Recursive function to compute the exponent of a number


def myPow( x: float, n: int):
    if n==0:
        return 1
    if n%2:
        if n<0:
            return myPow(x, n+1)/x
        else:
            return myPow(x, n-1)*x
        
    next_ = myPow(x, n/2)
    return next_*next_
print(myPow(5, 10))