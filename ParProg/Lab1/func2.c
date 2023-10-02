//F2: 2.17 ==> h = MAX(MF + MG*(MH * ML)), h - скаляр
#include <stdio.h>
#include "func2.h"
#include "data.h"
#include <limits.h>
/*
 * func2.c
 * Written by Oleh Bielov
 */
int findMax(int matrix[data.size][data.size], int row, int column) {
    int max = INT_MIN;

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }

    return max;
}

void F2()
{
    printf("\nThread T2 is started\n");
    int N, choice;
    N = data.size;
    choice = data.choice;
    // Локальні змінні для потоку T2
    int h;
    int MF[N][N], MG[N][N], MH[N][N], ML[N][N];
    int MHML[N][N], MGMHML[N][N], MS[N][N];

    if (N <= 3) {
        fillMatrixViaKeyboard(MF, N);
        fillMatrixViaKeyboard(MG, N);
        fillMatrixViaKeyboard(MH, N);
        fillMatrixViaKeyboard(ML, N);

    } else {
        switch(choice) {
            case 1:
                for(int i = 0; i < N; ++i){
                    vecOfRandomNums(MF[i], N, 10);
                    vecOfRandomNums(MG[i], N, 10);
                    vecOfRandomNums(MH[i], N, 10);
                    vecOfRandomNums(ML[i], N, 10);
                }
                break;
            case 2: {
                for(int i = 0; i < N; ++i){
                    creatingAndFillingVecWithFile(MF[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MF.txt", N);
                    creatingAndFillingVecWithFile(MG[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MG.txt", N);
                    creatingAndFillingVecWithFile(MH[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MH.txt", N);
                    creatingAndFillingVecWithFile(ML[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\ML.txt", N);
                }
                break;
            }
            case 3: {
                int num;
                printf("Enter num: \n");
                scanf("%d", &num);
                for(int i = 0; i < N; ++i){
                    SetAllVal(MF[i], num, N);
                    SetAllVal(MG[i], num, N);
                    SetAllVal(MH[i], num, N);
                    SetAllVal(ML[i], num, N);
                }
                break;
            }
        }
        //множення матриць MH на ML
        for(int row = 0; row < N; ++row){
            for(int column = 0; column < N; ++column){
                MHML[row][column] = 0;
                for(int k = 0; k < N; k++){
                    MHML[row][column] += MH[row][k] * ML[k][column];
                }
            }
        }

        //множення матриць MG та MHML
        for(int row = 0; row < N; ++row){
            for(int column = 0; column < N; ++column){
                MGMHML[row][column] = 0;
                for(int k = 0; k < N; k++){
                    MGMHML[row][column] += MG[row][k] * MHML[k][column];
                }
            }
        }

        // множення матриць MF та MGMHML
        for(int row = 0; row < N; ++row){
            for(int column = 0; column < N; ++column){
                MS[row][column] = MF[row][column] + MGMHML[row][column];
            }
        }

        // вкликаємо функцію findMax щоб знайти найбільше значення в матриці
        h = findMax(MS, N, N);

        printf("h = %d\n", h);


    }

    printf("\nThread T2 is finished.\n");


}