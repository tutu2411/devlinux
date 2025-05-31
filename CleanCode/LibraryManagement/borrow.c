#include <stdio.h>
#include "book.h"
#include "user.h"

void borrowBook() {
    int userId, bookId;
    printf("User ID: "); scanf("%d", &userId);
    printf("Book ID: "); scanf("%d", &bookId); getchar();

    User* user = findUserById(userId);
    Book* book = findBookById(bookId);

    if (!user || !book) {
        printf("User or book not found.\n");
        return;
    }

    if (book->isBorrowed) {
        printf("Book is already borrowed.\n");
        return;
    }

    if (user->borrowedCount >= MAX_BORROWED_BOOKS) {
        printf("User has reached borrowing limit.\n");
        return;
    }

    book->isBorrowed = 1;
    user->borrowedBookIds[user->borrowedCount++] = bookId;
    printf("Book borrowed successfully.\n");
}

void returnBook() {
    int userId, bookId;
    printf("User ID: "); scanf("%d", &userId);
    printf("Book ID: "); scanf("%d", &bookId); getchar();

    User* user = findUserById(userId);
    Book* book = findBookById(bookId);

    if (!user || !book) {
        printf("User or book not found.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < user->borrowedCount; i++) {
        if (user->borrowedBookIds[i] == bookId) {
            user->borrowedBookIds[i] = user->borrowedBookIds[user->borrowedCount - 1];
            user->borrowedCount--;
            book->isBorrowed = 0;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Book returned successfully.\n");
    } else {
        printf("This book was not borrowed by the user.\n");
    }
}
