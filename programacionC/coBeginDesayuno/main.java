import java.util.concurrent.CountDownLatch;

public class main {
  public static void main(String[] args) {
    final CountDownLatch latch = new CountDownLatch(2);

    Thread hilo1 = new Thread(new Runnable() {
      public void run() {
        // S1: agua_caliente = agua + calor(estufa)
        // Simulamos la operación con una espera de 2 segundos
        try {
          Thread.sleep(2000);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
        int agua = 200; // Supongamos que hay 200 ml de agua
        int estufa = 100; // Supongamos que la estufa produce 100 grados de calor
        int agua_caliente = agua + estufa;
        System.out.println("S1: agua_caliente = " + agua_caliente);
        
        // S2: cafe = agua_caliente + nescafe
        int nescafe = 50; // Supongamos que usamos 50 gramos de Nescafé
        int cafe = agua_caliente + nescafe;
        System.out.println("S2: cafe = " + cafe);
        latch.countDown();
      }
    });

    Thread hilo2 = new Thread(new Runnable() {
      public void run() {
        // S3: torta = pan + lechuga + jamon + queso
        String pan = "pan";
        String lechuga = "lechuga";
        String jamon = "jamon";
        String queso = "queso";
        String torta = pan + " " + lechuga + " " + jamon + " " + queso;
        System.out.println("S3: torta = " + torta);
        
        // S5: mochila_lista = torta + fruta
        String fruta = "manzana";
        String mochila_lista = torta + " " + fruta;
        System.out.println("S5: mochila_lista = " + mochila_lista);
        latch.countDown();
      }
    });

    hilo1.start();
    hilo2.start();

    try {
      latch.await();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    // S4: desayuno_caliente = comida_de_mamá + microondas
    String comida_de_mama = "huevos con tocino";
    String desayuno_caliente = comida_de_mama + " calentado en el microondas";
    System.out.println("S4: desayuno_caliente = " + desayuno_caliente);
  }
}
