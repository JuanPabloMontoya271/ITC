#Count number of 1 bits in a number


def count(n):
    counter = 0
    while n:
        counter+= n&1
        n>>=1
    return counter

count(10)
print(bin(10>>2), bin(10))