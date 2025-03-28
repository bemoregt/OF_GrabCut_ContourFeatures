#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseScrolled(int x, int y, float scrollX, float scrollY);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // Export functions
    void exportBinaryMask();
    void exportSegmentMask();
    void exportEdgeImage();
    void exportYoloBoxText();
    void exportYoloMaskText();
    //void handleExport(int menuIndex);
    void showStatusMessage(const string& message);
    void handleFeatureExtraction(int featureType);

    // Variables
    ofImage image;            // Main image
    ofImage overlay;          // Overlay for contours
    cv::Mat binaryMask;       // Binary mask result
    cv::Mat segmentMask;      // Segmented mask result
    cv::Mat edgeImage;        // Edge detection result
    cv::Rect bboxRect;        // Bounding box rectangle

    // Window dimensions
    int ww, hh;

    // Mouse interaction
    int startX, startY;       // Starting point of selection
    int endX, endY;          // Ending point of selection
    bool dragging;           // Is currently dragging

    // State flags
    bool maskCreated;        // Has mask been created
    bool showPopup;          // Show export popup menu
    bool hasContourInfo;     // Has contour information

    // Contour properties
    double contourArea;
    double contourPerimeter;
    cv::Point2f centerOfMass;
    double contourAngle;
    double contourOvality;
    double contourDirection;
    double bestFitRadius;
    double rectFitWidth;     // Best-fit rectangle width
    double rectFitHeight;    // Best-fit rectangle height

    // Menu related
    vector<string> menuItems;
    vector<ofRectangle> menuItemRects;
    int popupX, popupY;

    // Status message
    string statusMessage;
    float statusMessageTimer;

    // Current image file name
    string currentImageFileName;
    
private:
    int currentFeatureType = -1;  // Current selected feature type
    vector<double> huMoments;
    vector<double> fourierDescriptors;
    vector<double> shapeContextFeatures;
    vector<double> innerDistanceFeatures;
    vector<double> curvatureFeatures;
    vector<double> skeletonFeatures;
    
    vector<double> calculateFourierDescriptors(const vector<cv::Point2f>& contour, int numDescriptors);
    vector<double> calculateShapeContext(const vector<cv::Point>& contour);
    vector<double> calculateInnerDistance(const vector<cv::Point>& contour);
    vector<double> calculateCurvature(const vector<cv::Point>& contour);
    vector<double> calculateSkeletonFeatures(const cv::Mat& binaryMask);
};