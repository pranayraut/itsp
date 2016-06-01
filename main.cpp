#include<iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"


using namespace cv;
using namespace std;

void applyfilters(Mat);
void parametersMOG2(Ptr<BackgroundSubtractorMOG2>);
void applyfilters(Mat framenew)
{

blur(framenew,framenew,Size(3,3),Point(-1,-1));

}

int main()
{


Mat frame;
Mat mask;



Ptr<BackgroundSubtractorMOG2> pmog2;

namedWindow("original",WINDOW_NORMAL);
namedWindow("detecting",WINDOW_NORMAL);


pmog2=createBackgroundSubtractorMOG2(500,16,false);


VideoCapture Cap("4.mp4");



 if(!Cap.isOpened())
 {
     return 10;
 }


parametersMOG2(pmog2);


while(1)
{


if(!Cap.read(frame))
{
    return -1;
}

applyfilters(frame);






    pmog2->apply(frame,mask,-1);






    imshow("original",frame);
    imshow("detecting",mask);

    if(waitKey(30)==27)
        return -1;


}





return 0;

}


/*
void blobdetect()
{
SimpleBlobDetector detector;

// Detect blobs.
vector<KeyPoint> keypoints;
detector.detect( frame,keypoints);

// Draw detected blobs as red circles.
// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
Mat im_with_keypoints;
drawKeypoints( mask, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );

// Show blobs
imshow("keypoints", im_with_keypoints );

}*/




void parametersMOG2(Ptr<BackgroundSubtractorMOG2> pmog2)
{
cout<<pmog2->getBackgroundRatio()<<endl;
cout<<pmog2->getComplexityReductionThreshold ()<<endl ;
cout<<pmog2->getDetectShadows () <<endl;
cout<<pmog2->getHistory() <<endl;
cout<<pmog2->getNMixtures()<<endl;
cout<<pmog2->getShadowThreshold ()<<endl;
cout<<pmog2->getShadowValue ()<<endl;
cout<<pmog2->getVarInit ()<<endl;
cout<<pmog2->getVarMax ()<<endl;
cout<<pmog2->getVarMin () <<endl;
cout<<pmog2->getVarThreshold ()<<endl;
cout<<pmog2->getVarThresholdGen ()<<endl;

}
