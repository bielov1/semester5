public class T2 extends Thread {
    int k2 = 0;
    int e2 = 0;
    int p2 = 0;
    Data data;
    MyMonitor mon2;

    public T2(MyMonitor mon2, Data data) {
        this.mon2 = mon2;
        this.data = data;
    }
    @Override
    public void run() {
        System.out.println("T2 is started");
        try {
            // 1. Уведення С і МА
            for(int i = 0; i < data.N; ++i) {
                data.C[i] = 1;
                for(int j = 0; j < data.N; ++j) {
                    data.MA[i][j] = 1;
                }
            }
            // 2. Сигнал задачі T1 про введення C i MA
            // 3. Сигнал задачі T3 про введення C i MA
            // 4. Сигнал задачі T4 про введення C i MA
            mon2.signal_In();
            // 5. Чекати на введення MD i R в задачі Т3
            mon2.wait_In();
            // 6. Обчислення 1: k2 = max(Cн * (MAн * MDн))
            data.MK = data.matricesMultiplication(data.MA, data.MD);
            data.W = data.vecAndMatrixMultiplication(data.C, data.MK);
            k2 = data.findMax(data.W);
            // 7. Обчилсення 2: k = max(k, k2)
            mon2.compute_k(k2);
            // 8. Сигнал задачі T1 про обчислення k
            // 9. Сигнал задачі T3 про обчислення k
            // 10. Сигнал задачі T4 про обчислення k
            mon2.signal_Calc();
            Thread.sleep(100);
            // 11. Чекати на завершення обчислень k в Т1
            // 12. Чекати на завершення обчислень k в Т3
            // 13. Чекати на завершення обчислень k в Т4
            mon2.wait_Calc();
            // 14. Чекати на введення e в задачі Т1
            // 15. Чекати на введення p i B в задачі Т4
            mon2.wait_In();
            // 16. Копіювати k2 = k;
            k2 = mon2.get_k();
            // 17. Копіювати e2 = e;
            e2 = mon2.get_e();
            // 18. Копіювати p2 = p;
            p2 = mon2.get_p();
            // 19. Обчислення 3. Xн = p2*k2*Rн + e2*Bн
            int[] Xн = data.calculation(p2*k2, data.R, e2, data.B);
            // 20. Сигнал задачі Т1 про обчислення Xн
            mon2.signal_Out();
        } catch(Exception e) {}
        System.out.println("T2 is finished");
    }
}
