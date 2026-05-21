#include <iostream>
using namespace std;
struct DiffType
{
    int a;
    float b;
    double c;
};
int main()
{
    cout << sizeof(DiffType) << endl;
}