package lavaraAutos;

public class llenarBote extends Thread {
    public void run(){
        try {
            System.out.println("Llenando botes");
            Thread.sleep(1000);
            System.out.println("Botes llenados <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
