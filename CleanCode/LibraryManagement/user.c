#include <stdio.h>
#include <string.h>
#include "user.h"
#include "book.h"
#include "utils.h"

User users[MAX_USERS];
int userCount = 0;

User* findUserById(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) return &users[i];
    }
    return NULL;
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;
    printf("User Name: "); readLine(newUser.name, sizeof(newUser.name));
    printf("User ID: "); scanf("%d", &newUser.id); getchar();

    if (findUserById(newUser.id)) {
        printf("User ID already exists.\n");
        return;
    }

    newUser.borrowedCount = 0;
    users[userCount++] = newUser;
    printf("User added successfully.\n");
}

void editUser() {
    int id;
    printf("Enter user ID to edit: ");
    scanf("%d", &id); getchar();

    User* updateUser = findUserById(id);
    if (!updateUser) {
        printf("Book not found.\n");
        return;
    }

    printf("New Name: "); readLine(updateUser->name, sizeof(updateUser->name));
    printf("User updated successfully.\n");
}

void deleteUser() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id); getchar();

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            users[i] = users[userCount - 1];
            userCount--;
            printf("User deleted successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}

void showUserInfo() {
    int id;
    printf("Enter user ID: ");
    scanf("%d", &id); getchar();

    User* user = findUserById(id);
    if (!user) {
        printf("User not found.\n");
        return;
    }

    printf("Name: %s | ID: %d\n", user->name, user->id);
    printf("Borrowed books:\n");
    for (int i = 0; i < user->borrowedCount; i++) {
        Book* book = findBookById(user->borrowedBookIds[i]);
        if (book) {
            printf(" - %s (%s)\n", book->title, book->author);
        }
    }
}
