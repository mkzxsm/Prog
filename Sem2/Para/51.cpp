#include <iostream>

class IReadable
{
public:
    ~IReadable() = default;
    virtual void read() = 0;
};

class IWritable
{
public:
    ~IWritable() = default;
    virtual void write() = 0;
};

class File : public IReadable, public IWritable
{
public:
    void read() override
    {
        std::cout << "Read" << std::endl;
    }
    void write() override
    {
        std::cout << "Write" << std::endl;
    }
};

int main()
{
    File* f = new File;
    f->read();
    f->write();
    delete f;
}