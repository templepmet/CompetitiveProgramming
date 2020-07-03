import numpy as np
import matplotlib.pyplot as plt
from pylab import *

u = np.arange(-5, 5.5, 0.5)
x = np.arange(-3, 4)
y = exp(u)
f = exp(x)
p = [ 5.97469054, 2.45171376, 0.82831160, 0.20742034, 0.04978707, 0.06713244, 0.13533528, 0.22763894, 0.36787944, 0.60373545, 1.00000000, 1.65187406, 2.71828183, 4.47520789, 7.38905610, 12.21003032, 20.08553692, 32.69360905, 52.39635273, 82.41341477, 127.01547239 ]

plt.plot(u,y, label='Source function')
plt.plot(u,p, label='Interpolation')
plt.scatter(x,f, c='red', label='sample')
plt.xlabel("u")
plt.ylabel("exp(u)")
plt.legend()
plt.show()