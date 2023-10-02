// Паралельне програмування. ЛР1 "Програмування потоків"
//
// Варіант
// F1: 1.22 ==> d = (B * C) + (A * B) + (C * (B * (MA * ME))), d - скаляр
// F2: 2.17 ==> h = MAX(MF + MG*(MH * ML)), h - скаляр
// F3: 3.13 ==> T = S * (MO * MP) + SORT(S)*MR, T - вектор
//
// Бєлов Олег Данилович, IO-11, 30.09.2023

#include <stdio.h>
#include <windows.h>
#include "data.h"
#include "func1.h"
#include "func2.h"
#include "func3.h"

#define STACK_SIZE (32*1024*1024) // 32 Мб

// Скорочуємо тип на LPTSR
typedef LPTHREAD_START_ROUTINE LPTSR;

int main(void)
{
    int n;

    //введення розмірності векторів та матриць
    printf("N = ");
    scanf("%d", &n);
    printf("\n");
    printf("N = %d\n", n);

    int choice;

    // визначення яким чином заповнювати веткори та матриці
    printf("Please, select number from the given list below that will implement autofill for vectors/matrices\n");
    printf("1: random number generator\n");
    printf("2: using file\n");
    printf("3: fixed number\n");

    scanf("%d", &choice);
    
    data.size = n;
    data.choice = choice;

    // Створення трьох потоків - T1, T2, T3
    HANDLE T1, T2, T3;
    // Індекатори потоків
    DWORD Tid1, Tid2, Tid3;

    // Створення потоків за допомогою функції CreateThread()
    T1 = CreateThread(NULL, STACK_SIZE, (LPTSR)F1, NULL, 0, &Tid1);
    T2 = CreateThread(NULL, STACK_SIZE, (LPTSR)F2, NULL, 0, &Tid2);
    T3 = CreateThread(NULL, STACK_SIZE, (LPTSR)F3, NULL, 0, &Tid3);

    //Встановлення пріоритетності потоків
    // THREAD_PRIORITY_LOWEST - найнижчий пріорітет
    // THREAD_PRIORITY_NORMAL - звичайний пріорітет
    // THREAD_PRIORITY_TIME_CRITICAL - потік отримує найвищий можливий пріоритет
    SetThreadPriority(T1, THREAD_PRIORITY_LOWEST);
    SetThreadPriority(T2, THREAD_PRIORITY_NORMAL);
    SetThreadPriority(T3, THREAD_PRIORITY_TIME_CRITICAL);

    // Обрання ядра для виконання потоку
    SetThreadAffinityMask(T1, 5);
    SetThreadAffinityMask(T2, 3);
    SetThreadAffinityMask(T3, 1);

    // очікування синхронізації роботи потоків або
    // очікування завершення певних дій
    WaitForSingleObject(T1, INFINITE);
    WaitForSingleObject(T2, INFINITE);
    WaitForSingleObject(T3, INFINITE);

    // закриття потоків
    CloseHandle(T1);
    CloseHandle(T2);
    CloseHandle(T3);

    return 0;
}



