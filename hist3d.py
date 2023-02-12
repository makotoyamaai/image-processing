#############
# hist3d.py #
#############

import matplotlib.pyplot as plt
import numpy as np
import cv2
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.cm as cm

image = cv2.imread("../data/image_processing/src2/cosmobio_rgb1-unsharp-mask1-filtering.jpg", 0)
height, width = image.shape[:2]

x = np.linspace(0, width-1, width)
y = np.linspace(0, height-1, height)
x , y = np.meshgrid(x, y)

z = image[y.astype(np.int32), x.astype(np.int32)]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter3D(np.ravel(x), np.ravel(y), np.ravel(z), s=10, marker='.')
ax.set_title("hist3d")
plt.savefig("../data/image_processing/src2/cosmobio_rgb1-unsharp-mask1-filtering-hist3d.png")
plt.show()
