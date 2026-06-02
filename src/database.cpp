#include "database.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Load data buku dari CSV
vector<Book> loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);

    if (!file.is_open()) {
        return books;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Book book;
        string stockStr;

        getline(ss, book.id, ',');
        getline(ss, book.title, ',');
        getline(ss, book.author, ',');
        getline(ss, stockStr, ',');

        book.stock = stoi(stockStr);

        books.push_back(book);
    }

    file.close();
    return books;
}

// Simpan data buku ke CSV
void saveBooks(const string& filename, const vector<Book>& books) {
    ofstream file(filename);

    for (const auto& book : books) {
        file << book.id << ","
             << book.title << ","
             << book.author << ","
             << book.stock << endl;
    }

    file.close();
}

// Tambah buku baru
void addBook(const string& filename, const Book& newBook) {
    vector<Book> books = loadBooks(filename);

    books.push_back(newBook);

    saveBooks(filename, books);
}

// Update data buku berdasarkan ID
bool updateBook(const string& filename, const string& id, const Book& updatedBook) {
    vector<Book> books = loadBooks(filename);

    for (auto& book : books) {
        if (book.id == id) {
            book = updatedBook;
            saveBooks(filename, books);
            return true;
        }
    }

    return false;
}

// Hapus buku berdasarkan ID
bool deleteBook(const string& filename, const string& id) {
    vector<Book> books = loadBooks(filename);

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            saveBooks(filename, books);
            return true;
        }
    }

    return false;
}