package desayuno2;

public class main {
    public static void main(String[] args) {
        Thread desayuno[] = new desayuno[7];

        for (int i = 0; i < desayuno.length; i++){
            desayuno[i] = new desayuno(i);
            desayuno[i].start();
        }
    }
}