import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

datos = np.loadtxt("datos.dat").T

fig = plt.figure()
ax = Axes3D(fig)
ax.plot_trisurf(datos[0],datos[1],datos[2])
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Potencial")
plt.savefig("resultados.png")