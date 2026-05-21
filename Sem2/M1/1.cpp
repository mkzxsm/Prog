//Варіант 3
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

class Book
{
protected:
    string name;
    string author;
    long int price;
public:
    Book(string n, string a, long int p) : name(n), author(a), price(p){}
    virtual ~Book(){}
    virtual void print(ostream& os) const = 0;
    virtual string getType() const = 0;

    string getName() const { return name; }
    string getAuthor() const { return author; }
    long int getPrice() const { return price; }
};

class Paper : public Book
{
private:
    int pages;
    string typePal;
public:
    Paper(string n, string a, long int p, int pag, string t) : Book(n, a, p), pages(pag), typePal(t){}
    virtual ~Paper(){}

    void print(ostream& os) const override
    {
        os << name << " " << author << " " << price << " " << pages << " " << typePal;
    }
    string getType() const override { return "Paper"; }
};

class Elect : public Book
{
private:
    string format;
    double weight;
public:
    Elect(string n, string a, long int p, string f, double w) : Book(n, a, p), format(f), weight(w){}
    virtual ~Elect(){}

    void print(ostream& os) const override
    {
        os << name << " " << author << " " << price << " " << format << " " << weight;
    }
    string getType() const override { return "Elect"; }
};

void sort(Book** books, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i -1; ++j)
        {
            if (books[j]->getPrice() > books[j+1]->getPrice())
            {
                Book* temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void printAllForAuthor(Book** books, int size, string targetAuthor)
{
    long int totalCost = 0;
    cout << "Books from: " << targetAuthor << endl;
    for (int i = 0; i < size; ++i)
    {
        if (books[i]->getAuthor() == targetAuthor)
        {
            books[i]->print(cout);
            cout << endl;
            totalCost += books[i]->getPrice();
        }
    }
    cout << "Total Cost: " << totalCost << endl;
}

void writeTxtElect(Book** books, int size, string filename, long int targetMin, long int targetMax)
{
    ofstream out(filename);
    for (int i = 0; i < size; ++i)
    {
        if (books[i]->getType() == "Elect" &&
            books[i]->getPrice() > targetMin &&
            books[i]->getPrice() < targetMax)
        {
            books[i]->print(out);
            out << endl;
        }
    }
    out.close();
}

void writeTxtPaper(Book** books, int size, string filename, string targetAuthor)
{
    ofstream out(filename);
    for (int i = 0; i < size; ++i)
    {
        if (books[i]->getType() == "Paper" &&
            books[i]->getAuthor() == targetAuthor)
        {
            books[i]->print(out);
            out << endl;
        }
    }
    out.close();
}

int main()
{
    srandom(time(0));

    int size = 10;
    Book** books = new Book*[size];

    for (int i = 0; i < size; ++i)
    {
        long int temp = random() % 10 + 2;
        if (temp % 2 == 0)
        {
            books[i] = new Paper("Paper book 1", "Author 1", random() % 700 + 100, random() % 700 + 100, "hard");
        } else
        {
            books[i] = new Elect("Elect book 2", "Author 2", random() % 700 + 100, "pdf", random() % 10 + 20);
        }
    }

    sort(books, size);

    printAllForAuthor(books, size, "Author 1");

    writeTxtElect(books, size, "elect.txt", 100, 500);
    writeTxtPaper(books, size, "paper.txt", "Author 1");

    for (int i = 0; i < size; ++i)
    {
        delete books[i];
    }
    delete[] books;

    return 0;
}