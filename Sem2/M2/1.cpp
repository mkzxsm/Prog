//Варіант 5
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <random>

using namespace std;

template <typename T>
class Matrix
{
private:
    int size;
    T** data;

public:
    Matrix() {
        size = 0;
        data = nullptr;
    }

    Matrix(int s) {
        if (s <= 0) throw invalid_argument("Size must be more then 0");
        size = s;
        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
        }
    }

    Matrix(const Matrix& other) {
        size = other.size;
        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
            for (int j = 0; j < size; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < size; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        for (int i = 0; i < size; i++) delete[] data[i];
        delete[] data;

        size = other.size;
        data = new T*[size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
            for (int j = 0; j < size; j++) data[i][j] = other.data[i][j];
        }
        return *this;
    }

    void initRandom()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (typeid(T) == typeid(int))
                {
                    data[i][j] = (T)(random() % 10);
                }
                else if (typeid(T) == typeid(double))
                {
                    data[i][j] = (T)(random() % 100) / 10.0;
                }
                else if (typeid(T) == typeid(char))
                {
                    data[i][j] = (T)(random() % 26 + 65);
                }
                else
                {
                    throw invalid_argument("Unknown type");
                }

            }
        }
    }

    T findMax() const
    {
        if (size == 0) throw logic_error("Matrix is empty");

        T maxVal = data[0][0];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (data[i][j] > maxVal)
                {
                    maxVal = data[i][j];
                }
            }
        }
        return maxVal;
    }

    Matrix transpose() const
    {
        Matrix result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }

    friend istream& operator>>(istream& is, Matrix& m) {
        for (int i = 0; i < m.size; i++) {
            for (int j = 0; j < m.size; j++) {
                is >> m.data[i][j];
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m)
    {
        for (int i = 0; i < m.size; i++)
        {
            for (int j = 0; j < m.size; j++)
            {
                os << m.data[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }
};

int main()
{
    try
    {
        srandom(time(0));
        Matrix<int> m(3);
        m.initRandom();
        cout << "Default matrix int:\n" << m << endl;
        cout << "Transpose matrix int:\n" << m.transpose() << endl;
        cout << "Max from matrix int:\n" << m.findMax() << endl;

        Matrix<double> d(3);
        d.initRandom();
        cout << "Default matrix double:\n" <<d << endl;
        cout << "Transpose matrix double:\n" << d.transpose() << endl;
        cout << "Max from matrix double:\n" << d.findMax() << endl;

        Matrix<char> c(3);
        c.initRandom();
        cout << "Default matrix char:\n" <<c << endl;
        cout << "Transpose matrix char:\n" << c.transpose() << endl;
        cout << "Max from matrix char:\n" << c.findMax() << endl;
        Matrix<int> t(-1);
    } catch (const exception& e)
    {
        cout << "Catch exception: " << e.what();
    }
}
