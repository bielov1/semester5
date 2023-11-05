
//
// Created by Oleg on 03.11.2023.
//

#include "task3.h"
#include "Database.h"
#include <stdio.h>

void T3(){
    printf("T3 is started\n");

    int* G3;
    int x3, b3;
    //1. Уведення ME, B, E
    fillVector(B, N);
    fillVector(E, N);
    fillMatrix(ME, N);
    //2. Подати сигнал задачі Т1 про введення ME, B, E
    //3. Подати сигнал задачі Т2 про введення ME, B, E
    //4. Подати сигнал задачі Т4 про введення ME, B, E
    ReleaseSemaphore(Sem.S3, 3, NULL);
    //5.Чекати на введення D, MM, p в задачі Т2
    WaitForSingleObject(Sem.S2, INFINITE);
    //6.Чекати на обчислення DMMME в задачі Т2
    WaitForSingleObject(Eve.E134_2, INFINITE);
    //7. Обчислення G3 = sort(DMMME)*p
    G3 = bubbleSort(DMMME, N);
    for(int i = 0; i < N; ++i){
        G3[i] = G3[i] * p;
    }
    //8. Обчислення G = sort(G3);
    WaitForSingleObject(Mut.M, INFINITE);
    G = bubbleSort(G3, N);
    ReleaseMutex(Mut.M);
    //9. Подати сигнал задачі Т1 про завершення обчислень G
    //10. Подати сигнал задачі Т2 про завершення обчислень G
    //11. Подати сигнал задачі Т4 про завершення обчислень G
    SetEvent(Eve.E3_G);
    //12. Чекати на завершення обчислень G в Т1
    WaitForSingleObject(Eve.E1_G, INFINITE);
    //13. Чекати на завершення обчислень G в Т2
    WaitForSingleObject(Eve.E2_G, INFINITE);
    //14. Чекати на завершення обчислень G в Т4
    WaitForSingleObject(Eve.E4_G, INFINITE);
    //15. Чекати на введення C, A в задачі Т4
    WaitForSingleObject(Sem.S4, INFINITE);
    //16. Обчислення b3 = (B*C)
    b3 = VecMul(B, C, N);
    //17. Обчислення b = (b + b3);
    WaitForSingleObject(Mut.M, INFINITE);
    b = b3;
    ReleaseMutex(Mut.M);
    //18. Подати сигнал задачі Т1 про завершення обчислень b
    //19. Подати сигнал задачі Т2 про завершення обчислень b
    //20. Подати сигнал задачі Т4 про завершення обчислень b
    SetEvent(Eve.E3_b);
    //21. Чекати на завершення обчислень b в Т1
    WaitForSingleObject(Eve.E1_b, INFINITE);
    //22. Чекати на завершення обчислень b в Т2
    WaitForSingleObject(Eve.E2_b, INFINITE);
    //23. Чекати на завершення обчислень b в Т4
    WaitForSingleObject(Eve.E4_b, INFINITE);
    //24. Копіювати G3 = G
    WaitForSingleObject(Mut.M, INFINITE);
    G3 = G;
    ReleaseMutex(Mut.M);
    //25. Копіювати b3 = b
    EnterCriticalSection(&CS);
    b3 = b;
    LeaveCriticalSection(&CS);
    //26. Копіювати x1 = x
    WaitForSingleObject(Mut.M, INFINITE);
    x3 = x;
    ReleaseMutex(Mut.M);
    //27. Обчислення A = G1 + b1 * E * x1
    calcA(newA,G3, E, b3, x3, N);
    //28. Подати сигнал Т4 про завершення обчислень A
    SetEvent(Eve.E3_A);


    printf("T3 is finished\n");
}
