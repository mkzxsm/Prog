#include <iostream>
using namespace std;
int sum = 0;
int main(){
    int a[6] = {3, 7, 1, 9, 2, 5,};
    for (int i = 0; i < 6; i++){
        sum += a[i];
    }
    cout << "sum=" << sum << endl;
    return 0;
}