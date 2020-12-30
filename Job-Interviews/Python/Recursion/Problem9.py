#Towers of Hanoi: Really nice solution recursively

steps = []
def towers_of_hanoi(n, start, end ):
    #n = number of disks
    #start: number of starting position
    #end: number of end position
    if n ==1:
        steps.append(pm(start, end))
    else:
        other = 6-(start+end)
        towers_of_hanoi(n-1, start, other)
        steps.append(pm(start, end))
        towers_of_hanoi(n-1, other, end)


def pm (start, end):
    return f"{start} -> {end}"
towers_of_hanoi(3, 1, 3)

print(steps)