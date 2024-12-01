#include <iostream>
#include <fstream>
#include <cstring>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

int z(int r){if(r==0||r==1||r==2||r==3||r==4||r==5||r==6||r==7||r==8||r==9){return r;}else if(49<=r<55){return r-39;}}

int main(){
    std::fstream fio;
    cpp_int key,pub;
    fio.open("pri", std::ios::in);
    fio >> key;
    fio.close();
    fio.open("public", std::ios::in);
    fio >> pub;
    fio.close();
    int y=0;
    std::string s,t;
    fio.open("RSA-ed.txt", std::ios::in);
    fio >> s;
    fio.close();
    int j = 0;
    fio.open("output.txt", std::ios::out);
    char c[64];
    cpp_int u[64];
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='/'){
            for(int k = 0; k < j; k++){
                int r=z(c[k]-'0');
                cpp_int zr=1;
                for(int l=0;l<(j-k);l++){
                    zr=zr*16;
                }
                zr=zr/16;
                zr=zr*r;
                u[k]=zr;
            }
            cpp_int v=0;
            for(int k=0; k<j; k++){
                v+=u[k];
            }
            y=1;
            cpp_int w=1;
            for(int k=0; k<key; k++){
                w=w*v;
            }
            cpp_int x=w%pub;
            fio << char(x-256);
            for(int k=0; k<64; k++){
                u[k]=NULL;
            }
            j=0;
            for(int k=0; k<64; k++){
                c[k]='\0';
            }
        }else{
        c[j]=s[i]; j++;
        }
    }
    fio.close();
    std::cout << "解密后数据已写入到output.txt" << std::endl;
    return 0;
}