//
// Created by Oleg on 03.11.2023.
//

#include "task2.h"
#include "Database.h"
#include <stdio.h>

void T2(){
    printf("T2 is started\n");

    int* G2;
    int x2, b2;

    //1. Уведення D, MM, p
    fillVector(D, N);
    fillMatrix(MM, N);
    p = 2;
    //2. Подати сигнал задачі Т1 про введення D, MM, p
    //3. Подати сигнал задачі Т3 про введення D, MM, p
    //4. Подати сигнал задачі Т4 про введення D, MM, p
    ReleaseSemaphore(Sem.S2, 3, NULL);
    //5. Чекати на введення ME, B, E, в задачі Т3
    WaitForSingleObject(Sem.S3, INFINITE);
    //6. Обчислення DMMME = D*(MM*ME)
    EnterCriticalSection(&CS);
    VecAndMatMult(D, MM, ME);
    LeaveCriticalSection(&CS);
    //7. Подати сигнал задачі Т1 про обчислення DMMME
    //8. Подати сигнал задачі Т3 про обчислення DMMME
    //9. Подати сигнал задачі Т4 про обчислення DMMME
    SetEvent(Eve.E134_2);
    //10. Обчислення G2 = sort(DMMME)*p
    G2 = bubbleSort(DMMME, N);
    for(int i = 0; i < N; ++i){
        G2[i] = G2[i] * p;
    }
    //11. Обчислення G = sort(G2);
    WaitForSingleObject(Mut.M, INFINITE);
    G = bubbleSort(G2, N);
    ReleaseMutex(Mut.M);
    //12. Подати сигнал задачі Т1 про завершення обчислень G
    //13. Подати сигнал задачі Т3 про завершення обчислень G
    //14. Подати сигнал задачі Т4 про завершення обчислень G
    SetEvent(Eve.E2_G);
    //15. Чекати на завершення обчислень G в Т1
    WaitForSingleObject(Eve.E1_G, INFINITE);
    //16. Чекати на завершення обчислень G в Т3
    WaitForSingleObject(Eve.E3_G, INFINITE);
    //17. Чекати на завершення обчислень G в Т4
    WaitForSingleObject(Eve.E4_G, INFINITE);
    //18. Чекати на введення C, A в задачі Т4
    WaitForSingleObject(Sem.S4, INFINITE);
    //19. Обчислення b2 = (B*C)
    b2 = VecMul(B, C, N);
    //20. Обчислення b = (b + b2);
    WaitForSingleObject(Mut.M, INFINITE);
    b = b2;
    ReleaseMutex(Mut.M);
    //21. Подати сигнал задачі Т1 про завершення обчислень b
    //22. Подати сигнал задачі Т3 про завершення обчислень b
    //23. Подати сигнал задачі Т4 про завершення обчислень b
    SetEvent(Eve.E2_b);
    //24. Чекати на завершення обчислень b в Т1
    WaitForSingleObject(Eve.E1_b, INFINITE);
    //25. Чекати на завершення обчислень b в Т3
    WaitForSingleObject(Eve.E3_b, INFINITE);
    //26. Чекати на завершення обчислень b в Т4
    WaitForSingleObject(Eve.E4_b, INFINITE);
    //27. Копіювати a1 = a
    WaitForSingleObject(Mut.M, INFINITE);
    G2 = G;
    ReleaseMutex(Mut.M);
    //28. Копіювати b1 = b
    EnterCriticalSection(&CS);
    b2 = b;
    LeaveCriticalSection(&CS);
    //29. Копіювати x1 = x
    WaitForSingleObject(Mut.M, INFINITE);
    x2 = x;
    ReleaseMutex(Mut.M);
    //30. Обчислення A = G2 + b2 * E * x2
    calcA(newA,G2, E, b2, x2, N);
    //31. Подати сигнал Т4 про завершення обчислень A
    SetEvent(Eve.E2_A);

    printf("T2 is finished\n");
}