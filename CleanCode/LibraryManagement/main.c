#include <stdio.h>
#include "Book\book.h"
#include "User\user.h"
#include "Borrow\borrow.h"

void showMenu() {
    printf("\n===== LIBRARY MENU =====\n");
    printf("1. Add Book\n");
    printf("2. Edit Book\n");
    printf("3. Delete Book\n");
    printf("4. Add User\n");
    printf("5. Edit User\n");
    printf("6. Delete User\n");
    printf("7. Borrow Book\n");
    printf("8. Return Book\n");
    printf("9. Search Books\n");
    printf("10. List Available Books\n");
    printf("11. Show User Info\n");
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
            case 5: editUser(); break;
            case 6: deleteUser(); break;
            case 7: borrowBook(); break;
            case 8: returnBook(); break;
            case 9: searchBooks(); break;
            case 10: listAvailableBooks(); break;
            case 11: showUserInfo(); break;
            case 0: return 0;
            default: printf("Invalid option.\n");
        }
    }
}
