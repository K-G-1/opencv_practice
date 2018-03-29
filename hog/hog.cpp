#include "opencv2/core/core.hpp"    
#include "opencv2/objdetect.hpp"  
#include "opencv2/core/cuda.hpp"  
#include "opencv2/highgui/highgui.hpp"    
#include "opencv2/imgproc/imgproc.hpp"    
#include "opencv2/video/video.hpp"    
#include "opencv2/ml.hpp"  
#include "opencv2/opencv.hpp"  
#include <opencv2/objdetect/objdetect.hpp>    
#include <opencv2/imgcodecs.hpp>  
#include <stdlib.h>  
#include <time.h>  
#include <algorithm>  
#include <math.h>  
#include <iostream>    
#include <vector>  
#include <fstream>  
#include <cstdlib>  

using namespace std;  
using namespace cv;  
using namespace cv::ml; 



int main(int argc, char const *argv[])
{
    //检测窗口(64,128),块尺寸(16,16),块步长(8,8),cell尺寸(8,8),直方图bin个数9  
    HOGDescriptor hog(Size(64,128),Size(16,16),Size(8,8),Size(8,8),9);//HOG检测器，用来计算HOG描述子的  
    int DescriptorDim;//HOG描述子的维数，由图片大小、检测窗口大小、块大小、细胞单元中直方图bin个数决定  

    Mat src = imread("people-1.jpg");//读取图片  
    src = src(Rect(16,16,64,128));//将96*160的INRIA正样本图片剪裁为64*128，即剪去上下左右各16个像素  
    vector<float> descriptors;//HOG描述子向量  
    hog.compute(src,descriptors,Size(8,8));//计算HOG描述子，检测窗口移动步长(8,8)  
    //  
    cout<<"描述子维数："<<descriptors.size()<<endl;  

    //处理第一个样本时初始化特征向量矩阵和类别矩阵，因为只有知道了特征向量的维数才能初始化特征向量矩阵  
     
    DescriptorDim = descriptors.size();//HOG描述子的维数  
    

    Mat img = imread("people-2.jpg");
    vector< Rect > detections;  
    vector< double > foundWeights;
    hog.detectMultiScale(img, detections, foundWeights); 
    for (size_t j = 0; j < detections.size(); j++)  
    {  
        if (foundWeights[j] < 0.5) continue; //清楚权值较小的检测窗口  
        Scalar color = Scalar(0, foundWeights[j] * foundWeights[j] * 200, 0);  
        rectangle(img, detections[j], color, img.cols / 400 + 1);  
    }   
    imshow("people", img);
    waitKey(); 
     
    return 0;
}