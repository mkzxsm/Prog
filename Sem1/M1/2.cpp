//Варіант 2
#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    if (k == 0) {
        return 0;
    }
    int current_num;
    int last_printed;
    cin >> current_num;
    cout << current_num << " ";
    last_printed = current_num;
    for (int i = 1; i < k; ++i) {
        cin >> current_num;
        if (current_num != last_printed) {
            cout << current_num << " ";
            last_printed = current_num;
        }
    }
    return 0;
}