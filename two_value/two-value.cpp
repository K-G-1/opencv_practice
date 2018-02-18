/**
 * 二值化
 * author :k.g.
 * 
 */
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
    Mat src = imread("2.jpg");
    Mat src1 = src.clone();

    imshow("Origin",src);
    //display original image
    //
    Mat edge,gray,dst;
    cvtColor(src1,gray,COLOR_BGR2GRAY);             //转化为灰度值 
    // imshow("gray",gray);                         //显示灰度图
    threshold(gray,edge, 70, 255,THRESH_BINARY);    //固定阈值
    adaptiveThreshold(gray,dst,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,333,0);

    imshow("th",edge);
    imshow("ad_th",dst);
    waitKey(0);
    return 0;
}