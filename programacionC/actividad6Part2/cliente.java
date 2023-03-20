package actividad6Part2;
import java.util.Random;

import javax.management.openmbean.CompositeDataSupport;

public class cliente extends Thread{
    Random random = new Random();
    private int idCliente;
    private cuentas c;
    private int miMesero = 100;
    private menu m;
    organizacionRestauran or;
    public cliente(int idCliente,cuentas c,organizacionRestauran or,menu m){
        this.idCliente = idCliente;
        this.c = c;
        this.or = or;
        this.m = m;
    }

    @Override
    public void run() {
        System.out.println("cliente " + idCliente + ": entro al restauran");
        while (true) {
            if (miMesero == 100) {
                or.llamarMesero(idCliente);
                miMesero = or.miMesero(idCliente);
            }else{
                int comida = random.nextInt(4);
                or.ordenarC(miMesero,true,comida);
                System.out.println("cliente " + idCliente + ": me gustaria ordenar " + m.precioCo[comida]);
                comida = random.nextInt(4);
                or.ordenarC(miMesero,false,comida);
                System.out.println("cliente " + idCliente + ": y para beber me puede traer " + m.precioBe[comida]);
                // dormir para simular la espera
                try {
                    sleep(random.nextInt(5000));
                } catch (Exception e) {
                    // TODO: handle exception
                }
                System.out.println("\t\t\t\t\t\tmesero " + miMesero + ": aqui esta su comida");
                try {
                    sleep(2000 + random.nextInt(5000));
                } catch (Exception e) {
                    // TODO: handle exception
                }
                System.out.println("cliente " + idCliente + ": la cuenta porfavor");
                c.revisar(miMesero, idCliente);
                System.out.println("cliente " + idCliente + ": pago su cuenta");
                c.cambiar(miMesero,idCliente,0,true);
                System.out.println("cliente " + idCliente + ": salio del restauran");
                or.salir();
                break;
            }
        }

    }
}
