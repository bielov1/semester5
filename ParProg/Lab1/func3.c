//F3: 3.13 ==> T = S * (MO * MP) + SORT(S)*MR, T - вектор
#include <stdio.h>
#include <stdlib.h>
#include "func3.h"
#include "data.h"
/*
 * func3.c
 * Written by Oleh Bielov
 */
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void F3()
{
    printf("\nThread T3 is started\n");

    int N, choice;
    N = data.size;
    choice = data.choice;
    // Локальні змінні для потоку T3
    int T[N];
    int S[N];
    int MO[N][N], MP[N][N], MR[N][N];
    int MOMP[N][N], SMOMP[N], SMR[N];

    if (N <= 3) {
        fillMatrixViaKeyboard(MO, N);
        fillMatrixViaKeyboard(MP, N);
        fillMatrixViaKeyboard(MR, N);
    } else {
        switch(choice) {
            case 1:
                vecOfRandomNums(S, N, 10);

                for(int i = 0; i < N; ++i){
                    vecOfRandomNums(MO[i], N, 10);
                    vecOfRandomNums(MP[i], N, 10);
                    vecOfRandomNums(MR[i], N, 10);
                }
                break;
            case 2: {
                creatingAndFillingVecWithFile(S, "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\S.txt", N);

                for(int i = 0; i < N; ++i){
                    creatingAndFillingVecWithFile(MO[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MO.txt", N);
                    creatingAndFillingVecWithFile(MP[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MP.txt", N);
                    creatingAndFillingVecWithFile(MR[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MR.txt", N);
                }
                break;
            }
            case 3: {
                int num;
                printf("Enter num: \n");
                scanf("%d", &num);

                SetAllVal(S, num, N);

                for(int i = 0; i < N; ++i){
                    SetAllVal(MO[i], num, N);
                    SetAllVal(MP[i], num, N);
                    SetAllVal(MR[i], num, N);
                }
                break;
            }
        }

        //множення матриць MO на MP
        for(int row = 0; row < N; ++row){
            for(int column = 0; column < N; ++column){
                MOMP[row][column] = 0;
                for(int k = 0; k < N; k++){
                    MOMP[row][column] += MO[row][k] * MP[k][column];
                }
            }
        }

        // множення вектора S на матрицю MOMP
        for(int i = 0; i < N; ++i){
            SMOMP[i] = 0;
            for(int j = 0; j < N; ++j){
                SMOMP[i] += S[j] * MOMP[j][i];
            }
        }

        // вкликаэмо функцію qsort, щоб відсортувати вектор S
        qsort(S, N, sizeof(int), cmpfunc);
//        printf("\nAfter sorting the list is: \n");
//        for(int i = 0 ; i < N; i++ ) {
//            printf("%d ", S[i]);
//        }

        // множення вектора S на матрицю MR
        for(int i = 0; i < N; ++i){
            SMR[i] = 0;
            for(int j = 0; j < N; ++j){
                SMR[i] += S[j] * MR[j][i];
            }
        }

        // результат T
        for(int i = 0; i < N; ++i){
            T[i] = SMOMP[i] + SMR[i];
        }

        for(int r = 0; r < N; ++r){
            printf("%2d ", T[r]);
        }

    }

    printf("\nThread T3 is finished.\n");
}