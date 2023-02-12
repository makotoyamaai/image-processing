# Image processing
> Ubuntu 22.04 LTS<br>
> In here, I used two images from the following website.<br>
> https://www.cosmobio.co.jp/product/detail/products_scr_20081010_01.asp?entry_id=5817<br>
![image grayscale](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1.jpg)
![image bgr](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1.jpg)
## unsharp.cpp
> Create unsharp image<br>
![image grayscale unsharp](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1-unsharp.jpg)
![image bgr unsharp](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp.jpg)
## histogram.py
> Create histogram for grayscale or color image<br>
![image grayscale unsharp histogram](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1-unsharp-histogram.jpg)<br>
![image bgr unsharp histogram](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-histogram.jpg)
## region1.cpp
> Draw box on image by using mouse and show axis of box (for check unsharpness)
## region2.cpp
> Clip box by using axis from region1.cpp (for check unsharpness)<br>
![image grayscale unsharp region1](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1-unsharp-region.jpg)
![image bgr_unsharp region](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-region.jpg)
## extraction1.cpp
> Create binary image from grayscale image by using trackbar<br>
![image grayscale unsharp to binary](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1-unsharp-mask.jpg)<br>
![image grayscale unsharp to binary screenshot](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/example_gray.png)
## extraction2.cpp
> Create binary image from BGR color image by using trackbar<br>
![image bgr unsharp to binary blue](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask1.jpg)
![image bgr unsharp to binary green](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask2.jpg)
![image bgr unsharp to binary screenshot](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/example_rgb.png)
## extraction3.cpp
> Create filtering image (mask image + unsharp image)<br>
![image bgr unsharp to binary mask blue](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask1-filtering.jpg)
![image bgr unsharp to binary mask green](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask2-filtering.jpg)
## hist3d.py
> Create 3d brightness histogram of filtering image (grayscaling)<br>
![image bgr unsharp to binary mask blue 3dhist](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask1-filtering-hist3d.png)
![image bgr unsharp to binary mask green 3dhist](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask2-filtering-hist3d.png)
## ed.cpp
> Dilate and erode binary image<br>
![image grayscale to binary dilate and erode](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1-unsharp-de.jpg)
## contour.cpp
> Detect contours<br>
> Draw bounding rectangles and contours.<br>
![image grayscale detect contours](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src1/cosmobio_gray1-unsharp-de-rect.jpg)
![image bgr detect contours blue](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask1-rect.jpg)
![image bgr detect contours green](https://github.com/makotoyamaai/image-processing/blob/main/data/image_processing/src2/cosmobio_rgb1-unsharp-mask2-rect.jpg)
## count.cpp
> Count cells on your binary image
