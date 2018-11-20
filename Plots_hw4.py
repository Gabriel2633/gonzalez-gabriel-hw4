import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt

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


plt.savefig(a1,a2)
plt.savefig(b1,b2)
plt.savefig(c1,c2)
plt.savefig(d1,d2)
plt.savefig(e1,e2)
plt.savefig(f1,f2)
plt.savefig(g1,g2)
plt.savefig(h1,h2)














