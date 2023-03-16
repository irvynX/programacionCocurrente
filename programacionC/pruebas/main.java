package pruebas;

public class main {
    public static void main(String[] args) {
        hilo1 hilo1 = new hilo1();
        hilo2 hilo2 = new hilo2(hilo1);

        hilo2.start();
        hilo1.start();
    }
}
