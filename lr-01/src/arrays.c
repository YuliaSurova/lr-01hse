#include "arrays.h"
#include <stdio.h>
#include <math.h>
//сами функции

//ввод массива A
int read_array(double A[], int capacity){
    int n;
    if(scanf("%d",&n) != 1){
        return 0;
    }
    if(n > capacity || n < 1){
        return 0;
    }
    for(int i = 0;i < n;i++){
        if(scanf("%lf", &A[i]) != 1){
            return 0;
        }
    }
    return n;
}

//ввод длины,проверка на правельность 
int read_length(int capacity){
    int length;
    if(scanf("%d",&length) != 1){
        return 0;
    }
    if(length > capacity || length < 1){
        return 0;
    }
    return length;
}

//ввод a x h
int read_params(double param[]){
    for(int i = 0;i < 3; i++){
        if(scanf("%lf",&param[i]) != 1){
            return 0;
        }
    }
    return 1;
}

//генерация B
void build_b(double B[],int m, double a, double x,double h){
    for(int i = 0;i < m; i++){
        B[i] = 1.25 * sin(3 * a * x - i * h);
    }
}

//удаление отриц. элементов до первого максимум
int dell_el_first_max(double B[],int m){
    if (m < 1){
        return -1;
    }
    double f_max = B[0];
    int index_first_max = 0;
    for(int i = 1;i < m; i ++){
        if(B[i] > f_max){
            f_max = B[i];
            index_first_max = i;
        }
    }
    int k = 0;
    while(k < index_first_max){
        if(B[k] < 0){
            for(int j = k;j<m-1;j++){
                B[j] = B[j+1];
            }
            m--;
            index_first_max--;
        }
        else{k++;}
    }
    return m;//выводим новую длину
}

//копия последнего элемента в конец
int cope_el_end(double A[],int n ,int capacity){
    if(n == capacity){
        return -1;
    }
    double last_el = A[n-1];
    A[n] = last_el;
    n += 1;
    return n;
}
//элементы с fabs(A[i]) < 1 на 1
void replace_fads(double A[],int n){
    for(int i = 0;i < n; i++){
        if(fabs(A[i]) < 1){
            A[i] = 1;
        }
    }
}

//вывод
void print_array(const double A[], int n){
    for(int i = 0;i < n; i++){
        printf("%.3lf ", A[i]);
    }
    printf("\n");
}