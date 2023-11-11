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
    hThreads[0] = CreateThread(NULL, STACK_SIZE, (LPTSR) T1, NULL, 0, &Tid[0]);
    hThreads[1] = CreateThread(NULL, STACK_SIZE, (LPTSR) T2, NULL, 0, &Tid[1]);
    hThreads[2] = CreateThread(NULL, STACK_SIZE, (LPTSR) T3, NULL, 0, &Tid[2]);
    hThreads[3] = CreateThread(NULL, STACK_SIZE, (LPTSR) T4, NULL, 0, &Tid[3]);

    for (int k = 0; k < THREADS; ++k) {
        WaitForSingleObject(hThreads[k], INFINITE);
    }

    DeleteCriticalSection(&CS);

    for (int i = 0; i < THREADS; ++i) {
        CloseHandle(hThreads[i]);
    }

    return 0;
}
