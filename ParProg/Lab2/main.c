<<<<<<< HEAD
/*
 * Паралельне програмування
 * Лабораторна роботи №2
 * Автор: Бєлов Олег Данилович
 * Група ЫО-11
 * Варіант 4
 * A = sort(D*(ME*MM))*p + (B*C)*E*x
 * Дата сворення: 04.11.2023
 */

#include <stdio.h>
#include "Database.h"

#define THREADS 4
#define STACK_SIZE (64*1024*1024)

typedef LPTHREAD_START_ROUTINE LPTSR;

int main() {
    HANDLE hThreads[THREADS];
    DWORD Tid[THREADS];

    //Ініціалізуємо всі спільні ресурси
    initCP();

    InitializeCriticalSection(&CS);
    hThreads[0] = CreateThread(NULL, STACK_SIZE, (LPTSR)T1, NULL, 0, &Tid[0]);
    hThreads[1] = CreateThread(NULL, STACK_SIZE, (LPTSR)T2, NULL, 0, &Tid[1]);
    hThreads[2] = CreateThread(NULL, STACK_SIZE, (LPTSR)T3, NULL, 0, &Tid[2]);
    hThreads[3] = CreateThread(NULL, STACK_SIZE, (LPTSR)T4, NULL, 0, &Tid[3]);

    for(int k = 0; k < THREADS; ++k){
        WaitForSingleObject(hThreads[k], INFINITE);
    }

    DeleteCriticalSection(&CS);

    for(int i = 0; i < THREADS; ++i){
        CloseHandle(hThreads[i]);
    }

    return 0;
=======
//
// Created by Oleg on 23.10.2023.
// var: A = sort(D*(ME*MM))*p + (B*C)*E*x - вектор


#include <stdio.h>
#include <windows.h>
#include "Database.h"

#define THREADS 4
#define STACK_SIZE (32*1024*1024)


typedef LPTHREAD_START_ROUTINE LPTSR;

int main(void)
{
	HANDLE hThreadArray[THREADS];
    DWORD Tid[THREADS];
	printf(" Test Test Test");
	hThreadArray[0] = CreateThread(NULL, STACK_SIZE, (LPTSR)T1, NULL, 0, &Tid[0]);
	hThreadArray[1] = CreateThread(NULL, STACK_SIZE, (LPTSR)T2, NULL, 0, &Tid[1]);
    hThreadArray[2] = CreateThread(NULL, STACK_SIZE, (LPTSR)T3, NULL, 0, &Tid[2]);
    hThreadArray[3] = CreateThread(NULL, STACK_SIZE, (LPTSR)T4, NULL, 0, &Tid[3]);


    WaitForSingleObject(hThreadArray[0], INFINITE);
    WaitForSingleObject(hThreadArray[1], INFINITE);
    WaitForSingleObject(hThreadArray[2], INFINITE);
    WaitForSingleObject(hThreadArray[3], INFINITE);
    
	for(int i = 0; i < THREADS; ++i){
    	CloseHandle(hThreadArray[i]);
    }
    
    
	return 0;
>>>>>>> 4b2c8bc630ee0eec4b74e17dd50d9e596dda2f4e
}
