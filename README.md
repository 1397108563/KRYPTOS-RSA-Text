# KRYPTOS-RSA-Text
基于KRYPTOS &amp; RSA的非对称文本加密传输
## 依赖
`g++`
## 用法 
### Linux
`make`  
`cd build`  
`./key`  
然后就可以进行加密解密了  
加密`./encoder`  
解密`./decoder`  
### Windows
先去  
`https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z`  
下载mingw-w64，将bin目录添加到PATH。  
然后运行`make.bat`  
之后可以在`build`目录下找到可执行文件  
**分享软件需要与DLL一起分享**
使用过程与Linux相同。  
## 文件
`RSA-ed.txt`是经过RSA加密的内容，其中原始内容的每一个字节以“/”作分割，可以在文件内查找该字符并修改  
**不可修改为空格，会影响程序的文件读取功能**  
`output.txt`是使用私钥解密过后的内容
# 推荐使用方法
##  建立可信通话渠道
1.通话发起者生成一对公私钥，并将公钥的哈希值加密后发送给接收者。  
2.接收者收到公钥后，使用公钥解密（此时需要将发起者的pub修改为pri进行解密），使用解密后的哈希值验证包是否被篡改。  
3.验证通过后，接收者生成一对公私钥，并将公钥使用发起者的公钥加密后发送给发起者。  
4.发起者收到公钥后，使用自己的私钥解密得到接受者的公钥。  
5.验证通过后，双方通过接受者的公私钥进行通信。  
