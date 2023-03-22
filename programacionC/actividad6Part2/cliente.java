import java.util.Random;

public class cliente extends Thread{
    Random random = new Random();
    private int idCliente;
    private cuentas c;
    private int miMesero = 100;
    organizacionRestauran or;
    public cliente(int idCliente,cuentas c,organizacionRestauran or){
        this.idCliente = idCliente;
        this.c = c;
        this.or = or;
    }

    @Override
    public void run() {
        while (true) {
            if (miMesero == 100) {
                System.out.println("cliente " + idCliente + " entro al restauran");
                or.llamarMesero(idCliente);
                miMesero = or.miMesero(idCliente);
            }else{
                int comerPagar = random.nextInt(2);
                if (comerPagar == 0) {
                    int comida = random.nextInt(2);
                    if (comida == 0) {
                        comida = random.nextInt(4);
                        or.ordenarC(miMesero,true,comida);
                        // dormir para simular la espera
                        try {
                            sleep(random.nextInt(5000));
                        } catch (Exception e) {
                            // TODO: handle exception
                        }
                    }else{
                        comida = random.nextInt(4);
                        or.ordenarC(miMesero,false,comida);
                        // dormir para simular la espera
                        try {
                            sleep(random.nextInt(5000));
                        } catch (Exception e) {
                            // TODO: handle exception
                        }
                    }
                }else{
                    c.cambiar(miMesero,idCliente,0,true);
                    System.out.println("cliente " + idCliente + " pago su cuenta");
                    System.out.println("cliente " + idCliente + " salio del restauran");
                }
            }

        }
    }
}
