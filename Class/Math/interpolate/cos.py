import numpy as np
import matplotlib.pyplot as plt
from pylab import *

u = np.arange(-5, 5.5, 0.5)
x = np.arange(-3, 4)
y = cos(u)
f = cos(x)
p = [ -2.96043648, -1.41683765, -1.01089942, -1.00470000, -0.98999250, -0.79713218, -0.41614684,  0.07004994,  0.54030231,  0.87771283,  1.00000000,  0.87771283,  0.54030231,  0.07004994, -0.41614684, -0.79713218, -0.98999250, -1.00470000, -1.01089942, -1.41683765, -2.96043648 ]

plt.plot(u,y, label='Source function')
plt.plot(u,p, label='Interpolation')
plt.scatter(x,f, c='red', label='sample')
plt.xlabel("u")
plt.ylabel("cos(u)")
plt.legend()
plt.show()