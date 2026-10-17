#include "arrays.h"
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
//программа
int main(void) {
    //устанавливаем utf8
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    int n, m;
    double A[CAPACITY];
    double B[CAPACITY];
    double parametr[3];

    n = read_array(A,CAPACITY);
    if(n == 0){
        printf("ошибка ввода\n");
        return 1;
    }

    m = read_length(CAPACITY);
    if(m == 0){
        printf("ошибка ввода\n");
        return 1;
    }

    if(read_params(parametr) == 0){
        printf("ошибка ввода\n");
        return 1;
    }

    printf("A:\n");
    print_array(A,n);

    build_b(B, m, parametr[0], parametr[1], parametr[2]);

    printf("B:\n");
    print_array(B,m);

    printf("B после удаления:\n");
    int len_new_B = dell_el_first_max(B, m);
    if(len_new_B == -1){
        printf("массив пуст\n");
    }
    else{
        print_array(B,len_new_B);
    }

    printf("A после вставки:\n");
    int len_new_A = cope_el_end(A,n,CAPACITY);
    if(len_new_A == -1){
        printf("массив переполнен\n");
        len_new_A = n;
    }
    else{
        print_array(A,len_new_A);
    }

    printf("A после изменения:\n");
    replace_fads(A,len_new_A);
    print_array(A,len_new_A);

    return 0;
}
