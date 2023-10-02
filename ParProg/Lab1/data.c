#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
/*
 * data.c
 * Written by Oleh Bielov
 */
typedef struct{
    int size;
    int choice;
} THDATA;

THDATA data;

// перевірка на пустий рядок
bool line_is_empty(const char *str){
    while(*str){
        if(!isspace((unsigned char) *str)){
            return false;
        }
        str++;
    }
    return true;
}

// заповнення вектора через клавіатуру
// виконується при N <= 3
void fillVectorViaKeyboard(int vector[], int N)
{
    printf("Enter %d values for vector\n", N);
    for(int i = 0; i < N; ++i){
        if(scanf("%d", &vector[i]) == EOF){
            perror("cannot convert input value\n");
            exit(-1);
        }
        printf("you have entered: %d\n", vector[i]);
    }
}

// заповнення матриці через клавіатуру
void fillMatrixViaKeyboard(int matrix[data.size][data.size], int N){
    printf("Enter %d values for vector\n", N*N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j) {
            if (scanf("%d", &matrix[i][j]) == EOF) {
                perror("cannot convert input value\n");
                exit(-1);
            }
            printf("you have entered: %d\n", matrix[i][j]);
        }
    }
}

// заповнення вектора випадковими велечинами
void vecOfRandomNums(int vector[], int length, int max)
{
    for(int i = 0; i < length; ++i){
        vector[i] = (rand() % max) + 1;
    }
}


#define BUFFER_SIZE 1024
// створення та заповнення вектора за допомогою файла
void creatingAndFillingVecWithFile(int arr[], const char *file_path, int N)
{
    FILE *in;

    in = fopen(file_path, "a");
    if(in == NULL){
        fputs("Cannot open file\n", stderr);
        exit(1);
    }

    int counter = 0;
    while(counter++ < N)
    {
        int rVal = (rand() % 10) + 1;
        fprintf(in, "%d\n", rVal);

    }
    fclose(in);

    in = fopen(file_path, "r");
    if(in == NULL){
        fputs("Cannot open file\n", stderr);
        exit(1);
    }
    char line[BUFFER_SIZE];
    int line_number = 0;
    while(fgets(line, sizeof(line), in)){
        int temp = atoi(line);
        if(line_is_empty(line)){
            break;
        }
        arr[line_number] = temp;
        line_number++;
    }

    fclose(in);

}

// заповнення всіх значь вектора фіксованим значенням, який задає користувач
void SetAllVal(int vector[], int num, int N)
{
    for(int i = 0; i < N; ++i){
        vector[i] = num;
    }
}
