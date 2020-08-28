GlowScript 3.0 VPython
from visual import *


print(f"{cos(radians(90)):.3f}")
def radio(alpha, epsilon, theta):
    return alpha/((1-epsilon* cos(radians(theta))))
def vectorize (a):
    angle, mag = a[0], a[1]
    return [mag*cos(radians(angle)), mag*sin(radians(angle))]
def euc(vector, vector2):
    return sqrt(abs((vector[0]-vector2[0])**2+(vector[1]-vector2[1])**2))
 
earth = sphere(pos = vector(0,0,0), radius = .12, color = vector(0, 1, 255))
neo= sphere(pos = vector(0,0,0), radius = .1, color = vector(255,10, 1))
sun = sphere (pos = vector(0,0,0), radius = .2, color = vector(230,2, 0))

params =[]
for i in range(360):
    a=vectorize([i, radio(0.6288424499,.777,i )])
    b=vectorize([i, radio(1,0,i )])
    params.append(a)
    sphere(pos = vector(a[0]-2.82+.354,a[1],0), radius = .0125, color = vector(255,255,255))
    sphere (pos = vector(b[0],b[1],0), radius = .0125, color = vector(255,255,255))
    
#nparams = [vectorize(param) for param in params]
distances = 0
min_distance = [0,100]
max_distance = [0,0]
while True:
    rate(2000)
    #0.6288424499
    vector_ = vectorize((365/729*i,radio(0.6288424499,.777,.5*i)))
    vector_2 = vectorize((i,radio(1,0,24/365*i)))
    vector_[0]=vector_[0]-2.82+.354
    distance =euc(vector_, vector_2)
    min_distance = [i, distance] if distance <min_distance[-1] else min_distance
    max_distance = [i, distance] if distance >max_distance[-1] else max_distance
    print(f"Day: {i} ")
    print(f"NEO:{vector_},\nEARTH:{vector_2}")
    print(f"Euclidean distance: {distance}")
    print(f"Average Distance: {distances/i},\nmin:{min_distance}, max: {max_distance} ")
    
    earth.pos.x = vector_2[0]
    earth.pos.y = vector_2[1]
    neo.pos.x = vector_[0]
    neo.pos.y = vector_[1]
    
    distances+=distance
    i+=1
