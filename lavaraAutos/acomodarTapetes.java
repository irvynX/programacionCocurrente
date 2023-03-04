package lavaraAutos;

public class acomodarTapetes extends Thread{
    public void run(){
        try {
            System.out.println("Acomodando tapetes");
            Thread.sleep(1000);
            System.out.println("Tapetes acomodados <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
