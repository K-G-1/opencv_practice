/**
 * 二值化
 * author :k.g.
 * 
 */
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <typeinfo>
#include <iostream>  
#include <fstream>  


#ifndef PosSamNO
#define PosSamNO 1010
#endif

using namespace cv;
using namespace std;


string intToString(int v)  
{  
    char buf[32] = {0};  
    snprintf(buf, sizeof(buf), "%u", v);  
  
    string str = buf;  
    return str;  
} 

int main()
{
    Mat edge,gray;
    char str[4];
    Mat src;
    string ImgName;//图片名(绝对路径) 
    string ReadPath; 
    string SavePath;
    ifstream finPos("capth.txt");//正样本图片的文件名列表  


    
    for(int num=1000; num<PosSamNO && getline(finPos,ImgName); num++)  
    {  
        ImgName = intToString(num);    // int转为字符串  
        ReadPath = "/home/kg/Soft/python/image/test_image/"+ImgName + ".jpg"; 
        SavePath = "/home/kg/Soft/python/image/two_value_image/"+ImgName + ".jpg";
        cout<<"处理："<<SavePath<<endl; 
       
        src = imread(ReadPath);//读取图片  
        cvtColor(src,gray,COLOR_BGR2GRAY);
        threshold(gray,edge, 200, 255,THRESH_BINARY);
        imshow("Origin",edge);
        imwrite(SavePath,edge);
        waitKey(1);
    }
    
    return 0;
}