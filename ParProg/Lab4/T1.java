public class T1 extends Thread {
    int k1 = 0;
    int e1 = 0;
    int p1 = 0;
    Data data;
    MyMonitor mon1;
    public T1(MyMonitor mon1, Data data) {
        this.mon1 = mon1;
        this.data = data;
    }

    @Override
    public void run() {
        System.out.println("T1 is started");
        try {
            // 1. Уведення X і e
            data.e = 1;
            mon1.set_e(data.e);
            // 2. Сигнал задачі Т2 про введення X i e
            // 3. Сигнал задачі Т3 про введення X i e
            // 4. Сигнал задачі Т4 про введення X i e
            mon1.signal_In();
            // 5. Чекати на введення MA і C в задачі T2
            // 6. Чекати на введення MD і R в задачі Т3
            mon1.wait_In();
            // 7. Обчислення 1: k1 = max(Cн*(МАн * МDн))
            data.MM = data.matricesMultiplication(data.MA, data.MD);
            data.G = data.vecAndMatrixMultiplication(data.C, data.MM);
            k1 = data.findMax(data.G);
            // 8. Обчислення 2: k = max(k, k1);
            mon1.compute_k(k1);
            // 9. Сигнал задачі T2 про обчислення k
            // 10. Сигнал задачі T3 про обчислення k
            // 11. Сигнал задачі T4 про обчислення k
            mon1.signal_Calc();
            Thread.sleep(100);
            // 12. Чекати на завершення обчислень k в Т2
            // 13. Чекати на завершення обчислень k в Т3
            // 14. Чекати на завершення обчислень k в Т4
            mon1.wait_Calc();
            // 15. Чекати на введення B i p в задачі Т4
            mon1.wait_In();
            // 16. Копіювати k1 = k
            k1 = mon1.get_k();
            // 17. Копіювати e1 = e
            e1 = mon1.get_e();
            // 18. Копіювати p1 = p
            p1 = mon1.get_p();
            // 19. Обчислення 3: Xн = p1*k1*Rн + e1*Bн
            int[] Xн = data.calculation(p1*k1, data.R, e1, data.B);
            data.X = Xн;
            // 20. Чекати на завершення обчислень Xн в Т2
            // 21. Чекати на завершення обчислень Xн в Т3
            // 22. Чекати на завершення обчислень Xн в T4
            Thread.sleep(100);
            mon1.wait_Out();
            // 23. Вивід результату X
            data.printX();
        } catch(Exception e) {}
        System.out.println("T1 is finished");
    }
}
