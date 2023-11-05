<<<<<<< HEAD
//
// Created by Oleg on 03.11.2023.
//

#include "task1.h"
#include "Database.h"
#include <stdio.h>

void T1(){
    printf("T1 is started\n");

    int* G1;
    int x1, b1;
    //1. Чекати на введення D, MM, p в задачі T2
    WaitForSingleObject(Sem.S2, INFINITE);
    //2. Чекати на обчислення DMMME в задачі Т2
    WaitForSingleObject(Eve.E134_2, INFINITE);
    //3. Обчислення G1 = sort(DMMME)*p
    G1 = bubbleSort(DMMME, N);
    for(int i = 0; i < N; ++i){
        G1[i] = G1[i] * p;
    }
    //4. Обчислення G = sort(G1);
    WaitForSingleObject(Mut.M, INFINITE);
    G = bubbleSort(G1, N);
    ReleaseMutex(Mut.M);
    //5. Подати сигнал задачі Т2 про завершення обчислень G
    //6. Подати сигнал задачі Т3 про завершення обчислень G
    //7. Подати сигнал задачі Т4 про завершення обчислень G
    SetEvent(Eve.E1_G);
    //8. Чекати на завершення обчислень G в Т2
    WaitForSingleObject(Eve.E2_G, INFINITE);
    //9. Чекати на завершення обчислень G в Т3
    WaitForSingleObject(Eve.E3_G, INFINITE);
    //10. Чекати на завершення обчислень G в Т4
    WaitForSingleObject(Eve.E4_G, INFINITE);
    //11. Чекати на введення B, E в задачі Т3
    WaitForSingleObject(Sem.S3, INFINITE);
    //12. Чекати на введення C, A, x в задачі Т4
    WaitForSingleObject(Sem.S4, INFINITE);
    //13. Обчислення b1 = (B*C)
    b1 = VecMul(B, C, N);
    //14. Обчислення b = (b + b1);
    WaitForSingleObject(Mut.M, INFINITE);
    b = b1;
    ReleaseMutex(Mut.M);
    //15. Подати сигнал задачі Т2 про завершення обчислень b
    //16. Подати сигнал задачі Т3 про завершення обчислень b
    //17. Подати сигнал задачі Т4 про завершення обчислень b
    SetEvent(Eve.E1_b);
    //18. Чекати на завершення обчислень b в Т2
    WaitForSingleObject(Eve.E2_b, INFINITE);
    //19. Чекати на завершення обчислень b в Т3
    WaitForSingleObject(Eve.E3_b, INFINITE);
    //20. Чекати на завершення обчислень b в Т4
    WaitForSingleObject(Eve.E4_b, INFINITE);
    //21. Копіювати G1 = G
    WaitForSingleObject(Mut.M, INFINITE);
    G1 = G;
    ReleaseMutex(Mut.M);
    //22. Копіювати b1 = b
    EnterCriticalSection(&CS);
    b1 = b;
    LeaveCriticalSection(&CS);
    //23. Копіювати x1 = x
    WaitForSingleObject(Mut.M, INFINITE);
    x1 = x;
    ReleaseMutex(Mut.M);
    //24. Обчислення A = G1 + b1 * E * x1
    calcA(newA,G1, E, b1, x1, N);
    //25. Подати сигнал Т4 про завершення обчислень A
    SetEvent(Eve.E1_A);


    printf("T1 is finished\n");

}
=======
#include "Database.h"
#include <stdio.h>
void T1()
{
	printf("T1 is started\n");
    printf("T1 is finished\n");
}
>>>>>>> 4b2c8bc630ee0eec4b74e17dd50d9e596dda2f4e
