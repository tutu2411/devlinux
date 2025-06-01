#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int id;
    int isBorrowed; // 0: available, 1: borrowed
} Book;

extern Book books[MAX_BOOKS];
extern int bookCount;

Book* findBookById(int id);
void addBook();
void editBook();
void deleteBook();
void searchBooks();
void listAvailableBooks();

#endif
