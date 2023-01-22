# Image processing
> Ubuntu 22.04 LTS<br>
> In here, I used two images from the following website.<br>
> https://www.cosmobio.co.jp/product/detail/products_scr_20081010_01.asp?entry_id=5817<br>
![image grayscale](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio3.jpg)
![image bgr](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2.jpg)
## unsharp.cpp
> Create unsharp image<br>
![image grayscale unsharp](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio3-unsharp.jpg)
![image bgr unsharp](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp.jpg)
## histogram1.cpp
> Create histogram for grayscale image<br>
![image grayscale unsharp histogram](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio3-unsharp-hist.jpg)
## histogram2.cpp
> Create histogram for BGR color image<br>
![image bgr unsharp histogram](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp-hist.jpg)
## region1.cpp
> Draw box on image by using mouse and show axis of box (for check unsharpness)
## region2.cpp
> Clip box by using axis from region1.cpp (for check unsharpness)<br>
![image bgr unsharp roi](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp-roi.jpg)
## extraction1.cpp
> Create binary image from grayscale image by using trackbar<br>
![image grayscale unsharp to binary](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio3-unsharp_mask_binary.jpg)<br>
![image grayscale unsharp to binary screenshot](https://github.com/makotoyamaai/image-processing/blob/main/images/example2.png)
## extraction2.cpp
> Create binary image from BGR color image by using trackbar<br>
![image bgr unsharp to binary blue](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp_mask_binary.jpg)
![image bgr unsharp to binary green](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp_mask_binary2.jpg)
![image bgr unsharp to binary screenshot](https://github.com/makotoyamaai/image-processing/blob/main/images/example1.png)
## extraction2-1.cpp
> Create mask image<br>
![image bgr unsharp to binary mask blue](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp_mask_rgb.jpg)
![image bgr unsharp to binary mask green](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp_mask_rgb2.jpg)
## ed.cpp
> Dilate and erode binary image<br>
![image grayscale to binary dilate and erode](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio3-unsharp_mask_binary_ed.jpg)
## contour.cpp
> Detect contours<br>
> Draw bounding rectangles and contours.<br>
![image grayscale detect contours](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio3-unsharp_mask_binary_ed_rect.jpg)
![image bgr detect contours blue](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp_mask_binary_rect.jpg)
![image bgr detect contours green](https://github.com/makotoyamaai/image-processing/blob/main/images/cosmobio2-unsharp_mask_binary2_rect.jpg)
## count.cpp
> Count cells on your binary image
