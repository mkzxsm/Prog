#include <iostream>
using namespace std;
int main(){
    int a[7] = {-2, 4, -5, 1, 0, -1, 3};
    for (int i = 0; i < 7; i++){
        if (a[i] < 0){
            a[i] = 0;
        }
    }
    for (int i = 0; i < 7; i++){
        cout << a[i] << " ";
    }
    return 0;
}