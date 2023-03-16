package pruebas;

public class hilo1 extends Thread {
    public void run() {
        // Código para el hilo 1
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Hilo 1");
    }
}
