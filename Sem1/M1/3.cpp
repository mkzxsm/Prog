//Варіант 2
#include <iostream>
using namespace std;
int main(){
    int m;
    cin >> m;
    int nums[m];
    for (int i=0; i<m; i++){
        cin >> nums[i];
    }
    char command;
    cin >> command;
    if (command == 'E'){
        int even_count = 0;
        for (int i = 0; i < m; ++i) {
            if (nums[i] % 2 == 0){
                even_count++;
            }
        }    
    cout << even_count;
    }
    if (command == 'O'){
        int negsum = 0;
        for (int i = 0; i < m; ++i){
            if (nums[i]<0){
                negsum+=nums[i];
            }
        }
    cout << negsum;
    }
    if (command == 'R'){
        for (int i = m - 1; i >= 0; --i) {
            cout << nums[i] << " ";
        }
    }    
    if (command == 'X'){
        int last_element = nums[m - 1];
        for (int i = m - 2; i >= 0; --i) {
            nums[i + 1] = nums[i];
        }
        nums[0] = last_element;
        }
        for (int i = 0; i < m; ++i) {
            cout << nums[i] << " ";
        }
}
 