#include <iostream>
using namespace std;
int main(){
    int min, index;
    int a[6] = {8, 3, 5, 2, 9, 4};
    for (int i = 0; i < 6; i++){
        if (a[i] < min){
            min = a[i];
            index = i;
        }
    }
    cout << "min=" << min << " index=" << index << endl;
    return 0;
}