#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<int> lst;

    for (int i = 1; i <= 5; ++i) {
        lst.push_back(i);
    }

    cout << "Initial: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << "\n";

    auto it = lst.begin();
    advance(it, 2);
    lst.insert(it, 99);

    cout << "After insert 99 before 3rd: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << "\n";

    lst.remove_if([](int n) { return n % 2 == 0; });

    cout << "After remove even: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << "\n";

    lst.sort();

    cout << "After sort: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << "\n";

    lst.reverse();

    cout << "After reverse: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}