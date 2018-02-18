# two_value 

转化为灰度值，才能二值化

## two_value
### 固定阈值
>threshold(输入图像，输出图像，阈值,替换值，[0~5])

0: THRESH_BINARY  当前点值大于阈值时，取Maxval,也就是第四个参数，下面再不说明，否则设置为0  <br>
1: THRESH_BINARY_INV 当前点值大于阈值时，设置为0，否则设置为Maxval                     <br>
2: THRESH_TRUNC 当前点值大于阈值时，设置为阈值，否则不改变<br>                             
3: THRESH_TOZERO 当前点值大于阈值时，不改变，否则设置为0<br>
4: THRESH_TOZERO_INV  当前点值大于阈值时，设置为0，否则不改变<br>

### 自适应阈值化
>void cv::adaptiveThreshold(  
        cv::InputArray src, // 输入图像  
        cv::OutputArray dst, // 输出图像  
        double maxValue, // 向上最大值  
        int adaptiveMethod, // 自适应方法，平均或高斯  
        int thresholdType // 阈值化类型  
        int blockSize, // 块大小  
        double C // 常量    
        );

thresholdType:cv::ADAPTIVE_THRESH_MEAN_C（平均）cv::ADAPTIVE_THRESH_GAUSSIAN_C（高斯）
thresholdType:THRESH_BINARY / THRESH_BINARY_INV
blockSize:奇数

