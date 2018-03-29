#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <typeinfo>
#include <iostream>  
#include <fstream>  


#ifndef PosSamNO
#define PosSamNO 300
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
 
Mat Filter_remove_noise(string path)
{
    Mat src = imread(path);

    int i,j,m,n,nValue,nCount;  
    int nWidth = getWidth();  
    int nHeight = getHeight();  
    //set boundry to be white  
    for (i = 0; i < nWidth ; ++i)  
    {  
        setPixel(i,0,WHITE);  
        setPixel(i,nHeight-1,WHITE);  
    }  
    for (i = 0; i < nHeight ; ++i)  
    {  
        setPixel(0,i,WHITE);  
        setPixel(nWidth-1,i,WHITE);  
    }
    //if the neighbor of a point is white but it is black, delete it  
    for (j = 1; j < nHeight; ++j)  
        for (i = 1; i < nWidth; ++i)  
        {  
            nValue = getPixel(i,j);  
            if ( !nValue )  
            {  
                nCount = 0;  
                for (m = i-1; m <= i+1; ++m)  
                    for (n = j-1; n <= j+1; ++n)  
                    {  
                        if( !getPixel(m,n) )  
                            nCount++;  
                    }  
                if (nCount <= pNum)  
                    setPixel(i,j,WHITE);  
            }  
            else  
            {  
                nCount = 0;  
                for (m = i-1; m <= i+1; ++m)  
                    for (n = j-1; n <= j+1; ++n)  
                    {  
                        if( !getPixel(m,n) )  
                            nCount++;  
                    }  
                if (nCount >= 7)  
                    setPixel(i,j,BLACK);  
            }  
        } 

    return src
}

int main(int argc, char const *argv[])
{
    /* code */
    Mat out,out_blur,out_gaussian,out_median,out_double;
    Mat element,element_dilate;
    Mat src1;
    char str[4];
    Mat src;
    string ImgName;//图片名(绝对路径) 
    string ReadPath; 
    string SavePath;


      

    for(int num=0; num<PosSamNO ; num++)  
    {  
        ImgName = intToString(num);    // int转为字符串  
        ReadPath = "/home/kg/Soft/python/image/two_value_image/"+ImgName + ".jpg"; 
        SavePath = "/home/kg/Soft/python/image/filter_image/"+ImgName + ".jpg";
        cout<<"处理："<<ReadPath<<endl; 

        src = imread(ReadPath);
        element_dilate = getStructuringElement(MORPH_ELLIPSE,Size(2,2));
        
        dilate(src,out_blur,element_dilate);
        imshow("deal_1",out_blur);    
        imshow("ori",src);
        imwrite(SavePath,out_blur);

        src1 = Filter_remove_noise(ReadPath);
        imshow("filter",src1);
        
    }
    return 0;
}