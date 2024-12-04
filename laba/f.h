#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

#define scanf scanf_s

void swap(double*, double*);
double* arrayAllocat(int);
void arrayFillRand(double*, int);
void arrayFillRandomInRange(double*, int);
void arrayFillUser(double*, int);
void arrayPrint(double*, int);

void bubbleSort(double*, int);
void merge(double*, int, int, int);
void mergeSort(double*, int, int);
void insertSort(double*,int);
void selectionSort(double*, int);
void quickSort(double*, int, int);