#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int main(){
    std::string text;
    std::cout<<"输入要加密的文本：";
    std::cin >> text;
    std::fstream fio;
    cpp_int key,pub;
    std::cout<<"输入加密密钥：";
    std::cin >> key;
    std::cout<<"输入共有密钥：";
    std::cin >> pub;
    const char *utf8 = text.c_str();
    fio.open("RSA-ed.txt", std::ios::out);
    for (int i = 0; i < text.size(); i++) {
        long r = utf8[i] + 256;
        cpp_int mi = 1;
        for (int j = 0; j < key; j++) {
            mi = mi*r;
        }
        mi = mi%pub;
        fio<<std::hex<<mi<<"/";
    }
    fio.close();
    fio.open("RSA-ed.txt", std::ios::in);
    std::string ed;
    fio>>ed;
    std::cout<<"加密后的文本为："<<ed<<std::endl;
    fio.close();
    std::cout << "加密文本已写入到 RSA-ed.txt" << std::endl;
    return 0;
}