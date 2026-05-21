#include <iostream>
using namespace std;
int main(){
    int count = 0;
    int a[10] = {5, 12, 7, 20, 10, 3, 15, 8, 25, 1};
    for (int i = 0; i < 10; i++){
        if (a[i] > 10){
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}