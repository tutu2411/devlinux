#include <stdio.h>
#include <string.h>
#include "book.h"
#include "utils.h"

Book books[MAX_BOOKS];
int bookCount = 0;

Book* findBookById(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) return &books[i];
    }
    return NULL;
}

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book newBook;
    printf("Title: "); readLine(newBook.title, sizeof(newBook.title));
    printf("Author: "); readLine(newBook.author, sizeof(newBook.author));
    printf("ID: "); scanf("%d", &newBook.id); getchar();

    if (findBookById(newBook.id)) {
        printf("Book ID already exists.\n");
        return;
    }

    newBook.isBorrowed = 0;
    books[bookCount++] = newBook;
    printf("Book added successfully.\n");
}

void editBook() {
    int id;
    printf("Enter book ID to edit: ");
    scanf("%d", &id); getchar();

    Book* book = findBookById(id);
    if (!book) {
        printf("Book not found.\n");
        return;
    }

    printf("New Title: "); readLine(book->title, sizeof(book->title));
    printf("New Author: "); readLine(book->author, sizeof(book->author));
    printf("Book updated successfully.\n");
}

void deleteBook() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id); getchar();

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            books[i] = books[bookCount - 1];
            bookCount--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void searchBooks() {
    char keyword[100];
    printf("Enter keyword: ");
    readLine(keyword, sizeof(keyword));

    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
            printf("ID: %d | %s - %s [%s]\n", books[i].id, books[i].title, books[i].author,
                   books[i].isBorrowed ? "Borrowed" : "Available");
        }
    }
}

void listAvailableBooks() {
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isBorrowed) {
            printf("ID: %d | %s - %s\n", books[i].id, books[i].title, books[i].author);
        }
    }
}
