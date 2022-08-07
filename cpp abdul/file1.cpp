#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("hello.txt", ios::trunc);
    ofs << "ritik" << endl;
    ofs << 33 << endl;
    ofs << "CS" << endl;
    cout << "Data appended";
    ofs.close();
    return 0;
}