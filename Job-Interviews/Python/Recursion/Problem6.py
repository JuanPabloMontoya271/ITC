#Compute Fibonacci number recursively
cache = {}
def fibonacci(n):
    
    if n in cache:
        return cache[n]
    else:
        if n <2:
            return 1
        else:
            result = fibonacci(n-1)+ fibonacci(n-2)
        cache[n]= result
        return result
print(fibonacci(6))