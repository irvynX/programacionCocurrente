package restauran;
import java.util.Scanner;

public class Cliente {
    // atributos
    private int cuenta = 0;
    public int tiempoEspera = 0;
    private int numMeseros = 0;
    private int[] meseros = {0,0,0};
    Scanner entrada = new Scanner(System.in);

    public Cliente() {
    }

    // metodos

    public void meseroAtendiendote(String tipo,String nombre, int id){
        if(numMeseros <= 2){
            System.out.println("soy el " + tipo + " " + nombre + "y sera un placer atenderlo");
            meseros[numMeseros] = id;
            numMeseros++;
        } else{
            System.out.println("veo que mis compañeros ya lo estan atendiendo");
        }
    }

    public void cuenta(int num){
        cuenta = cuenta + num;
    }

    public void pagar(){
        int pagar = 0;
        System.out.println("su cuenta es de $" + cuenta);
        while(pagar < cuenta){
            System.out.print("introduce la cantidad a pagar(los meseros agradecen las propinas): $");
            pagar = entrada.nextInt();
        }
        if (pagar > cuenta){
            System.out.print("esperamos que tenga un buen dia y vuelva pronto :)");
        }else{
            System.out.println("..........(el mesero no dice nada)");
        }
    }
}
