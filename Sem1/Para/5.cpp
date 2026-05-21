#include <iostream>
using namespace std;
int main(){
    int count = 0;
    int a[8] = {3, 6, 9, 12, 15, 18, 21, 24};
    for (int i = 0; i < 8; i++){
        if (a[i] % 2 == 0){
            count += 1;
        }
    }
    cout << count << endl;
}