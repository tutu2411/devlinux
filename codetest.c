#include <stdio.h>

int main() {
    int arr[4] = {1,2,3,4};
    int b = 123;
    printf("Kich thuoc mot phan tu int: %zu byte\n", sizeof(arr[0]));
    printf("Kich thuoc mot phan tu int: %d\n", *(arr));
    printf("Kich thuoc mot phan tu int: %d\n", *(arr + 1));
    printf("Kich thuoc mot phan tu int: %d\n", *(arr + 2));
    printf("Kich thuoc mot phan tu int: %d\n", *(arr + 3));
    
    printf("b address: %p\n", &b);
    printf("&(arr + 4) address: %p\n", (arr + 4));
    return 0;
}
