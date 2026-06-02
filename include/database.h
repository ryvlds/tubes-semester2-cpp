#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>

using namespace std;

struct Book {
    string id;
    string title;
    string author;
    int stock;
};

vector<Book> loadBooks(const string& filename);
void saveBooks(const string& filename, const vector<Book>& books);
void addBook(const string& filename, const Book& newBook);
bool updateBook(const string& filename, const string& id, const Book& updatedBook);
bool deleteBook(const string& filename, const string& id);

#endif