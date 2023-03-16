public class S4 {
    public void run(){
        // S4: desayuno_caliente = comida_de_mamá + microondas
        System.out.println("S4 --- > calentando desayuno");
        System.out.println("S4 --- commida de mamá en el microondas");
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("S4 --- comida de mamá caliente");
    }
}
