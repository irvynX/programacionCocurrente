package coBeginLavadora;

public class s3 extends Thread{
    private Thread hilo1;
    private Thread hilo2;
    
    public s3(Thread hilo1, Thread hilo2) {
        this.hilo1 = hilo1;
        this.hilo2 = hilo2;
    }

    public void run() {
        try {
            hilo1.join(); // Espera a que el hilo 1 termine
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
            hilo2.join(); // Espera a que el hilo 1 termine
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        //S3: ropa_lavada = lavadora_llena + ropa_separada
        System.out.println("s3 -->lavando ropa");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s3 -->ropa lavada");
    }
}