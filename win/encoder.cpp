#include <iostream>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

int main(){
    std::string text;
    std::cout<<"����Ҫ���ܵ��ı���";
    std::cin >> text;
    std::fstream fio;
    cpp_int key,pub;
    std::cout<<"���������Կ��";
    std::cin >> key;
    std::cout<<"���빲����Կ��";
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
    std::cout<<"���ܺ���ı�Ϊ��"<<ed<<std::endl;
    fio.close();
    std::cout << "�����ı���д�뵽 RSA-ed.txt" << std::endl;
    return 0;
}