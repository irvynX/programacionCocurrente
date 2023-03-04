package lavaraAutos;

public class secarAuto extends Thread{
    public void run(){
        try {
            System.out.println("secando Auto");
            Thread.sleep(1000);
            System.out.println("Auto secado <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
