#ifndef ARRAYS_H
#define ARRAYS_H

#define CAPACITY 20
//Ввод
int read_array(double A[], int capacity);//ввод массива
int read_length(int capacity);//ввод длины,проверка на правельность
int read_params(double param[]);//ввод параметров :a, x, h

//Модификации
void build_b(double B[],int m, double a, double x,double h);//генерация массива B
int dell_el_first_max(double B[],int m);//удаление отрицатенльных элементов до первого максимума
int cope_el_end(double A[],int n,int capacity);//копия последнего элемента в конец
void replace_fads(double A[],int n);//элементы с fabs(A[i]) < 1 на 1

//Вывод
void print_array(const double A[], int n);//вывод

#endif

