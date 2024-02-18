#include <fsipc.h>
#include <iostream>
using namespace std;
int main() {
    string str = "hello";
    int * ptr = fsipc::SharedMemory<int>(str);
    while(cin >> *ptr) {
        cout << *ptr << endl;
    }
}