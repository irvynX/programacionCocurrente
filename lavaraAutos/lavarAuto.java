package lavaraAutos;

public class lavarAuto extends Thread {
    public void run(){
        try {
            System.out.println("lavando auto");
            Thread.sleep(1000);
            System.out.println("auto lavado <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
