#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

struct Author {
    string surname;
    string name;

    bool operator<(const Author& other) const {
        if (surname != other.surname) {
            return surname < other.surname;
        }
        return name < other.name;
    }

    bool operator==(const Author& other) const {
        return surname == other.surname && name == other.name;
    }
};

struct Book {
    string title;
    string publisher;
    double price;
};

using BookDB = multimap<Author, Book>;

void addFromKeyboard(BookDB& db) {
    Author author;
    Book book;

    cout << "Прізвище автора: "; cin >> author.surname;
    cout << "Ім'я автора: "; cin >> author.name;
    cin.ignore();

    cout << "Назва книги: "; getline(cin, book.title);
    cout << "Видавництво: "; getline(cin, book.publisher);

    cout << "Ціна: "; cin >> book.price;

    db.insert({author, book});
}

void saveDBToFile(const BookDB& db, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) return;

    for (const auto& pair : db) {
        fout << pair.first.surname << "\n"
             << pair.first.name << "\n"
             << pair.second.title << "\n"
             << pair.second.publisher << "\n"
             << pair.second.price << "\n";
    }
    fout.close();
}

void loadDBFromFile(BookDB& db, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) return;

    Author author;
    Book book;

    while (fin >> author.surname) {
        fin >> author.name;
        fin.ignore();

        getline(fin, book.title);
        getline(fin, book.publisher);

        fin >> book.price;

        db.insert({author, book});
    }
    fin.close();
}

void extractAuthorBooks(BookDB& db, const Author& target, const string& filename) {
    auto range = db.equal_range(target);
    if (range.first == range.second) return;

    ofstream fout(filename);
    for (auto it = range.first; it != range.second; ++it) {
        fout << it->second.title << " | "
             << it->second.publisher << " | "
             << it->second.price << "\n";
    }
    fout.close();

    db.erase(range.first, range.second);
}

void findAuthorByTitle(const BookDB& db, const string& targetTitle) {
    for (const auto& pair : db) {
        if (pair.second.title == targetTitle) {
            cout << pair.first.surname << " " << pair.first.name << "\n";
        }
    }
}

void findBooksByPublisherAndPrice(const BookDB& db, const string& publisher, double minP, double maxP, const string& filename) {
    ofstream fout(filename);
    for (const auto& pair : db) {
        if (pair.second.publisher == publisher && pair.second.price >= minP && pair.second.price <= maxP) {
            fout << pair.first.surname << " " << pair.first.name << " - "
                 << pair.second.title << " (" << pair.second.price << ")\n";
        }
    }
    fout.close();
}

void changeBookPrice(BookDB& db, const Author& targetAuthor, const string& targetTitle, double newPrice) {
    auto range = db.equal_range(targetAuthor);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.title == targetTitle) {
            it->second.price = newPrice;
            return;
        }
    }
}

void generatePublisherReport(const BookDB& db, const string& targetPublisher, const string& filename) {
    map<Author, vector<double>> reportData;

    for (const auto& pair : db) {
        if (pair.second.publisher == targetPublisher) {
            reportData[pair.first].push_back(pair.second.price);
        }
    }

    if (reportData.empty()) return;

    ofstream fout(filename);
    fout << left << setw(30) << "Автор"
         << setw(15) << "К-сть книг"
         << setw(20) << "Середня вартість" << "\n";
    fout << string(65, '-') << "\n";

    for (const auto& data : reportData) {
        const Author& author = data.first;
        const vector<double>& prices = data.second;

        int count = prices.size();
        double sum = 0;
        for (double p : prices) sum += p;
        double avgPrice = sum / count;

        string fullName = author.surname + " " + author.name;
        fout << left << setw(30) << fullName
             << setw(15) << count
             << fixed << setprecision(2) << setw(20) << avgPrice << "\n";
    }
    fout.close();
}

int main() {
    BookDB myDB;
    const string dbFile = "database.txt";

    loadDBFromFile(myDB, dbFile);

    if (myDB.empty()) {
        myDB.insert({{"Шевченко", "Тарас"}, {"Кобзар", "Фоліо", 250.0}});
        myDB.insert({{"Шевченко", "Тарас"}, {"Гайдамаки", "А-БА-БА", 300.0}});
        myDB.insert({{"Франко", "Іван"}, {"Захар Беркут", "Фоліо", 180.0}});
    }

    findAuthorByTitle(myDB, "Кобзар");
    findBooksByPublisherAndPrice(myDB, "Фоліо", 100.0, 260.0, "search_results.txt");
    changeBookPrice(myDB, {"Франко", "Іван"}, "Захар Беркут", 199.99);
    generatePublisherReport(myDB, "Фоліо", "report_folio.txt");
    extractAuthorBooks(myDB, {"Шевченко", "Тарас"}, "shevchenko_books.txt");

    saveDBToFile(myDB, dbFile);

    return 0;
}