import numpy as np
import matplotlib.pyplot as plt
from math import radians
import pandas as pd


def radio(alpha, epsilon, theta):
    return alpha/((1-epsilon* np.cos(radians(theta))))
def vectorize (a):
    angle, mag = a[0], a[1]
    return [mag*np.cos(radians(angle)), mag*np.sin(radians(angle))]
def plot_ellipse(alpha, epsilon, step = 1):


    params = [[step*i,radio(alpha,epsilon,step*i )] for i in range(360//step)]
    nparams = [vectorize(param) for param in params]
    Xs =np.array(nparams)[:,0]
    Ys = np.array(nparams)[:,1]
    plt.title(f'Elipse: alpha: {alpha}, epsilon {epsilon}')
    plt.scatter(Xs, Ys)
    plt.plot([Xs.min(),Xs.max()],[0,0])
    plt.plot([(Xs.max()+Xs.min())/2,(Xs.max()+Xs.min())/2],[Ys.min(),Ys.max()])
    plt.show()
    df =pd.DataFrame(params, columns = ['Angulo', "Valor"])
    d2 = pd.DataFrame(nparams, columns = ['x','y'])
    df['X']=Xs
    df['Y']=Ys
    print(df)
plot_ellipse(0.6288424499,.777,1)
plot_ellipse(1,0)
plot_ellipse(1,.5)
def euc (v1, v2):
    return np.sqrt(abs((v2[1]-v1[1])**2+(v2[0]-v1[0])**2))
earth = []
neo = []
eucs = []
for i in range(1,365*1000):
    earth.append(vectorize([i,radio(1,0,i)]))
    neo.append(vectorize([365/729*i,radio(0.6288424499,.777,365/729*i)]))
    eucs.append(euc(vectorize([i,radio(1,0,i)]),vectorize([729/365*i,radio(0.6288424499,.777,729/365*i)])))
di = pd.DataFrame(earth, columns = ['EarthX', "EarthY"])
di["NEOX"], di["NEOY"] = np.array(neo)[:,0],np.array(neo)[:,1]
di["Euclidean Distance"] = eucs
di.min()


di.to_csv("Datos_obtenidos_de_la_simulación.csv")
fig = di[["Euclidean Distance"]].plot(figsize=(20, 16), fontsize=26, title = "NEO Y").get_figure()
fig.savefig("11.png")
ax1 = di.plot.scatter(x='EarthX',
                       y='EarthY',figsize=(20, 20)
                      ).get_figure()
ax1.savefig("9.png")
fig.savefig("1.png")
di["Euclidean Distance"].plot()
descriptive = di.describe()
descriptive.to_csv("Estadisticas.csv")
di.describe()
np.argmin(di["Euclidean Distance"].values)/365
