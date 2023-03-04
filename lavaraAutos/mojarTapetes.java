package lavaraAutos;

public class mojarTapetes extends Thread {
    public void run(){
        try {
            System.out.println("Mojando tapetes");
            Thread.sleep(1000);
            System.out.println("Tapetes mojados <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
