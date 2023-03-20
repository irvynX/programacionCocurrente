package actividad6Part2;

public class organizacionRestauran {
    //0=inicio, 1=llamar mesero, 2=ordenar, 3=pagar
    private int cliente [] = {100,100,100,100,100,100,100};
    //representa que mesero atiende a cada cliente
    private int llamarMesero [] = {100,100,100,100,100,100,100};
    //plato a oredenar
    private int ordenar [] = {100,100,100,100,100,100,100};
    // mientras este en true el progra funciona
    private boolean restauranAbierto = true;
    // crea las esperas
    private boolean llamar = false;
    //pedido pendientes
    public boolean comida = false;
    public int numPedido = 100;
    public int ordenAlMesero = 100;
    public boolean pedido = false;

    public synchronized void llamarMesero(int idC){
        while (llamar == true) {
            try {
                System.out.println("el cliente " + idC + " esta esperando para llamar a un mesero");
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        llamar = true;
        System.out.println("cliente " + idC + ": llama a un mesero");
        cliente[idC] = 1;
        try {
            System.out.println("el cliente " + idC + " esta esperando a un mesero");
            wait();
        } catch (Exception e) {
            System.out.println(e);
        }
        llamar = false;
        notifyAll();
    }

    public synchronized void meseroObservando(int idM){
        while (llamar == false) {
            try {
                System.out.println("el mesero " + idM + " esta esperando para ver");
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        int temp = 100;
        for (int i = 0; i < cliente.length; i++) {
            if (cliente[i] == 1) {
                temp = i;
            }
        }
        if (temp == 100) {
            System.out.println("ningun cliente llama");
        }else{
            System.out.println("cliente " + temp + ": llama a un mesero");
            cliente[temp] = 2;
            llamarMesero[temp] = idM;
            System.out.println("mesero " + idM + ": sera un gusto atenderlo");
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
        int temp = 0;
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
    }

    public synchronized boolean pedido(int idM){
        while (llamar == true) {
            try {
                wait();
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
        notifyAll();
        return temp;
    }
}
