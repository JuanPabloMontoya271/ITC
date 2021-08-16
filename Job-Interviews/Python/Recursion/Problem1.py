#Problem 1
#Compute the factorial (n!) of a number using recursion
import sys
def factorial(n):

    if n ==1:
        return 1
    return n*factorial(n-1)
if __name__ == "__main__":
    try:
        n = int(input("Ingrese un numero: "))
        print(factorial(n))
    except Exception as e:
        print(e)
        sys.exit()

    
