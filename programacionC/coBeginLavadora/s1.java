package coBeginLavadora;

public class s1 extends Thread{
    public void run() {
        //S1: lavadora_llena = lavadora + agua
        System.out.println("s1 -->llenando lavadora");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s1 -->lavadora llena");
    }
}
