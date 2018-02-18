/**
 * canny 边缘检测
 * author :k.g.
 * 
 */
// #include <opencv2/openv.hpp>
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
    Mat dst,edge,gray;
    dst.create(src1.size(),src1.type());
    cvtColor(src1,gray,COLOR_BGR2GRAY); //转化为灰度值
    blur(gray,edge,Size(3,3));          //滤波 用3×3的核
    Canny(edge,edge,30,100,3);          //开始滤波
    // dst = Scalar::all(0);
    // src1.copyTo(dst,edge);
    imshow("Canny",edge);

    waitKey(0);
    return 0;
}