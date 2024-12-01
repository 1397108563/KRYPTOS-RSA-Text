#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int main(){
    std::fstream fio;
    std::string text = "你好";
    cpp_int key = 53;
    cpp_int pub = 4559;
    const char *utf8 = text.c_str();
    fio.open("RSA-ed.txt", std::ios::out);
    for (int i = 0; i < text.size(); i++) {
        long r = utf8[i] + 256;
        cpp_int mi = 1;
        for (int j = 0; j < key; j++) {
            mi = mi*r;
        }
        std::cout<<mi<<std::endl;
        mi = mi%pub;
        fio<<std::hex<<mi<<"/";
    }
    fio.close();
    return 0;
}