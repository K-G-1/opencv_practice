#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <typeinfo>
#include <iostream>  
#include <fstream>  
#include "opencv/cxcore.h"
#include "/home/kg/Soft/python/image/floodFill/Image.h"

#ifndef PosSamNO
#define PosSamNO 1010
#endif

using namespace cv;
using namespace std;

static const int BLACK = 0;
static const int WHITE = 255;
const int OFFSET = 7;

string intToString(int v)  
{  
    char buf[32] = {0};  
    snprintf(buf, sizeof(buf), "%u", v);  
  
    string str = buf;  
    return str;  
} 


int main(int argc, char const *argv[])
{
    /* code */
    Mat out,out_blur,out_gaussian,out_median,out_double;
    Mat element,element_dilate;
    char str[4];
    Mat src;
    string ImgName;//图片名(绝对路径) 
    string ReadPath; 
    string SavePath;
    std::vector<string> data;



    for(int num=1000; num<PosSamNO ; num++)  
    {  
        ImgName = intToString(num);    // int转为字符串  
        ReadPath = "/home/kg/Soft/python/image/two_value_image/"+ImgName + ".jpg"; 
        SavePath = "/home/kg/Soft/python/image/filter_image/"+ImgName + ".jpg";
        cout<<"处理："<<ReadPath<<endl; 

        Image img;
        img.LoadImg(ReadPath);
        img.toGray();
        img.Binarization();
        img.NaiveRemoveNoise(3);
        
        img.ContoursRemoveNoise(5.0f);
        img.SelfDilate(2);
        data.clear();
 
        img.ShowInWindow(ImgName);

        img.SaveImg(SavePath);
       
    }
    return 0;
}