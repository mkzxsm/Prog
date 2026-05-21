#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    array<int, 5> arr = {5, 3, 1, 4, 2};

    cout << "Elements: ";
    for (int num : arr) {
        cout << num << " ";
    }

    cout << "Size: " << arr.size();
    cout << "Front: " << arr.front() << ", Back: " << arr.back();
    sort(arr.begin(), arr.end());
    cout << "Sorted: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}