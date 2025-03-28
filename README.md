# OF_GrabCut_ContourFeatures

An OpenFrameworks application that combines interactive image segmentation using the GrabCut algorithm with advanced contour feature extraction capabilities.

![Preview](preview.png)

## Description

This application allows users to:
1. Load images via drag-and-drop
2. Interactively select regions of interest
3. Automatically segment objects using the GrabCut algorithm
4. Extract and visualize various contour features for shape analysis

The tool provides an intuitive interface for interactive foreground extraction and supports multiple advanced shape descriptor algorithms for contour analysis.

## Features

### Image Segmentation
- Interactive region selection via bounding box
- OpenCV GrabCut algorithm for foreground extraction
- Visual overlay of detected contours

### Shape Feature Extraction
The application extracts and displays various shape descriptors:

1. **Hu Moments**
   - Scale, rotation, and translation invariant moments for shape recognition

2. **Fourier Descriptors**
   - Frequency domain shape representation
   - Useful for shape matching and recognition

3. **Shape Context Features**
   - Describes shape using log-polar histograms of relative point distributions
   - Effective for shape matching with robustness to deformations

4. **Inner Distance Features**
   - Features based on geodesic distances between contour points
   - Captures the internal structure of shapes

5. **Curvature-based Features**
   - Local curvature measurements along the contour
   - Captures the smoothness and sharpness of shape boundaries

6. **Skeleton-based Features**
   - Features derived from the medial axis (skeleton) of the shape
   - Represents the topological structure of the shape

### Basic Shape Measurements
- Area
- Perimeter
- Center of mass
- Orientation angle
- Ovality (aspect ratio)
- Best-fit radius

## Usage

1. Drag and drop an image file onto the application window
2. Draw a bounding box around the object of interest by clicking and dragging
3. The application automatically segments the object using GrabCut
4. Right-click to open the feature extraction menu
5. Select a feature type to calculate and display

## Requirements

- OpenFrameworks
- ofxCv addon (for OpenCV integration)
- OpenCV (≥ 3.0)

## Installation

1. Clone this repository into your OpenFrameworks `apps/myApps/` directory:
   ```
   git clone https://github.com/bemoregt/OF_GrabCut_ContourFeatures.git
   ```

2. Install required addons:
   - ofxCv: `git clone https://github.com/kylemcdonald/ofxCv.git` into your OpenFrameworks `addons/` directory

3. Build and run using the OpenFrameworks project generator or your IDE

## Notes on Implementation

The implementation includes several sophisticated feature extraction algorithms:

- **Fourier Descriptors**: Transforms contour points into the frequency domain using FFT, providing rotation-invariant shape features
- **Shape Context**: Creates a log-polar histogram of relative point distributions to characterize shape
- **Inner Distance**: Measures distances between sampled contour points to capture internal structure
- **Curvature Features**: Calculates curvature along the contour using central difference method
- **Skeleton Features**: Extracts shape topology using skeletonization and measures branch points

## License

MIT

## Author

bemoregt