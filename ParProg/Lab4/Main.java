public class Main {
    public static void main(String[] args) {
        MyMonitor mon = new MyMonitor();
        Data data = new Data();
        Thread[] threads = new Thread[] {
            new T1(mon, data),
            new T2(mon, data),
            new T3(mon, data),
            new T4(mon, data)
        };

        for(Thread trd : threads) {
            trd.start();
        }

        try {
            for(Thread trd : threads) {
                trd.join();
            }
        } catch (Exception e) {}
    }
}
