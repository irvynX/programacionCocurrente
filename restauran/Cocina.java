package restauran;

public class Cocina {
    // atributos
    private int numeroPlatillos = 5;
    private int[] precio = {100,50,89,25,10};

    public Cocina() {
    }

    // metodos
    public int getNumero() {
        return numeroPlatillos;
    }

    public int precio(int num){
        if(num <= 4 && num >= 0){
            return precio[num];
        }else{
            return 0;
        }
    }
}
