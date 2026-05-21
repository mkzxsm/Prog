#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Phone
{
protected:
    string dev;
    double price;
    string color;
public:
    Phone (string d, double p, string c) : dev(d), price(p), color(c){}
    virtual ~Phone(){}
    virtual void print(ostream& os) const = 0;
    virtual string getType() const = 0;

    string getDev() const { return dev; }
    double getPrice() const { return price; }
    string getColor() const { return color; }
};

class Mobile : public Phone
{
private:
    string proc;
    int ram;
public:
    Mobile(string d, double p, string c, string pr, int r) : Phone(d, p, c), proc(pr), ram(r){}
    void print(ostream& os) const override
    {
        os << dev << " " << price << " " << color << " " << proc << " " << ram;
    }
    string getType() const override
    {
        return "Mobile";
    }
};

class Radio : public Phone
{
private:
    double rad;
    bool autoans;
public:
    Radio(string d, double p, string c, double r, bool a) : Phone(d, p, c), rad(r), autoans(a){}
    void print(ostream& os) const override
    {
        os << dev << " " << price << " " << color << " " << rad << " " << autoans;
    }
    string getType() const override
    {
        return "Radio";
    }
};

void sort(Phone** phones, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i -1; ++j)
        {
            if (phones[j]->getPrice() > phones[j+1]->getPrice())
            {
                Phone* temp = phones[j];
                phones[j] = phones[j+1];
                phones[j+1] = temp;
            }
        }
    }
}

void getAllDev(Phone** phones, int size, const string& targetBrand)
{
    double totalCost = 0;
    bool found = false;

    for (int i = 0; i < size; ++i)
    {
        if (phones[i]->getDev() == targetBrand)
        {
            totalCost += phones[i]->getPrice();
            phones[i]->print(cout);
            cout << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Not such phones\n";
    } else
    {
        cout << "Total cost: " << totalCost << endl;
    }
}

void writeTxT(Phone** phones, int size, const string& filename, double targetMin, double targetMax, const string& targetColor)
{
    ofstream out(filename);

    for (int i = 0; i < size; ++i)
    {
        if (phones[i]->getType() == "Mobile" &&
            phones[i]->getPrice() > targetMin &&
            phones[i]->getPrice() < targetMax &&
            phones[i]->getColor() == targetColor)
        {
            phones[i]->print(out);
            out << endl;
        }
    }
    out.close();
}

int main()
{
    int size = 5;
    Phone** phones = new Phone*[size];

    phones[0] = new Mobile("Xiaomi", 25000, "Black", "Exynos 2100", 8);
    phones[1] = new Radio("Panasonic", 1500, "White", 50, true);
    phones[2] = new Mobile("Apple", 35000, "Black", "A15 Bionic", 6);
    phones[3] = new Mobile("Xiaomi", 12000, "Blue", "Snapdragon 778G", 6);
    phones[4] = new Radio("Gigaset", 2000, "Black", 100, false);

    sort(phones, size);
    getAllDev(phones, size, "Xiaomi");
    writeTxT(phones, size, "test1.txt", 15000, 30000, "Black");

    for (int i = 0; i < size; ++i)
    {
        delete phones[i];
    }
    delete[] phones;

    return 0;
}