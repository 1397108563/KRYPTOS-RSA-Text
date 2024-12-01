#include <iostream>
#include <fstream>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

bool is_prime(cpp_int n) {
    std::fstream fio;
    for(int i=2;i<n;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int m,n;
    std::fstream fio;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(2,1000);
    while(true){
        m = distr(gen);
        if (is_prime(m)){
            break;
        }
    }
    while(true){
        n = distr(gen);
        if (is_prime(n)){
            break;
        }
    }
    std::cout<<"共有密钥为："<<m*n<<std::endl;
    fio.open("public",std::ios::out);
    fio<<m*n<<std::endl;
    fio.close();
    long ola = (m-1)*(n-1);
    cpp_int pub;
    distr=std::uniform_int_distribution<>(2,ola);
    while(true){
        pub = distr(gen);
        if(is_prime(pub)&&ola%pub!=0){
            std::cout<<"公钥为："<<pub<<std::endl;
            break;
        }
    }
    fio.open("pub",std::ios::out);
    fio<<pub<<std::endl;
    fio.close();
    cpp_int pri;
    for(pri=0;;pri++){
        if((pub*pri)%ola==1){
            break;
        }
    }
    std::cout<<"私钥为："<<pri<<std::endl;
    fio.open("pri",std::ios::out);
    fio<<pri<<std::endl;
    fio.close();
    return 0;
}