#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class Exhibit
{
private:
    string name;
    string origin;
    int year;
    double price;
    int count;

public:
    Exhibit() : name(""), origin(""), year(0), price(0.0), count(0)
    {
    }

    Exhibit(string n, string o, int y, double p, int c)
    {
        if (!setName(n)) name = "Unknown";
        if (!setOrigin(o)) origin = "Unknown";
        if (!setYear(y)) year = 0;
        if (!setPrice(p)) price = 0.0;
        if (!setCount(c)) count = 0;
    }

    double getTotalValue() const
    {
        return price * count;
    }

    bool setName(string n)
    {
        if (n.empty()) return false;
        name = n;
        return true;
    }

    string getName() const { return name; }

    bool setOrigin(string o)
    {
        if (o.empty()) return false;
        origin = o;
        return true;
    }

    bool setYear(int y)
    {
        if (y < 0) return false;
        year = y;
        return true;
    }

    bool setPrice(double p)
    {
        if (p < 0) return false;
        price = p;
        return true;
    }

    double getPrice() const { return price; }

    bool setCount(int c)
    {
        if (c < 0) return false;
        count = c;
        return true;
    }

    int getCount() const { return count; }

    bool isValid() const
    {
        return !name.empty() && !origin.empty() && year >= 0 && price >= 0 && count >= 0;
    }

    bool operator<(const Exhibit& other) const
    {
        if (year != other.year)
        {
            return year < other.year;
        }
        return name < other.name;
    }

    friend ostream& operator<<(ostream& os, const Exhibit& ex);
    friend istream& operator>>(istream& os, Exhibit& ex);
};

ostream& operator<<(ostream& os, const Exhibit& ex)
{
    os << left << setw(15) << ex.name
        << setw(15) << ex.origin
        << setw(6) << ex.year
        << setw(10) << ex.price
        << setw(5) << ex.count
        << " Total: " << ex.getTotalValue();
    return os;
}

istream& operator>>(istream& is, Exhibit& ex)
{
    string n, o;
    int y, c;
    double p;

    if (is >> n >> o >> y >> p >> c)
    {
        bool ok = true;
        if (!ex.setName(n)) ok = false;
        if (!ex.setOrigin(o)) ok = false;
        if (!ex.setYear(y)) ok = false;
        if (!ex.setPrice(p)) ok = false;
        if (!ex.setCount(c)) ok = false;

        if (!ok)
        {
            ex.year = -1;
        }
    }
    return is;
}


int main()
{
    ifstream inFile("exhibits.txt");
    if (!inFile)
    {
        cerr << "Error: Cannot open exhibits.txt" << endl;
        return 1;
    }

    int n;
    inFile >> n;

    if (n <= 0)
    {
        cout << "No data to process" << endl;
        return 0;
    }

    Exhibit* exhibits = new Exhibit[n];
    int validCount = 0;

    Exhibit temp;
    for (int i = 0; i < n; ++i)
    {
        inFile >> temp;
        if (temp.isValid())
        {
            exhibits[validCount] = temp;
            validCount++;
        }
    }
    inFile.close();

    for (int i = 0; i < validCount - 1; ++i)
    {
        for (int j = 0; j < validCount - i - 1; ++j)
        {
            if (exhibits[j + 1] < exhibits[j])
            {
                swap(exhibits[j], exhibits[j + 1]);
            }
        }
    }

    ofstream outFile("report.txt");
    if (!outFile)
    {
        cerr << "Error: Cannot create report.txt" << endl;
        delete[] exhibits;
        return 1;
    }

    outFile << "--- Sorted Exhibits Report ---" << endl;
    outFile << left << setw(15) << "Name"
        << setw(15) << "Origin"
        << setw(6) << "Year"
        << setw(10) << "Price"
        << setw(5) << "Qty"
        << "Total Value" << endl;
    outFile << "-------------------------------------------------------------" << endl;

    double grandTotalValue = 0;

    for (int i = 0; i < validCount; ++i)
    {
        outFile << exhibits[i] << endl;
        grandTotalValue += exhibits[i].getTotalValue();
    }

    outFile << "-------------------------------------------------------------" << endl;
    outFile << "Total Value: " << grandTotalValue << endl;

    cout << "Report generated successfully in 'report.txt'." << endl;

    outFile.close();
    delete[] exhibits;

    return 0;
}
