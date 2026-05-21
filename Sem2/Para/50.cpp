#include <iostream>

class IPrintable
{
public:
    virtual void Print() const = 0;
    ~IPrintable()
    {
        std::cout << "IPrintable destructor";
    }
};

class Document : public IPrintable
{
    void Print() const override
    {
        std::cout << "Document printed" << std::endl;
    }
    ~Document()
    {
        std::cout << "Document destructor";
    }
};

int main()
{
    IPrintable* a = new Document;
    a->Print();
    delete a;
}
