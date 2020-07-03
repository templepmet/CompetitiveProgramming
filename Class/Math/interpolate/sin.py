import numpy as np
import matplotlib.pyplot as plt
from pylab import *

u = np.arange(-5, 5.5, 0.5)
x = np.arange(-3, 4)
y = sin(u)
f = sin(x)
p = [-3.67145379, -0.96083545,  0.10285014,  0.20642253, -0.14112001, -0.58637287, -0.90929743, -1.00099335, -0.84147098, -0.47742365,  0.00000000,  0.47742365,  0.84147098,  1.00099335,  0.90929743,  0.58637287,  0.14112001, -0.20642253, -0.10285014,  0.96083545,  3.67145379 ]

plt.plot(u,y, label='Source function')
plt.plot(u,p, label='Interpolation')
plt.scatter(x,f, c='red', label='sample')
plt.xlabel("u")
plt.ylabel("sin(u)")
plt.legend()
plt.show()