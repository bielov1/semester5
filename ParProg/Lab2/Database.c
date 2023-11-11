//
// Created by Oleg on 03.11.2023.
//

#include <stdbool.h>
#include <stdio.h>
#include "Database.h"

Semaphore Sem;
Event Eve;
Mutex Mut;

CRITICAL_SECTION CS;

int MM[N][N], ME[N][N];
int B[N], D[N], E[N], C[N], A[N], H[N], newA[N], DMMME[N];
int x, p, b;
int* G;

void initCP(){
    Sem.S2 = CreateSemaphore(NULL, 0, 3, NULL);
    Sem.S3 = CreateSemaphore(NULL, 0, 3, NULL);
    Sem.S4 = CreateSemaphore(NULL, 0, 3, NULL);


    Eve.E1_G = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E2_G = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E3_G = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E4_G = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E1_b = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E2_b = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E3_b = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E4_b = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E1_A = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E2_A = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E3_A = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E4_A = CreateEvent(NULL, TRUE, FALSE, NULL);
    Eve.E134_2 = CreateEvent(NULL, TRUE, FALSE, NULL);

    Mut.M = CreateMutex(NULL, FALSE, NULL);
}

void fillVector(int vec[], int n){
    for(int i = 0; i < n; ++i){
        if(n > 7){
            vec[i] = rand() % 10;
        } else{
            vec[i] = 1;
        }
    }
}

void fillMatrix(int mat[N][N], int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) {
            if(n > 7){
                mat[i][j] = rand() % 10;
            } else{
                mat[i][j] = 1;
            }
        }
    }
}

void VecAndMatMult(int vec[N], int mat1[N][N], int mat2[N][N]){
    int tempMat[N][N];
    for(int row = 0; row < N; ++row){
        for(int column = 0; column < N; ++column){
            tempMat[row][column] = 0;
            for(int k = 0; k < N; k++){
                tempMat[row][column] += mat1[row][k] * mat2[k][column];
            }
        }
    }

    for(int i = 0; i < N; ++i){
        DMMME[i] = 0;
        for(int j = 0; j < N; ++j){
            DMMME[i] += vec[j] * tempMat[j][i];
        }
    }
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int *bubbleSort(const int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n; ++i) {
        H[i] = arr[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (H[j] > H[j + 1]) {
                swap(&H[j], &H[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    return H;
}

int VecMul(int arr1[], int arr2[], int n){
    int e = 0;
    for(int i = 0; i < n; ++i){
        e += arr1[i] * arr2[i];
    }
    return e;
}

void calcA(int newA[], int arrG[], int arrE[], int b, int x, int n){
    for(int i  = 0; i < n; ++i){
        newA[i] = arrG[i] + arrE[i] * b * x;
    }
}
