package coBeginLavadora;

public class s2 extends Thread{
    public void run() {
        //S2: ropa_separada = ropa + persona
        System.out.println("s2 -->separando ropa");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s2 -->ropa separada");
    }
}