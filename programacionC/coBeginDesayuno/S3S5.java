import java.util.concurrent.CountDownLatch;

public class S3S5 extends Thread {
    public void run(){
        final CountDownLatch latch = new CountDownLatch(1);

        Thread S3 = new Thread(new Runnable() {
            public void run() {
                // S3: torta = pan + lechuga + jamon + queso
                System.out.println("S3 --- > preparando torta");
                System.out.println("S3 --- pan");
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S3 --- lechuga");
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S3 --- jamon");
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("S3 --- queso");
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S3 --- torta lista");

                latch.countDown();
            }
        });

        Thread S4 = new Thread(new Runnable() {
            public void run() {
            try {
                latch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
                // S5: mochila_lista = torta + fruta
                System.out.println("S5 --- > preparando mochila");
                System.out.println("S5 --- torta");
                try {
                    Thread.sleep(50);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S5 --- fruta");
                
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("S5 --- mochila lista");
            }
        });

        S3.start();
        S4.start();
    }
}
