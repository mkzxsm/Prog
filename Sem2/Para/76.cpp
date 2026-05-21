#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> deq;
    for (int i = 0; i < 3; i++)
    {
        deq.push_back(i);
    }
    for (int num : deq)
    {
        cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        deq.push_front(i*10);
    }
    cout << endl;
    for (int num : deq)
    {
        cout << num << " ";
    }
    cout << endl;
    deq.pop_back();
    deq.pop_front();
    for (int num : deq)
    {
        cout << num << " ";
    }
}