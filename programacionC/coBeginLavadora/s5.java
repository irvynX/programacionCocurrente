package coBeginLavadora;

public class s5 extends Thread{
    private Thread hilo1;
    
    public s5(Thread hilo1) {
        this.hilo1 = hilo1;
    }

    public void run() {
        try {
            hilo1.join(); // Espera a que el hilo 1 termine
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //S5: colgar_ropa = ropa_enjuagada + persona
        System.out.println("s5 -->colgando ropa");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s5 -->ropa colgada");
    }
}