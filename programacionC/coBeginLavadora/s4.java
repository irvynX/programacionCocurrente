package coBeginLavadora;

public class s4 extends Thread{
    private Thread hilo1;
    
    public s4(Thread hilo1) {
        this.hilo1 = hilo1;
    }

    public void run() {
        try {
            hilo1.join(); // Espera a que el hilo 1 termine
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //S4: ropa_enjuagada = ropa_lavada + persona
        System.out.println("s4 -->enjuagando ropa");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s4 -->ropa enjuagada");
    }
}