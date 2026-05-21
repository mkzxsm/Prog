#include <iostream>
using namespace std;
int main(){
    int a[7] = {-3, 2, -1, 0, -5, 4, 1};
    int product = 1;
    bool hasnegative = false;
    for (int i = 0; i < 7; i++){
        if (a[i] < 0){
            product *= a[i];
            hasnegative = true;
        }
    }
    if (hasnegative = true){
        cout << product << endl;
    }
    else{
        cout << "0" << endl;
    }
    return 0;
}
