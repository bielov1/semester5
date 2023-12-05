public class T3 extends Thread {
    int k3 = 0;
    int e3 = 0;
    int p3 = 0;
    Data data;
    MyMonitor mon3;

    public T3(MyMonitor mon3, Data data) {
        this.mon3 = mon3;
        this.data = data;
    }
    @Override
    public void run() {
        System.out.println("T3 is started");
        try {
            // 1. Уведення R i MD
            for(int i = 0; i < data.N; ++i) {
                data.R[i] = 1;
                for(int j = 0; j < data.N; ++j) {
                    data.MD[i][j] = 1;
                }
            }
            // 2. Сигнал задачі T1 про введення R i MD
            // 3. Сигнал задачі T2 про введення R i MD
            // 4. Сигнал задачі T4 про введення R i MD
            mon3.signal_In();
            // 5. Чекати на введення MA i C в задачі T2
            mon3.wait_In();
            // 6. Обчислення 1: k3 = max(Cн * (MAн * MDн))
            data.MX = data.matricesMultiplication(data.MA, data.MD);
            data.Q = data.vecAndMatrixMultiplication(data.C, data.MX);
            k3 = data.findMax(data.Q);
            // 7. Обчилсення 2: k = max(k, k3)
            mon3.compute_k(k3);
            // 8. Сигнал задачі T1 про обчислення k
            // 9. Сигнал задачі T2 про обчислення k
            // 10. Сигнал задачі T4 про обчислення k
            mon3.signal_Calc();
            Thread.sleep(100);
            // 11. Чекати на завершення обчислень k в Т1
            // 12. Чекати на завершення обчислень k в Т2
            // 13. Чекати на завершення обчислень k в Т4
            mon3.wait_Calc();
            // 14. Чекати на введення e в задачі T1
            // 15. Чекати на введення B i p в задачі Т4
            mon3.wait_In();
            // 16. Копіювати k3 = k;
            k3 = mon3.get_k();
            // 17. Копіювати e3 = e;
            e3 = mon3.get_e();
            // 18. Копіювати p3 = p;
            p3 = mon3.get_p();
            // 19. Обчислення 3: Xн = p3*k3*Rн + e3*Bн
            int[] Xн = data.calculation(p3*k3, data.R, e3, data.B);
            // 20. Сигнал задачі T1 про обчислення Xн
            mon3.signal_Out();
        } catch(Exception e) {}
        System.out.println("T3 is finished");
    }
}
