package lavaraAutos;

public class cerrarAuto extends Thread{
    public void run(){
        try {
            System.out.println("cerrando el auto");
            Thread.sleep(1000);
            System.out.println("Auto cerrado <------------");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
