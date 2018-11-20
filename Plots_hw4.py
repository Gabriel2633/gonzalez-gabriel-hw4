import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

a=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_10grados.txt")
a1=a[:,1]
a2=a[:,2]

b=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_40grados.txt")
b1=b[:,1]
b2=b[:,2]

c=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_30grados.txt")
c1=c[:,1]
c2=c[:,2]

d=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_20grados.txt")
d1=d[:,1]
d2=d[:,2]

e=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_45grados.txt")
e1=e[:,1]
e2=e[:,2]

f=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_50grados.txt")
f1=f[:,1]
f2=f[:,2]

g=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_60grados.txt")
g1=g[:,1]
g2=g[:,2]

h=np.genfromtxt("/Users/GabrielGonzalez/Desktop/proyectil_70grados.txt")
h1=h[:,1]
h2=h[:,2]


plt.plot(a1,a2)
plt.plot(b1,b2)
plt.plot(c1,c2)
plt.plot(d1,d2)
plt.plot(e1,e2)
plt.plot(f1,f2)
plt.plot(g1,g2)
plt.plot(h1,h2)
plt.savefig("resultados.pdf")

aa=np.genfromtxt("/Users/GabrielGonzalez/Desktop/fijo_0.txt")
bb=np.genfromtxt("/Users/GabrielGonzalez/Desktop/fijo_1000.txt")
cc=np.genfromtxt("/Users/GabrielGonzalez/Desktop/fijo_2000.txt")
dd=np.genfromtxt("/Users/GabrielGonzalez/Desktop/abierta_0.txt")
ee=np.genfromtxt("/Users/GabrielGonzalez/Desktop/abierta_1000.txt")
ff=np.genfromtxt("/Users/GabrielGonzalez/Desktop/abierta_2000.txt")

w=np.linspace(1,50,50)

fig = plt.figure()
ax = Axes3D(fig)
ax.plot(w,w,aa)
ax.plot(w,w,bb)
ax.plot(w,w,cc)
ax.plot(w,w,dd)
ax.plot(w,w,ee)
ax.plot(w,w,ff)
plt.title("Grafica En 3D de X , Y y Z")
plt.xlabel("X")
plt.ylabel("Y")
plt.savefig("resultados.pdf")
