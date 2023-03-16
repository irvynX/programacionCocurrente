public class s1 extends Thread{
    public void run() {
        //S1: agua_caliente = agua + calor(estufa)
        System.out.println("s1 -->tengo agua");
        System.out.println("s1 -->estufa encendida");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s1 -->agua caliente");
    }
}
