package pruebas;

public class hilo2 extends Thread {
    private Thread hilo1; // Referencia al hilo 1
    
    public hilo2(Thread hilo1) {
        this.hilo1 = hilo1;
    }
    
    public void run() {
        // Código para el hilo 2
        try {
            hilo1.join(); // Espera a que el hilo 1 termine
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("hilo 2");
        // Código para el hilo 2 que se ejecuta después de que el hilo 1 haya terminado
    }
}

