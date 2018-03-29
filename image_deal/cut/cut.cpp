#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <typeinfo>
#include <iostream>  
#include <fstream>  
#include "opencv/cxcore.h"


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

/**
 * 通过轮廓分割字符
 * @Author   KG
 * @DateTime 2018-03-22
 */
void get_outline(Mat src,Mat &img1,Mat &img2,Mat &img3,Mat &img4)
{
    Mat img_gray;
    int num,imgCount=3;
    cvtColor(src, img_gray, CV_BGR2GRAY);  
    threshold(img_gray, img_gray, 100, 255, CV_THRESH_BINARY_INV);


    vector<vector<cv::Point> > contours;  
    vector<Vec4i> hierarchy;  
    findContours(img_gray, contours, hierarchy,  
        CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE );  

    num = contours.size();
    cout<<contours.size()<<endl;
    for(int i=num-1; num>=4 && imgCount>=0;i--)  
    {  
        Rect rect = boundingRect(Mat(contours[i]));  
        // rectangle(src, rect.tl(), rect.br(),Scalar(255,0,0));  
        Mat roi = src(rect); 
        cout<< roi.cols<<endl;

        // 给分割的图片copy to img[]
        if(imgCount == 3) {
            roi.convertTo(img1, roi.type());
            // imshow("cut",img1);
        }
        if(imgCount == 2) {
            roi.convertTo(img2, roi.type());
            // imshow("cut2",img2);
        }
        if(imgCount == 1) {
            roi.convertTo(img3, roi.type());
            // imshow("cut3",img3);
        }
        if(imgCount == 0) {
            roi.convertTo(img4, roi.type());
            // imshow("cut4",img4);
        }

        // 发现有的图片过大,证明是连接的字符,从中间分割,
        // 若是第4张图片,不需要分割,因为字符只有4个.
        if(roi.cols>70)
        {
            Rect rect(0,0,roi.cols/3,roi.rows);   //创建一个Rect框，属于cv中的类，四个参数代表x,y,width,height 
            Rect rect2(roi.cols/3,0,roi.cols/3,roi.rows);
            Rect rect3(roi.cols*2/3,0,roi.cols/3,roi.rows);
            Mat image_cut1 = Mat(roi, rect);
            Mat image_cut2 = Mat(roi, rect2);
            Mat image_cut3 = Mat(roi, rect3); 

            if(imgCount == 3) {
                img1 = image_cut1.clone();
                img2 = image_cut2.clone();
                img3 = image_cut3.clone();
                
            }
            if(imgCount == 2) {
                img2 = image_cut1.clone();
                img3 = image_cut2.clone();
                img4 = image_cut3.clone();
            }
            
            imgCount -= 3;
            
        }
        else if(roi.cols>30)
        {
            Rect rect(0,0,roi.cols/2,roi.rows);   //创建一个Rect框，属于cv中的类，四个参数代表x,y,width,height 
            Rect rect2(roi.cols/2,0,roi.cols/2,roi.rows);
            Mat image_cut1 = Mat(roi, rect);
            Mat image_cut2 = Mat(roi, rect2);
            

            if(imgCount == 3) {
                img1 = image_cut1.clone();
                img2 = image_cut2.clone();
                
            }
            if(imgCount == 2) {
                img2 = image_cut1.clone();
                img3 = image_cut2.clone();
            }
            if(imgCount == 1) {
                img3 = image_cut1.clone();
                img4 = image_cut2.clone();
            }
            imgCount -= 2;
            
        }
        else if(roi.cols<10){

        }
        else
            imgCount--;

        // cout<<imgCount<<" "<<i<<endl;
        //  waitKey();
    } 

   
   
}
int main(int argc, char const *argv[])
{
    /* code */
    Mat out,out_blur,out_gaussian,out_median,img_gray;
    Mat element,element_dilate;
    char str[4];
    Mat src;
    string ImgName;//图片名(绝对路径) 
    string ReadPath; 
    string SavePath;
    string Savefile;
    std::vector<string> data;

    Mat img1;  
    Mat img2;  
    Mat img3;  
    Mat img4; 

    for(int num=0; num<300 ; num++)  
    {  
        ImgName = intToString(num);    // int转为字符串  
        ReadPath = "/home/kg/Soft/python/image/filter_image/"+ImgName + ".jpg"; 
        SavePath = "/home/kg/Soft/python/image/cut_image/";
        // Savefile
        cout<<"处理："<<ReadPath<<endl; 

        
        src = imread(ReadPath);
        Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
        // morphologyEx(src,src, MORPH_OPEN, element);
        get_outline(src,img1,img2,img3,img4);
        resize(img1,img1,Size(32,32),0,0,INTER_LINEAR);
        resize(img2,img2,Size(32,32),0,0,INTER_LINEAR);
        resize(img3,img3,Size(32,32),0,0,INTER_LINEAR);
        resize(img4,img4,Size(32,32),0,0,INTER_LINEAR);

        imshow("img1",img1);  
        // imshow("img2",out);
        // cout<<img1.cols<<"  "<<img1.rows<<endl;   
        imshow("img3",img2);  
        imshow("img4",img3);  
        imshow("img5",img4);

        // // imshow("thresholdImg", img_gray);
        imwrite(SavePath+ImgName+"_1"+".jpg",img1);
        imwrite(SavePath+ImgName+"_2"+".jpg",img2);
        imwrite(SavePath+ImgName+"_3"+".jpg",img3);
        imwrite(SavePath+ImgName+"_4"+".jpg",img4);
        imshow("ori",src);


        // waitKey();
    }
    return 0;
}