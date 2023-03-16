import java.util.concurrent.CountDownLatch;

public class S1S2 extends Thread{
    public void run(){
        final CountDownLatch latch = new CountDownLatch(1);

        Thread S1 = new Thread(new Runnable() {
            public void run() {
                // S1: agua_caliente = agua + calor(estufa)
                System.out.println("S1 --- > encendiendo la estufa");
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S1 --- calentando agua");
                try {
                    Thread.sleep(1500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S1 --- agua caliente");  

                latch.countDown();
            }
        });
        Thread S2 = new Thread(new Runnable() {
            public void run() {
            try {
                latch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
                // S3: torta = pan + lechuga + jamon + queso
                System.out.println("S2 --- > agregando cafe al agua caliente");
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S2 --- cafe listo");
            }
        });

        S1.start();
        S2.start();
    }
}
