#ifndef LAB2_DATABASE_H
#define LAB2_DATABASE_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

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

