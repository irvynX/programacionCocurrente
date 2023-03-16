public class s3 extends Thread{

    public void run() {
        //S3: torta = pan + lechuga + jamon + queso
        System.out.println("s3 -->torta");
        System.out.println("s3 -->lechuga");
        System.out.println("s3 -->jamon");
        System.out.println("s3 -->queso");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s3 -->torta lista");
    }
}