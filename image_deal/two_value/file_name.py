#!/usr/bin/env python3
#coding:UTF-8

import os

# 遍历指定目录，显示目录下的所有文件名
def eachFile(filepath):
    txt_name = open("/home/kg/Soft/python/image/capth.txt","w+")
    pathDir =  os.listdir(filepath)
    for allDir in pathDir:
        child = os.path.join('%s%s' % (filepath, allDir))
        txt_name.write(allDir+'\r\n')
    txt_name.close()

def main():
    path = "/home/kg/Soft/python/image/image/"
    eachFile(path)
if __name__ == '__main__':
    main()

