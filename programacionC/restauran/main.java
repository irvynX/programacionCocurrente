package restauran;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        int[] estado = {0,0};
        int op = 0;
        int tmp = 0;
        Mesero mesero[]=new Mesero[2];
        Mesero barman[]=new Mesero[2];
        Cliente cliente[]=new Cliente[1];
        Scanner entrada = new Scanner(System.in);
        //BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
 
        //Creamos objetos en cada posicion
        mesero[0]= new Mesero(0,1,"jose Martinez");
        mesero[1]= new Mesero(1,1,"juan Perez");
        barman[0]= new Mesero(0,0,"Pedro Zitle");
        barman[1]= new Mesero(1,0,"Marco Garcia");

        cliente[0]= new Cliente();

        while (op != 100) {
            System.out.println("para salir en cualquier momento elige como opcion 100");
            for(int i=0; i < cliente.length; i++) {
                if (cliente[i].tiempoEsperaM == 1) {
                    System.out.println("cliente " + (i+1) + ": ");
                    cliente[i].entregaM(mesero[0].meseroC.precio(cliente[i].numPedidoM),mesero[cliente[i].numMesero].getNombre());
                    cliente[i].tiempoEsperaM = 0;
                }else if (cliente[i].tiempoEsperaB == 1) {
                    System.out.println("cliente " + (i+1) + ": ");
                    cliente[i].entregaBarman(barman[0].meseroB.precio(cliente[i].numPedidoM),barman[cliente[i].numMesero].getNombre());
                    cliente[i].tiempoEsperaB = 0;
                }else{
                    //fuera del restauran
                    if (estado[i] == 0) {
                        System.out.println("cliente " + (i+1) + ": un restaurante muy bonito, ¿deberia entrar? \n1.- Entrar \n2.- Ver una mariposa");
                        op = entrada.nextInt();
                        if(op==1){
                            System.out.println("Cliente " + (i+1) + ": entra y se sienta en una mesa");
                            estado[i]++;
                        }else{
                            System.out.println("Cliente " + (i+1) + ": se queda quieto viendo una mariposa pasar");
                        }
                    }
                    if(estado[i] == 1){
                        System.out.println("Cliente " + (i+1) + ": ¿que deberia hacer?\n1.-llamar un mesero\n2.-Llamar a alguien de barra\n3.-Pagar\n4.-Esperar\n5.-Salir");
                        op = entrada.nextInt();
                        switch (op) {
                            case 1:
                                System.out.println("¿aquien llamare?");
                                for (int j = 0; j < mesero.length; j++) {
                                    System.out.println( (j+1) + ".- empleado " + mesero[j].getNombre());
                                }
                                op = entrada.nextInt();
                                if(op > mesero.length){
                                    op = mesero.length;
                                }else if (op < 1) {
                                    op = 1;
                                }
                                cliente[i].meseroAtendiendote(mesero[op-1].getNombre(), mesero[op-1].getId());
                                estado[i] = 2;
                                break;
                            case 2:
                                System.out.println("¿aquien llamare?");
                                for (int j = 0; j < barman.length; j++) {
                                    System.out.println( (j+1) + ".- empleado " + barman[j].getNombre());
                                }
                                op = entrada.nextInt();
                                if(op > barman.length){
                                    op = barman.length;
                                }else if (op < 1) {
                                    op = 1;
                                }
                                cliente[i].barmanAtendiendote(barman[op-1].getNombre(), barman[op-1].getId());
                                estado[i] = 3;
                                break;
                            case 3:
                                if (cliente[i].cuenta == 0) {
                                    System.out.println("Debes consumir primero antes de pagar");
                                }else{
                                    cliente[i].pagar();
                                }
                                break;
                            case 4:
                                System.out.println("cliente " + (i+1) + ": esta meditando en silencio");
                                break;
                            case 5:
                                if(cliente[i].cuenta > 0){
                                    System.out.println("cliente " + (i+1) + "mi mama me enseño a pagar");
                                }else if (cliente[i].tiempoEsperaM > 0 || cliente[i].tiempoEsperaB > 0) {
                                    System.out.println("cliente " + (i+1) + ": no me gusta esperar pero tengo mucha hambre");
                                }else{
                                    estado[i] = 0;
                                }
                                break;
                            default:
                                estado[i] = 0;
                                break;
                        }
                    }
                    if (estado[i] == 2) {
                        if (cliente[i].tiempoEsperaM > 1) {
                            System.out.println("estamos preparando tu pedido");
                            estado[i] = 1;
                        }else if (cliente[i].tiempoEsperaM == 0){
                            System.out.println("1.-Me puedes mostrar el menu\n2.-Me puedes traer...\n3.-Todo bien");
                            op = entrada.nextInt();
                            switch (op) {
                                case 1:
                                    System.out.println(mesero[0].menu());
                                    break;
                                case 2:
                                System.out.println("elige el numero del plato: ");
                                tmp = entrada.nextInt();
                                tmp--;
                                if (tmp > 4) {
                                    tmp = 4;
                                }
                                cliente[i].numPedidoM = tmp;
                                cliente[i].tiempoEsperaM = 4;
                                estado[i] = 1;
                                    break;
                                case 3:
                                estado[i] = 1;
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    if (estado[i] == 3) {
                        if (cliente[i].tiempoEsperaB > 1) {
                            System.out.println("estamos preparando tu bebida");
                            estado[i] = 1;
                        }else if (cliente[i].tiempoEsperaB == 0){
                            System.out.println("1.-Me puedes mostrar el menu\n2.-Me puedes traer...\n3.-Todo bien");
                            op = entrada.nextInt();
                            switch (op) {
                                case 1:
                                    System.out.println(barman[0].menu());
                                    break;
                                case 2:
                                System.out.println("elige el numero de la bebida: ");
                                tmp = entrada.nextInt();
                                tmp--;
                                if (tmp > 4) {
                                    tmp = 4;
                                }
                                cliente[i].numPedidoB = tmp;
                                cliente[i].tiempoEsperaB = 4;
                                estado[i] = 1;
                                    break;
                                case 3:
                                estado[i] = 1;
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }





                if (cliente[i].tiempoEsperaM > 0) {
                    cliente[i].tiempoEsperaM--;
                }
                if (cliente[i].tiempoEsperaB > 0) {
                    cliente[i].tiempoEsperaB--;
                }
                System.out.println("--------------------------------");
                System.out.println("--------------------------------");
            }
        } 
 

        entrada.close();
    }
}
