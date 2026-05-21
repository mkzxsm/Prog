#include <iostream>
using namespace std;

int findCount(int* row, int x, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (row[i] > x)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Введи n: ";
    cin >> n;

    int x;
    cout << "Введи x: ";
    cin >> x;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int* counts = new int[n];

    for (int i = 0; i < n; i++)
    {
        counts[i] = findCount(arr[i], x, n);
    }

    int maxIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (counts[i] > counts[maxIdx])
        {
            maxIdx = i;
        }
    }

    cout << "Номер рядка з максимумом: " << maxIdx << endl;

    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
    delete[] counts;

    return 0;
}