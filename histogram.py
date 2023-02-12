###############
# histgram.py #
###############

import cv2
import matplotlib.pyplot as plt

#################
# Get histogram #
#################
def get_hist(img):
	# If img is rgb color image, then it has 3 channels (B, G, R).
	# Else, img is grayscale image, then it has 1 channel.
	if len(img.shape) == 3:
		channels = 3
	else:
		channels = 1

	histogram = []
	for ch in range(channels):
		# Histogram for each channels (B, G, R).
		hist_ch = cv2.calcHist([img],[ch],None,[256],[0,256])
		histogram.append(hist_ch[:,0])

	return histogram

##################
# Draw histogram #
##################
def draw_hist(hist):
	# Channel lengths
	ch = len(hist)

	# Color of plots
	if (ch == 1):
		colors = ["black"]
		label = ["Gray"]
	else:
		colors = ["blue", "green", "red"]
		label = ["B", "G", "R"]

	# Show histogram by using matplotlib
	x = range(256)
	for col in range(ch):
		y = hist[col]
		plt.plot(x, y, color = colors[col], label = label[col])

	plt.legend()
	plt.savefig("../data/image_processing/src2/cosmobio_rgb1-unsharp-histogram.jpg")
	plt.show()

########
# Main #
########
if __name__ == "__main__":
	# Load src image
	filename = "../data/image_processing/src2/cosmobio_rgb1-unsharp.jpg"
	img = cv2.imread(filename)

	# Show src image
	cv2.imshow("src image", img)
    
	# Get histogram
	hist = get_hist(img)
    
	# Draw histogram
	draw_hist(hist)
