public class organizacionRestauran {
    //0=inicio, 1=llamar mesero, 2=ordenar, 3=pagar
    private int cliente [] = {100,100,100,100,100,100,100};
    //representa que mesero atiende a cada cliente
    private int llamarMesero [] = {100,100,100,100,100,100,100};
    //numero de clientes
    private int numClientes = 100;
    // crea las esperas
    private boolean llamar = false;
    private boolean llamandoMesero = false;
    //pedido pendientes
    public boolean comida = false;
    public int numPedido = 100;
    public int ordenAlMesero = 100;
    public boolean pedido = false;

    public organizacionRestauran(int numC) {
        numClientes = numC;
    }

    public synchronized void llamarMesero(int idC){
        while (llamar == true || llamandoMesero == true) {
            try {
                //System.out.println("el cliente " + idC + " esta esperando para llamar a un mesero");
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        llamandoMesero = true;
        System.out.println("cliente " + idC + ": llama a un mesero");
        cliente[idC] = 1;
        llamar = false;
        notifyAll();
        try {
            wait();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public synchronized void meseroObservando(int idM){
        while (llamar == true) {
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        if (llamandoMesero == true) {
            llamar = true;
            int temp = 100;
            for (int i = 0; i < cliente.length; i++) {
                if (cliente[i] == 1) {
                    temp = i;
                }
            }
            if (temp == 100) {
                System.out.println("\t\t\t\t\t\tningun cliente llama");
            }else{
                cliente[temp] = 2;
                llamarMesero[temp] = idM;
                System.out.println("\t\t\t\t\t\tmesero " + idM + ": sera un gusto atenderlo cliente " + temp);
            }
            llamandoMesero = false;
            llamar = false;
        }
        notifyAll();
    }

    public synchronized int estadoCliente(int idC){
        while (llamar == true) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        int temp = cliente[idC];
        llamar = false;
        llamandoMesero = false;
        notifyAll();
        return temp;
    }

    public synchronized int miMesero(int idC){
        while (llamar == true) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        int temp = llamarMesero[idC];
        llamar = false;
        notifyAll();
        return temp;
    }

    public synchronized int miCliente(int idM){
        while (llamar == true) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        int temp = 100;
        for (int i = 0; i < llamarMesero.length; i++) {
            if (llamarMesero[i] == idM) {
                temp = i;
            }
        }
        llamar = false;
        notifyAll();
        return temp;
    }

    public synchronized void ordenarC(int idM,boolean c,int numP){
        while (llamar == true || pedido == true){
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        comida = c;
        numPedido = numP;
        pedido = true;
        ordenAlMesero = idM;
        llamar = false;
        notifyAll();
    }

    public synchronized boolean pedido(int idM){
        while (llamar == true) {
            try {
                Thread.sleep(100);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        boolean temp = false;
        if (idM == ordenAlMesero){
            temp = true;
        }
        llamar = false;
        return temp;
    }

    public synchronized void ordenCompleta(int idM,int idC){
        while (llamar == true) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        System.out.println("\t\t\t\t\t\tmesero " + idM + " apunto la orden del cliente " + idC);
        ordenAlMesero = 100;
        pedido = false;
        llamar = false;
        notifyAll();
    }

    public synchronized void salir(){
        while (llamar == true) {
            try {
                Thread.sleep(100);
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        numClientes--;
        llamar = false;
        notifyAll();
    }

    public synchronized int numClientes(){
        while (llamar == true) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        llamar = false;
        notifyAll();
        return numClientes;
    }
}
