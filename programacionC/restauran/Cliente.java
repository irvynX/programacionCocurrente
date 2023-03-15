package restauran;
import java.util.Scanner;

public class Cliente {
    // atributos
    public int cuenta = 0;
    public int tiempoEsperaM = 0;
    public int tiempoEsperaB = 0;
    public int numMesero = 0;
    public int numPedidoM = 0;
    public int numPedidoB = 0;
    public int numBarman = 0;
    Scanner entrada = new Scanner(System.in);

    public Cliente() {
    }

    // metodos

    public void meseroAtendiendote(String nombre, int id){
        if(numMesero == 0){
            System.out.println("soy " + nombre + "y sera un placer atenderlo");
            numMesero = id;
        } else{
            System.out.println("veo que mis compañeros ya lo estan atendiendo");
        }
    }

    public void entregaM(int num,String nom){
        System.out.println(nom + "(Mesero): aqui esta lo que ordeno. si desea algo mas puede llamarme");
        numMesero = 0;
        cuenta = cuenta + num;
    }

    public void barmanAtendiendote(String nombre, int id){
        if(numBarman == 0){
            System.out.println("soy " + nombre + "y sera un placer atenderlo");
            numBarman = id;
        } else{
            System.out.println("veo que mis compañeros ya lo estan atendiendo");
        }
    }

    public void entregaBarman(int num,String nom){
        System.out.println(nom + "(Barman:) aqui esta lo que ordeno. si desea algo mas puede llamarme");
        numBarman = 0;
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
            System.out.println("esperamos que tenga un buen dia.Vuelva pronto :)");
            cuenta = 0;
        }else if (pagar == cuenta){
            System.out.println("..........(el mesero no dice nada)");
            cuenta = 0;
        }else{
            System.out.println("creo que no me alcanza con esto");
        }
    }
}
