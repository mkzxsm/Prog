#include <iostream>
using namespace std;
int main(){
    int a[5] = {2, 4, 6, 6, 9};
    bool is_ordered = true;
    for (int i = 0; i < 4; i++){
        if (a[i] > a[i+1]){
            is_ordered = false;
        }
    }
    if (is_ordered == true){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}