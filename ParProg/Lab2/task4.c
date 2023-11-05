//
// Created by Oleg on 03.11.2023.
//

#include "task4.h"
#include "Database.h"
#include <stdio.h>

void T4(){
    printf("T4 is started\n");

    int* G4;
    int x4, b4;

    //1. Уведення C, A, x
    fillVector(C, N);
    fillVector(A, N);
    x = 2;
    //2. Подати сигнал задачі Т1 про введення C, A, x
    //3. Подати сигнал задачі Т2 про введення C, A, x
    //4. Подати сигнал задачі Т3 про введення C, A, x
    ReleaseSemaphore(Sem.S4, 3, NULL);
    //5.Чекати на введення D, MM, p в задачі Т2
    WaitForSingleObject(Sem.S2, 300);
    //6. Чекати на обчислення DMMME в задачі Т2
    WaitForSingleObject(Eve.E134_2, INFINITE);
    //7. Обчислення G4 = sort(DMMME)*p
    G4 = bubbleSort(DMMME, N);
    for(int i = 0; i < N; ++i){
        G4[i] = G4[i] * p;
    }
    //8. Обчислення G = sort(G3);
    WaitForSingleObject(Mut.M, INFINITE);
    G = bubbleSort(G4, N);
    ReleaseMutex(Mut.M);
    //9. Подати сигнал задачі Т1 про завершення обчислень G
    //10. Подати сигнал задачі Т2 про завершення обчислень G
    //11. Подати сигнал задачі Т3 про завершення обчислень G
    SetEvent(Eve.E4_G);
    //12. Чекати на завершення обчислень G в Т1
    WaitForSingleObject(Eve.E1_G, INFINITE);
    //13. Чекати на завершення обчислень G в Т2
    WaitForSingleObject(Eve.E2_G, INFINITE);
    //14. Чекати на завершення обчислень G в Т3
    WaitForSingleObject(Eve.E3_G, INFINITE);
    //15. Чекати на введення B, E в задачі Т3
    WaitForSingleObject(Sem.S3, INFINITE);
    //16. Обчислення b4 = (B*C)
    b4 = VecMul(B, C, N);
    //17. Обчислення b = (b + b4);
    WaitForSingleObject(Mut.M, INFINITE);
    b = b4;
    ReleaseMutex(Mut.M);
    //18. Подати сигнал задачі Т1 про завершення обчислень b
    //19. Подати сигнал задачі Т2 про завершення обчислень b
    //20. Подати сигнал задачі Т3 про завершення обчислень b
    SetEvent(Eve.E4_b);
    //21. Чекати на завершення обчислень b в Т1
    WaitForSingleObject(Eve.E1_b, INFINITE);
    //22. Чекати на завершення обчислень b в Т2
    WaitForSingleObject(Eve.E2_b, INFINITE);
    //23. Чекати на завершення обчислень b в Т3
    WaitForSingleObject(Eve.E3_b, INFINITE);
    //24. Копіювати G4 = G
    WaitForSingleObject(Mut.M, INFINITE);
    G4 = G;
    ReleaseMutex(Mut.M);
    //25. Копіювати b1 = b
    EnterCriticalSection(&CS);
    b4 = b;
    LeaveCriticalSection(&CS);
    //26. Копіювати x1 = x
    WaitForSingleObject(Mut.M, INFINITE);
    x4 = x;
    ReleaseMutex(Mut.M);
    //27. Обчислення A = G1 + b1 * E * x1
    calcA(newA,G4, E, b4, x4, N);
    //28. Чекати на завершення обчислень А в Т1
    WaitForSingleObject(Eve.E1_A, INFINITE);
    //29. Чекати на завершення обчислень А в Т2
    WaitForSingleObject(Eve.E2_A, INFINITE);
    //30. Чекати на завершення обчислень А в Т3
    WaitForSingleObject(Eve.E3_A, INFINITE);
    //31. Виведення результату А
    printf("A = {");
    for(int i = 0; i < N-1; ++i){
        printf("%d, ", newA[i]);
    }
    printf("%d}\n", newA[N-1]);

    printf("T4 is finished\n");
}
