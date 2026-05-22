#include <iostream>
#include <fstream>
#include <numeric>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class EmployeeException : public std::runtime_error
{
public:
    explicit EmployeeException(const std::string& msg) : std::runtime_error(msg) {}
};

template <typename T>
class Employee
{
private:
    string fullName;
    T birthDate;
    double baseSalary;
    int experience;
public:
    Employee() : fullName(""), birthDate(T()), baseSalary(0.0), experience(0) {}

    Employee(string name, T dob, double salary, int exp)
        : fullName(name), birthDate(dob), baseSalary(salary), experience(exp) {}

    friend ostream& operator<<(ostream& os, const Employee<T>& emp)
    {
        os << emp.fullName << " " << emp.birthDate << " " << emp.baseSalary << " " << emp.experience;
        return os;
    }

    friend istream& operator>>(istream& is, Employee<T>& emp)
    {
        is >> emp.fullName >> emp.birthDate >> emp.baseSalary >> emp.experience;
        return is;
    }

    void setFullName(string n)
    {
        fullName = n;
    }

    void setBirthDate(T n)
    {
        birthDate = n;
    }

    void setExperience(int n)
    {
        experience = n;
    }

    void setSalary(double n)
    {
        baseSalary = n;
    }

    string getFullName() const
    {
        return fullName;
    }

    T getBirthDate() const
    {
        return birthDate;
    }

    int getExperience() const
    {
        return  experience;
    }

    double getSalary() const
    {
        return baseSalary;
    }
};

int main()
{
    vector<Employee<int>> employees;

    ifstream inFile("file.txt");
    Employee<int> temp;
    while (inFile >> temp)
    {
        employees.push_back(temp);
    }
    double total_salary = accumulate(employees.begin(), employees.end(), 0.0, [](double sum, const Employee<int>& emp){return sum + emp.getSalary();});

    return 0;
}