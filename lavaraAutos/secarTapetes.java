package lavaraAutos;

public class secarTapetes extends Thread{
    public void run(){
        try {
            System.out.println("secando Tapetes");
            Thread.sleep(1000);
            System.out.println("tapetes secados <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
