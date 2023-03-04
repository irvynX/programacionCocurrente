package lavaraAutos;

public class aspirarAuto extends Thread{
    public void run(){
        try {
            System.out.println("Aspirando auto");
            Thread.sleep(1000);
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
