from pylab import *
from numpy import NaN
from mendel import mendel
 
X = arange(-2, .5, .002)
Y = arange(-1,  1, .002)
Z = zeros((len(Y), len(X)))
 
for iy, y in enumerate(Y):
	print (iy, "of", len(Y))
	for ix, x in enumerate(X):
		Z[iy,ix] = mendel(x, y)
 
imshow(Z, cmap = plt.cm.prism, interpolation = 'none', extent = (X.min(), X.max(), Y.min(), Y.max()))
xlabel("Re(c)")
ylabel("Im(c)")
savefig("mandelbrot_python.svg")
show()