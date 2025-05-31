#ifndef USER_H
#define USER_H

#define MAX_USERS 100
#define MAX_BORROWED_BOOKS 10

typedef struct {
    char name[100];
    int id;
    int borrowedBookIds[MAX_BORROWED_BOOKS];
    int borrowedCount;
} User;

extern User users[MAX_USERS];
extern int userCount;

User* findUserById(int id);
void addUser();
void deleteUser();
void showUserInfo();

#endif
