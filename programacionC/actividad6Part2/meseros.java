package actividad6Part2;

public class meseros extends Thread{
    private int idMesero;
    private cuentas c;
    private menu m;
    private int miCliente = 100;
    organizacionRestauran or;
    public meseros(int idMesero,cuentas c,menu m, organizacionRestauran or){
        this.idMesero = idMesero;
        this.c = c;
        this.m = m;
        this.or = or;
    }
    
    @Override
    public void run() {
        System.out.println("\t\t\t\t\t\tMesero " + idMesero + ": listo para trabajar");
        while (true) {
            if (or.numClientes() == 0) {
                break;
            }
            if (miCliente == 100) {
                or.meseroObservando(idMesero);
                miCliente = or.miCliente(idMesero);
            }else{
                if(or.pedido(idMesero)){
                    if (or.comida == true) {
                        c.cambiar(idMesero, miCliente, m.precioC[or.numPedido], false);
                        or.ordenCompleta(idMesero, miCliente);
                    }else{
                        c.cambiar(idMesero, miCliente, m.precioB[or.numPedido], false);
                        or.ordenCompleta(idMesero, miCliente);
                    }
                }
            }
        }
    }


    public void mostrarMenuC(){
        System.out.println(m.menuComida());
    }
    public void mostrarMenuB(){
        System.out.println(m.menuBebidas());
    }
}
