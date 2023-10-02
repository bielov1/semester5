#ifndef LAB1_DATA_H
#define LAB1_DATA_H
/*
 * Data.h
 * Written by Oleh Bielov
 */
typedef struct{
    int size;
    int choice;
} THDATA;

extern THDATA data;

void fillMatrixViaKeyboard(int matrix[data.size][data.size], int N);
void fillVectorViaKeyboard(int vector[], int length);
void vecOfRandomNums(int vector[], int length, int max);
void creatingAndFillingVecWithFile(int arr[], const char *file_path, int N);
void SetAllVal(int vector[], int num, int N);
#endif //LAB1_DATA_H
