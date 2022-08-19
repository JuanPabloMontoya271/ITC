from math import sqrt
import threading 
from tqdm import tqdm
from time import time 
class ThreadWithResult(threading.Thread):
    def __init__(self, group=None, target=None, name=None, args=(), kwargs={}, *, daemon=None):
        def function():
            self.result = target(*args, **kwargs)
        super().__init__(group=group, target=function, name=name, daemon=daemon)

def isPrime(n):
 
    # Corner case
    if (n <= 1):
        return False
 
    # Check from 2 to sqrt(n)
    for i in range(2, int(sqrt(n))+1):
        if (n % i == 0):
            return False
 
    return True

def prime_logic(n, lower, upper):

    for i in range(lower, upper):
        
        if (n%i == 0):
            return False
    return True


def isPrimeConcurrent(n):
    if (n <= 1):
        return False
    lower = 2
    upper = int(sqrt(n))+1
    n_threads = 10
    spacing = (upper-lower)//n_threads
    threads = []
    # Check from 2 to sqrt(n)
    for i in range(n_threads):
        c_lower = 2+ (i*spacing)
        c_upper = 2 + (i+1)*spacing
        x = ThreadWithResult(target = prime_logic, args = (n, c_lower, c_upper))
        x.start()
        threads.append(x)
    total = True
    for index, thread in enumerate(threads):
        thread.join()
        total = total  and (thread.result)


    return True
def concurrent_primes(i, j):
    for i in range(0, 5000000):
        isPrimeConcurrent(i)
    return     

def sumar_primos(i, j):
    total = 0
    for idx in (range(i, j)):
        total += idx if isPrime(idx) else 0
    return total


def concurrent_sum(ground_truth):
    
    threads = []
    num_threads = 3
    target = 5000000
    spacing = target//num_threads
    initial_time = time()
    for thread in range(num_threads):
        lower_bound = thread*spacing
        upper_bound = spacing * (thread+1)
        promise = ThreadWithResult(target = sumar_primos, args =(lower_bound, upper_bound))
        promise.start()
        threads.append(promise)
    total = 0
    for index, thread in enumerate(threads):
        thread.join()
        total += (thread.result)
    esIgual = "" if (total == ground_truth) else "no"
    tiempo = time() - initial_time
    print(f"Total Paralelo con {num_threads} threads : {total} {esIgual} es igual a {ground_truth}")
    print(f"Tiempo : {tiempo}")
    return tiempo

def sequential_sum(ground_truth):
    initial_time = time()
    res = (sumar_primos(0, 5000000))
    esIgual = "" if (res == ground_truth) else "no"
    tiempo = time() - initial_time
    print(f"Total Paralelo con 1 threads : {res} {esIgual} es igual a {ground_truth}")
    print(f"Tiempo : {tiempo}")
    return tiempo

def main():
    ground_truth = 838596693108
    T1 = sequential_sum(ground_truth)
    T5 = concurrent_sum(ground_truth)
    print(f"S5 = T1/T5 = {T1/T5}")
    # concurrent_primes(0, 5000)

if __name__ == "__main__":
    main()

