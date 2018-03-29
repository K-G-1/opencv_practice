# -*- coding:utf-8 -*-

import urllib
import time 

for i in range(1000,1010):
    string = "http://211.86.128.141/jwweb//sys/ValidateCode.aspx?t="
    index = str(i)
    file = index + '.jpg'
    url = (string+index)
    print (url)
    #time.sleep(1)
    urllib.urlretrieve(url,file)
