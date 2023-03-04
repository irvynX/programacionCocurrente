package lavaraAutos;

public class tallarEnjuagar extends Thread {
    public void run(){
        try {
            System.out.println("Tallando tapetes");
            Thread.sleep(1000);
            System.out.println("Ejuagando tapetes");
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
