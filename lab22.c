#include <stdio.h>

int count(int a, int n){
    if (a > (n - a)){
        return 0;
    }
    return 1 + count(a + 1, n);
}

int main(void){
    int n;
    printf("Введите натуральное число N: ");
    scanf("%d", &n);
    if (n != 1){
        if (n < 1){
            return 1;
        }
    }
    printf("Количество разбиен: %d\n", count(1,n));

    return 0;
}