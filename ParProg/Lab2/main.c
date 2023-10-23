//
// Created by Oleg on 23.10.2023.

#include "main.h"
#include <stdbool.h>
#include <stdio.h>


#define STACK_SIZE (32*1024*1024) // 32 Мб

typedef LPTHREAD_START_ROUTINE LPTSR;

void F1();
void F2();
void F3();

int Buf = 100;
S1 = CreateSemaphore(NULL, 1, 1, NULL);
S2 = CreateSemaphore(NULL, 0, 1, NULL);
S3 = CreateSemaphore(NULL, 0, 1, NULL);

int main(){
    int* S1, S2, S3;
    HANDLE T1, T2, T3;
    DWORD Tid1, Tid2, Tid3;
    int* R1, R2, R3;

    T1 = CreateThread(NULL, STACK_SIZE, (LPTSR)F1, &S1, 0, &Tid1);
    R1 = ReleaseSemaphore(*S2, 1, NULL);

    T2 = CreateThread(NULL, STACK_SIZE, (LPTSR)F2, &S2, 0, &Tid2);
    R1 = ReleaseSemaphore(*S3, 1, NULL);

    T3 = CreateThread(NULL, STACK_SIZE, (LPTSR)F3, &S3, 0, &Tid3);

    WaitForSingleObject(T1, INFINITE);
    WaitForSingleObject(T2, INFINITE);
    WaitForSingleObject(T3, INFINITE);

    CloseHandle(T1);
    CloseHandle(T2);
    CloseHandle(T3);

    return 0;
}

void F1(int* S)
{
    if(*S) {
        printf("F1 is running\n");
        printf("Buf before changes in F1: %d\n", Buf);
        Buf = 120;
        printf("after changes in F1: %d\n", Buf);
        printf("F1 is finished\n");
    }
    //printf("F1 working");
}

void F2(int* S)
{
    if(*S) {
        printf("F2 is running\n");
        printf("Buf before changes in F2: %d\n", Buf);
        Buf = 140;
        printf("after changes in F2: %d\n", Buf);
        printf("F2 is finished\n");
    }
    //printf("F2 working");
}

void F3(int* S)
{
    if(*S){
        printf("F3 is running\n");
        printf("Buf before changes in F3: %d\n", Buf);
        Buf = 160;
        printf("after changes in F3: %d\n", Buf);
        printf("F3 is finished\n");
    }
    //printf("F3 working");
}