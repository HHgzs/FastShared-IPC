#include <fsipc.h>
#include <iostream>
using namespace std;
int main() {
    string str;
    while(cin >> str) {
        cout << fsipc::generateSharedMemoryKey(str) << endl;
    }
}