#include <iostream>
#include <stdexcept>
#include <random>


template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class OrderedList {
private:
    Node<T>* head;
    size_t count;

    void copyFrom(const OrderedList& other) {
        if (!other.head) return;

        head = new Node<T>(other.head->data);
        Node<T>* curr = head;
        Node<T>* otherCurr = other.head->next;

        while (otherCurr) {
            curr->next = new Node<T>(otherCurr->data);
            curr = curr->next;
            otherCurr = otherCurr->next;
        }
        count = other.count;
    }

public:
    OrderedList() : head(nullptr), count(0) {}

    ~OrderedList() {
        clear();
    }

    OrderedList(const OrderedList& other) : head(nullptr), count(0) {
        copyFrom(other);
    }

    OrderedList& operator=(const OrderedList& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* curr = head;
            while (curr->next && curr->next->data < val) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        count++;
    }

    void remove(T val) {
        if (isEmpty()) {
            throw std::underflow_error("Помилка: Спроба видалення з порожнього списку!");
        }

        Node<T>* curr = head;
        Node<T>* prev = nullptr;

        while (curr && curr->data != val) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            throw std::invalid_argument("Помилка: Елемент для видалення не знайдено!");
        }

        if (!prev) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr;
        count--;
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        count = 0;
    }

    void fillRandom(size_t n, T minVal, T maxVal) {
        std::random_device rd;
        std::mt19937 gen(rd());

        for (size_t i = 0; i < n; ++i) {
            if constexpr (std::is_integral<T>::value) {
                std::uniform_int_distribution<T> dist(minVal, maxVal);
                insert(dist(gen));
            } else if constexpr (std::is_floating_point<T>::value) {
                std::uniform_real_distribution<T> dist(minVal, maxVal);
                insert(dist(gen));
            }
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    size_t getSize() const {
        return count;
    }

    friend std::ostream& operator<<(std::ostream& os, const OrderedList& list) {
        if (list.isEmpty()) {
            os << "[Порожній список]";
            return os;
        }
        Node<T>* curr = list.head;
        while (curr) {
            os << curr->data << " ";
            curr = curr->next;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, OrderedList& list) {
        size_t numElements;
        std::cout << "Введіть кількість елементів для додавання: ";
        if (is >> numElements) {
            std::cout << "Введіть " << numElements << " значень:\n";
            for (size_t i = 0; i < numElements; ++i) {
                T val;
                is >> val;
                list.insert(val);
            }
        }
        return is;
    }
};

int main() {
    try {
        std::cout << "=== Тестування списку ЦІЛИХ чисел (int) ===\n";
        OrderedList<int> intList;

        intList.fillRandom(10, 1, 100);
        std::cout << "Список після випадкової ініціалізації:\n" << intList << "\n";

        std::cout << "\nДодаємо числа 50, -10 та 200:\n";
        intList.insert(50);
        intList.insert(-10);
        intList.insert(200);
        std::cout << intList << "\n";

        std::cout << "\nВидаляємо число 50:\n";
        intList.remove(50);
        std::cout << intList << "\n";

        std::cout << "\nСпроба видалити неіснуюче число 999...\n";
        try {
            intList.remove(999);
        } catch (const std::exception& e) {
            std::cout << "Зловлено виключення: " << e.what() << "\n";
        }

        std::cout << "\n\n=== Тестування списку ДІЙСНИХ чисел (double) ===\n";
        OrderedList<double> doubleList;

        doubleList.fillRandom(5, -5.5, 5.5);
        std::cout << "Список дійсних чисел:\n" << doubleList << "\n";

        std::cout << "\nСтворюємо копію списку дійсних чисел...\n";
        OrderedList<double> copiedList(doubleList);
        copiedList.insert(99.99); // Додаємо лише в копію
        std::cout << "Оригінал: " << doubleList << "\n";
        std::cout << "Копія:    " << copiedList << "\n";

        std::cout << "\nОчищаємо оригінальний список...\n";
        doubleList.clear();
        std::cout << "Оригінал після очищення: " << doubleList << "\n";

        std::cout << "\nСпроба видалити елемент з порожнього списку...\n";
        try {
            doubleList.remove(1.1);
        } catch (const std::exception& e) {
            std::cout << "Зловлено виключення: " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Глобальна помилка: " << e.what() << "\n";
    }

    return 0;
}