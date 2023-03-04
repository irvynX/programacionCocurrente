package lavaraAutos;

public class pulir extends Thread{
    public void run(){
        try {
            System.out.println("Puliendo auto");
            Thread.sleep(1000);
            System.out.println("auto pulido <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
