#include "mainActivityJNI.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

#include <vector>

cv::Ptr<cv::Feature2D> detector;

/*
 * Class:     ph_edu_dlsu_akazefeaturesjni_MainActivity
 * Method:    findAKAZEFeatures
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_ph_edu_dlsu_akazefeaturesjni_MainActivity_findAKAZEFeatures
  (JNIEnv *pEnv, jobject, jlong mGray, jlong mRGBA){
  
  	cv::Mat& mGr  = *(cv::Mat*)mGray;
    cv::Mat& mRgb = *(cv::Mat*)mRGBA;
    
    std::vector<cv::KeyPoint> v;

	if (detector == NULL)
    	detector = cv::AKAZE::create();
    
    detector->detect(mGr, v, cv::Mat());
    

    for( unsigned int i = 0; i < v.size(); i++ )
    {
        const cv::KeyPoint& kp = v[i];
        cv::circle(mRgb, cv::Point(kp.pt.x, kp.pt.y), 10, cv::Scalar(0,255,0,255));
    }
 
  }
