# Image Proc

The ImageProc benchmark suite includes a variety of image processing operations to evaluate the performance and capabilities of different algorithms. These benchmarks cover fundamental operations such as morphology and line extraction, as well as advanced techniques like non-photorealistic rendering and text skewness correction. Image processing is essential in fields such as computer vision, graphics, and photography, where it is used to enhance, analyze, and manipulate images.

|          TEST           |    STATUS    |
| ------------------------| -------------|
| Morphology Operation    | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Line Extraction         | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Cloning                 | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Delaunay Triangulation & Voronoi Tessellation     | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Line Segment Detection   | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Non-Photorealistic Rendering  | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Text Skewness Correction      | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|
| Watershed  | ![Static Badge](https://img.shields.io/badge/Test-%20Succeeded-%20green)|

## Morphology Operation

A set of operations that process images based on shapes. Morphological operations apply a *structuring element* to an input image and generate an output image.

 The most basic morphological operations are: Erosion and Dilation. They have a wide array of uses, i.e. :
    -   Removing noise
    -   Isolation of individual elements and joining disparate elements in an image.
    -   Finding of intensity bumps or holes in an image

### Dilation

-   This operations consists of convolving an image \f$A\f$ with some kernel (\f$B\f$), which can have any shape or size, usually a square or circle.
-   The kernel \f$B\f$ has a defined *anchor point*, usually being the center of the kernel.
-   As the kernel \f$B\f$ is scanned over the image, we compute the maximal pixel value overlapped by \f$B\f$ and replace the image pixel in the anchor point position with that maximal value. As you can deduce, this maximizing operation causes bright regions within an image to "grow" (therefore the name *dilation*).
-   The dilatation operation is: \f$\texttt{dst} (x,y) =  \max _{(x',y'):  \, \texttt{element} (x',y') \ne0 } \texttt{src} (x+x',y+y')\f$

### Erosion

-   This operation is the sister of dilation. It computes a local minimum over the area of given kernel.
-   As the kernel \f$B\f$ is scanned over the image, we compute the minimal pixel value overlapped by \f$B\f$ and replace the image pixel under the anchor point with that minimal value.
-   The erosion operation is: \f$\texttt{dst} (x,y) =  \min _{(x',y'):  \, \texttt{element} (x',y') \ne0 } \texttt{src} (x+x',y+y')\f$




