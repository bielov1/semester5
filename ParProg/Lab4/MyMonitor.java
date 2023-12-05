public class MyMonitor {
    private int k = 0;
    private int p = 0;
    private int e = 0;

    private int Fl1 = 0;
    private int Fl2 = 0;
    private int Fl3 = 0;

    public synchronized void signal_In() {
        notify();
        Fl1 += 1;
    }

    public synchronized void wait_In() {
        while (Fl1 != 4) {
            try {
                wait();
            } catch(Exception e) {}
        }
    }

    public synchronized void signal_Calc() {
        notify();
        Fl2 += 1;
    }

    public synchronized void wait_Calc() {
        while(Fl2 != 4) {
            try {
                wait();
            } catch(Exception e) {}
        }
    }

    public synchronized void signal_Out() {
        notify();
        Fl3 += 1;
    }

    public synchronized void wait_Out() {
        while(Fl3 != 3) {
            try {
                wait();
            } catch(Exception e) {}
        }
    }


    public synchronized void compute_k(int k_i) {
        this.k = Math.max(this.k, k_i);
    }

    public synchronized int get_k() {
        return this.k;
    }

    public synchronized void set_p(int p) {
        this.p = p;
    }

    public synchronized int get_p() {
        return this.p;
    }


    public synchronized void set_e(int e) {
        this.e = e;
    }


    public synchronized int get_e() {
        return this.e;
    }
}
