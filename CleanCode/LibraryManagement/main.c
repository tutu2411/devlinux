#include <stdio.h>
#include "book.h"
#include "user.h"
#include "borrow.h"

void showMenu() {
    printf("\n===== LIBRARY MENU =====\n");
    printf("1. Add Book\n");
    printf("2. Edit Book\n");
    printf("3. Delete Book\n");
    printf("4. Add User\n");
    printf("5. Delete User\n");
    printf("6. Borrow Book\n");
    printf("7. Return Book\n");
    printf("8. Search Books\n");
    printf("9. List Available Books\n");
    printf("10. Show User Info\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice); getchar();

        switch (choice) {
            case 1: addBook(); break;
            case 2: editBook(); break;
            case 3: deleteBook(); break;
            case 4: addUser(); break;
            case 5: deleteUser(); break;
            case 6: borrowBook(); break;
            case 7: returnBook(); break;
            case 8: searchBooks(); break;
            case 9: listAvailableBooks(); break;
            case 10: showUserInfo(); break;
            case 0: return 0;
            default: printf("Invalid option.\n");
        }
    }
}
