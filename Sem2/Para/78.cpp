#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

int main()
{
    forward_list<int> fl;
    for (int i = 0; i < 6; i++)
    {
        fl.push_front(i);
    }
    fl.insert_after(fl.begin(),99);
    auto it =fl.begin();
    advance(it,1);
    fl.erase_after(it);
    for (int num : fl)
    {
        cout << num << " ";
    }
}