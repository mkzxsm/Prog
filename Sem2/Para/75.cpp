#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 0;i<6;i++)
    {
        vec.push_back(i);
    }
    cout << "Size: " << vec.size() << "Capacity: " << vec.capacity();
    vec.pop_back();
    vec.insert(vec.begin()+2, 99);
    vec.erase(vec.begin()+2);
    for (int num : vec)
    {
        cout << num << " ";
    }
}