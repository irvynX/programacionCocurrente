public class s4 extends Thread{

    public void run() {
        //S4: desayuno_caliente = comida_de_mamá + microondas
        System.out.println("s4 -->comida de mamá");
        System.out.println("s4 -->encender microondas");
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("s4 -->desayuno caliente");
    }
}