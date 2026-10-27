#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_natural_string(const char *str) {
    if (str[0]=='\0'|| str[0]=='0' || str[0]=='-') {
        return 0;
    }
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]<'0' || str[i]>'9') {
            return 0;
        }
    }
    return 1;
}
int is_integer_string(const char *str) {
    int start=0;
    if (str[0]=='-' || str[0]=='+') {
        start+=1;
    }
    if (str[start]=='\0') {
        return 0;
    }
    for (int i=start; str[i]!='\0'; i++) {
        if (str[i]<'0' || str[i]>'9') {
            return 0;
        }
    }
    return 1;
}
int is_float_string(const char *str) {
    int start=0;
    if (str[0]=='-' || str[0]=='+') {
        start+=1;
    }
    if (str[start]=='\0') {
        return 0;
    }
    int dot_count=0;
    int digit_count=0;
    for (int i=start; str[i]!='\0'; i++) {
        if (str[i]=='.') {
            dot_count++;
            if (dot_count>1) {
                return 0;
            }
        } else if (str[i]>='0' && str[i]<='9') {
            digit_count++;
        } else {
            return 0;
        }
    }
    if (digit_count==0) {
        return 0;
    }
    return 1;
}
int main() {
    char *N_str=NULL;
    char *M_str=NULL;
    int M,N;
    while (1) {
        printf("Введите N: ");
        if (scanf("%ms",&N_str)!=1) {
            printf("Ошибка чтения.\n");
            free(N_str);
            continue;
        }
        if (is_natural_string(N_str)) {
            N=atoi(N_str);
            free(N_str);
            break;
        } else {
            free(N_str);
            printf("Число должно быть натуральным!\n");
        }
    }
    while (1) {
        printf("Введите M: ");
        if (scanf("%ms", &M_str) !=1) {
            printf("Ошибка чтения.\n");
            free(M_str);
            continue;
        }
        if (is_natural_string(M_str)) {
            M=atoi(M_str);
            free(M_str);
            break;
        } else {
            printf("Число должно быть натуральным!\n");
            free(M_str);
        }   
    }

    float *Matrix=malloc(M*N*sizeof(*Matrix));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char *element=NULL;
            float value;
            while (1) {
                printf("Введите элемент [%i][%i]: ",i,j);
                if (scanf("%ms", &element) !=1) {
                    printf("Ошибка чтения.\n");
                    free(element);
                    continue;
                }
                if (is_float_string(element)) {
                    value=atof(element);
                    free(element);
                    break;
                } else {
                    free(element);
                    printf("Некорректный ввод!\n");
                }
            }
            Matrix[i*M+j]=value;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++){
            printf("| %f |", Matrix[i*M+j]);
        }
        printf("\n");
    }
    // пункт 1: максимум над побочной диагональю и его местоположение
    if (M>1){
        float max=-999999.0; // Инициализируем заведомо маленьким числом
        int mi=0,mj=0;
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (i+j<M-1 && j>i){ //Условие нахождения над побочной диагональю
                    if (Matrix[i*M+j]>max){
                        max=Matrix[i*M+j];
                        mi=i;
                        mj=j;
                    }
                }
            }
        }
        printf("Максимум: %f, позиция [%i][%i]\n", max, mi,mj);
    } else {
        printf("Над побочной диагональю нет элементов.\n");
    }
    // пункт 2: количество положительных во 2-й строке и произведение sin
    if (N>1) {
        int k=0;
        double P=1.0;
        for (int j=0; j<M; j++) {
            float a=Matrix[M+j];
            if (a>0) {
                k++;
                P*=sin(a);
            }
        }
        printf("Положительных: %i, P=%lf\n", k, P);
    } else {
        printf("В матрице нет 2-й строки.\n");
    }
    free (Matrix); // очистка памяти.
    return 0;
} 
