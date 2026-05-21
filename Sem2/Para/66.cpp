#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int parseInt(const string& str)
{
    if (str.empty())
    {
        throw string("String is empty");
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            throw string ("Not valid integer");
        }
    }
    return stoi(str);
}

int main()
{
    try {
        int num = parseInt("42");
        cout << "Parsed: " << num << endl;
    } catch (const string& error_msg) {
        cout << "Error: " << error_msg << endl;
    } catch (...) {
        cout << "Unknown exception caught" << endl;
    }

    try {
        int num = parseInt("abc");
        cout << "Parsed: " << num << endl;
    } catch (const string& error_msg) {
        cout << "Error: " << error_msg << endl;
    } catch (...) {
        cout << "Unknown exception caught" << endl;
    }
}