#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Mobile
{
private:
    string model;
    string developer;
    int price;
public:
    Mobile() : model("Unknown"), developer("Unknown"), price(0) {}
    Mobile(string m, string d, int p) : model(m), developer(d), price(p) {}

    void setModel(string m)
    {
        model = m;
    }
    void setDeveloper(string d)
    {
        developer = d;
    }
    void setPrice(int p)
    {
        price = p;
    }

    string getModel() const
    {
        return model;
    }
    string getDeveloper() const
    {
        return developer;
    }
    int getPrice() const
    {
        return price;
    }

    friend istream& operator>>(istream& is, Mobile& m)
    {
        is >> m.model >> m.developer >> m.price;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Mobile& m)
    {
        os << m.model << " | " << m.developer << " | " << m.price << endl;
        return os;
    }

    bool operator<(const Mobile& other) const
    {
        return price < other.price;
    }
};

void sortMobile(Mobile* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                Mobile temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

string findMinPriceModel(Mobile* arr, int n, string targetDeveloper)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].getDeveloper() == targetDeveloper)
        {
            return arr[i].getModel();
        }
    }
    return "Not found";
}

int main()
{
    ifstream inFile("mobile.txt");
    ofstream outFile("output.txt");

    if (!inFile)
    {
        cerr << "File not exist" << endl;
        return 1;
    }

    int n;
    if (!(inFile >> n))
    {
        cout << "File is empty" << endl;
        return 1;
    }

    Mobile* arr = new Mobile[n];
    for (int i = 0; i < n; i++)
    {
        inFile >> arr[i];
    }

    sortMobile(arr, n);

    string d;
    cout << "Target developer: ";
    cin >> d;

    string minModelName = findMinPriceModel(arr, n, d);

    cout << "Lowest price model: " << minModelName << endl;
    outFile << "Lowest price model: " << minModelName << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        outFile << arr[i];
    }

    delete[] arr;
    inFile.close();
    outFile.close();

    return 0;
}