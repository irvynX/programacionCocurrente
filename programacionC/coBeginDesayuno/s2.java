public class s2 extends Thread{
    private Thread hilo1;
    
    public s2(Thread hilo1) {
        this.hilo1 = hilo1;
    }

    public void run() {
        try {
            hilo1.join(); // Espera a que el hilo 1 termine
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //S2: cafe = agua_caliente + nescafe
        System.out.println("s2 -->nescafe");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s2 -->el cafe esta listo");
    }
}