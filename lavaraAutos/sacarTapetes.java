package lavaraAutos;

public class sacarTapetes extends Thread{
    public void run(){
        try {
            System.out.println("Sacando tapetes");
            Thread.sleep(1000);
            System.out.println("Tapetes sacados <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
