public class T4 extends Thread {
    int k4 = 0;
    int e4 = 0;
    int p4 = 0;
    Data data;
    MyMonitor mon4;

    public T4(MyMonitor mon4, Data data) {
        this.mon4 = mon4;
        this.data = data;
    }
    @Override
    public void run() {
        System.out.println("T4 is started");
        try {
            // 1. Уведення B i p
            for(int i = 0; i < data.N; ++i) {
                data.B[i] = 1;
            }
            data.p = 2;
            mon4.set_p(data.p);
            // 2. Сигнал задачі T1 про введення B i p
            // 3. Сигнал задачі T2 про введення B i p
            // 4. Сигнал задачі T3 про введення B i p
            mon4.signal_In();
            // 5. Чекати на введення MA i C в задачі T2
            // 6. Чекати на введення MD i R в задачі T3
            mon4.wait_In();
            // 7. Обчислення 1: k4 = max(Cн * (MAн * MDн))
            data.MS = data.matricesMultiplication(data.MA, data.MD);
            data.I = data.vecAndMatrixMultiplication(data.C, data.MS);
            k4 = data.findMax(data.I);
            // 8. Обчилсення 2: k = max(k, k4)
            mon4.compute_k(k4);
            // 9. Сигнал задачі T1 про обчислення k
            // 10. Сигнал задачі T2 про обчислення k
            // 11. Сигнал задачі T3 про обчислення k
            mon4.signal_Calc();
            Thread.sleep(100);
            // 12. Чекати на завершення обчислень k в Т1
            // 13. Чекати на завершення обчислень k в Т2
            // 14. Чекати на завершення обчислень k в Т3
            mon4.wait_Calc();
            // 15. Чекати на введення e в задачі T1
            mon4.wait_In();
            // 16. Копіювати k4 = k;
            k4 = mon4.get_k();
            // 17. Копіювати e4 = e;
            e4 = mon4.get_e();
            // 18. Копіювати p4 = p;
            p4 = mon4.get_p();
            // 19. Обчислення 3: Xн = p4*k4*Rн + e4*Bн
            int[] Xн = data.calculation(p4*k4, data.R, e4, data.B);
            // 20. Сигнал задачі T1 про обчислення Xн
            mon4.signal_Out();
        } catch(Exception e) {
            throw new RuntimeException(e);
        }
        System.out.println("T4 is finished");
    }
}
