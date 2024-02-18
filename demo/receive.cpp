#include <fsipc.h>
#include <iostream>
using namespace std;
int main() {
    string str = "hello";
    int * ptr = fsipc::SharedMemory<int>(str);
    int a = 0;
    while(1) {
        if(*ptr != a){
            cout << *ptr << endl;
            a = *ptr;
        }
    }
}