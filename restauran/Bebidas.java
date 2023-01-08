package restauran;

public class Bebidas {
    //atributos
    private int numeroBebidas = 5;
    private int[] precio = {10,20,12,5,8} ;

    public Bebidas() {
    }

    //metodos
    public int getNumero() {
        return numeroBebidas;
    }

    public int precio(int num){
        if(num <= 4 && num >= 0){
            return precio[num];
        }else{
            return 0;
        }
    }
}
