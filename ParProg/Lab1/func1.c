// d = (B*C) + (A*B) + (C*(B*(MA*ME)))
#include <stdio.h>
#include "func1.h"
#include "data.h"
/*
 * func1.c
 * Written by Oleh Bielov
 */

void F1() {
    printf("\nThread T1 is started\n");
    int N, choice;
    N = data.size;
    choice = data.choice;
    // Локальні змінні для потоку T1
    long long int d;
    int A[N], B[N], C[N], D[N], e3 = 0, e2 = 0, e1 = 0;

    int MA[N][N], ME[N][N], MAME[N][N];

    if (N <= 3) {
        fillVectorViaKeyboard(A, N);
        fillVectorViaKeyboard(B, N);
        fillVectorViaKeyboard(C, N);

        fillMatrixViaKeyboard(MA, N);
        fillMatrixViaKeyboard(ME, N);

    } else {
        switch(choice) {
            case 1:
                vecOfRandomNums(A, N, 10);
                vecOfRandomNums(B, N, 10);
                vecOfRandomNums(C, N, 10);

                for(int i = 0; i < N; ++i){
                    vecOfRandomNums(MA[i], N, 10);
                    vecOfRandomNums(ME[i], N, 10);
                }
                break;
            case 2: {
                creatingAndFillingVecWithFile(A, "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\A.txt", N);
                creatingAndFillingVecWithFile(B, "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\B.txt", N);
                creatingAndFillingVecWithFile(C, "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\C.txt", N);

                for(int i = 0; i < N; ++i){
                    creatingAndFillingVecWithFile(MA[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\MA.txt", N);
                    creatingAndFillingVecWithFile(ME[i], "G:\\Gbin\\SemesterFifth\\ParProg\\Lab1\\txt_stack\\ME.txt", N);
                }

                break;
            }
            case 3: {
                int num;
                printf("Enter num: \n");
                scanf("%d", &num);
                SetAllVal(A, num, N);
                SetAllVal(B, num, N);
                SetAllVal(C, num, N);

                for(int i = 0; i < N; ++i){
                    SetAllVal(MA[i], num, N);
                    SetAllVal(ME[i], num, N);
                }
                break;
            }
        }

    }

    //множення матриць MA на ME
    for(int row = 0; row < N; ++row){
        for(int column = 0; column < N; ++column){
            MAME[row][column] = 0;
            for(int k = 0; k < N; k++){
                MAME[row][column] += MA[row][k] * ME[k][column];
            }
        }
    }


    //множення вектора B(1,N) на матрицю MAME(N, N)
    for(int i = 0; i < N; ++i){
        D[i] = 0;
        for(int j = 0; j < N; ++j){
            D[i] += B[j] * MAME[j][i];
        }
    }

    //множення вектора C на вектор D
    for(int i = 0; i < N; ++i){
        e3 += C[i] * D[i];
    }

    // множження вектора A на B
    for(int i = 0; i < N; ++i){
        e2 += A[i] * B[i];
    }

    // множення вектора B на C
    for(int i = 0; i < N; ++i){
        e1 += B[i] * C[i];
    }

    // результат d - скаляр
    d = e1 + e2 + e3;

    printf("d = %lld\n", d);

    printf("\nThread T1 is finished.\n");
}

