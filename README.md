# KRYPTOS-RSA-Text
基于KRYPTOS &amp; RSA的非对称文本加密传输
## 依赖
`sudo apt install -y libboost-all-dev g++`
## 用法
编译后直接运行  
`./make.sh && build/decoder && build/encoder`
## 文件
`RSA-ed.txt`是经过RSA加密的内容，其中原始内容的每一个字节以“/”作分割，可以在文件内查找该字符并修改  
**不可修改为空格，会影响程序的文件读取功能**  
`output.txt`是使用私钥解密过后的内容
