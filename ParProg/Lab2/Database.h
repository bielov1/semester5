<<<<<<< HEAD
//
// Created by Oleg on 03.11.2023.
//

#ifndef LAB2_DATABASE_H
#define LAB2_DATABASE_H

=======
#ifndef LAB2_DATABASE_H
#define LAB2_DATABASE_H


#define WIN32_LEAN_AND_MEAN
>>>>>>> 4b2c8bc630ee0eec4b74e17dd50d9e596dda2f4e
#include <windows.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

<<<<<<< HEAD
#define N 1024

typedef struct{
    HANDLE S2;
    HANDLE S3;
    HANDLE S4;
}Semaphore;

typedef struct{
    HANDLE E1_G;
    HANDLE E2_G;
    HANDLE E3_G;
    HANDLE E4_G;
    HANDLE E1_b;
    HANDLE E2_b;
    HANDLE E3_b;
    HANDLE E4_b;
    HANDLE E1_A;
    HANDLE E2_A;
    HANDLE E3_A;
    HANDLE E4_A;
    HANDLE E134_2;
}Event;

typedef struct{
    HANDLE M;
}Mutex;



extern Semaphore Sem;
extern Event Eve;
extern Mutex Mut;

extern CRITICAL_SECTION CS;

extern int MM[N][N], ME[N][N];
extern int B[N], D[N], E[N], C[N], A[N], H[N], newA[N], DMMME[N];
extern int x, p, b;
extern int* G;

void initCP();
void fillVector(int vec[], int n);
void fillMatrix(int mat[N][N], int n);
void VecAndMatMult(int vec[N], int mat1[N][N], int mat2[N][N]);
int* bubbleSort(const int arr[], int n);
void swap(int* xp, int* yp);
int VecMul(int arr1[], int arr2[], int n);
void calcA(int newA[], int arrG[], int arrE[], int b, int x, int n);

#endif //LAB2_DATABASE_H
=======
typedef struct {
	int ME;
    int MM;
} Matrices;

typedef struct {
	int D;
    int B;
    int C;
    int E;
} Vectors;

typedef struct {
	int p;
    int x;
} Scalar;

typedef struct {
	HANDLE S1;
    HANDLE S2;
    HANDLE S3;
}Semaphore;

extern Matrices Mat_t;
extern Vectors Vec_t;
extern Scalar Scal_t;
extern Semaphore Sem_t;


#endif //LAB2_DATABASE_H
x
>>>>>>> 4b2c8bc630ee0eec4b74e17dd50d9e596dda2f4e
