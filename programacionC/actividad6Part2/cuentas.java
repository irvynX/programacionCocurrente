package actividad6Part2;

public class cuentas{
    private float[] cuentas = {0,0,0,0,0,0,0,0,0,0};
    private boolean revisandoCuentas = false;
    private boolean modificandoCuentas = false;
    menu menu = new menu();

    public synchronized void revisar(int idM, int idC){
        System.out.println("\t\t\t\t\t\tel mesero " + idM + " esta intentando leer una cuentas");
        while (modificandoCuentas == true || revisandoCuentas == true) {
            try {
                System.out.println("\t\t\t\t\t\tel mesero " + idM + " esta esperando");
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        revisandoCuentas = true;
        System.out.println("\t\t\t\t\t\tel mesero " + idM + " esta revisando una cuenta");
        System.out.println("\t\t\t\t\t\tsu cuenta es de " + mostrarCuenta(idC) + " cliente " + idC);
        System.out.println("\t\t\t\t\t\tel mesero " + idM + " termino de revisar las cuentas");
        revisandoCuentas = false;
        notifyAll();
    }

    public synchronized void cambiar(int idM,int idC,float cantidad,boolean pagar){
        System.out.println("\t\t\t\t\t\tel mesero " + idM + " esta intentando cambiar una cuenta");
        while (modificandoCuentas == true || revisandoCuentas == true) {
            try {
                System.out.println("\t\t\t\t\t\tel mesero " + idM + " esta esperando");
                wait();
            } catch (Exception e) {
                System.out.println(e);
            }
        }
        modificandoCuentas = true;
        System.out.println("\t\t\t\t\t\tel mesero " + idM + " esta modificando una cuenta");
        modificarCuenta(idC,cantidad,pagar);
        System.out.println("\t\t\t\t\t\tel mesero " + idM + " termino de modificar la cuentas");
        modificandoCuentas = false;
        notifyAll();
    }

    public synchronized String mostrarCuenta(int idCliente){
        String salida = "$";
        salida = salida + cuentas[idCliente];
        return salida;
    }

    public synchronized void modificarCuenta(int idc,float cuentaC, boolean pagar){
        if (pagar == true) {
            cuentas[idc] = 0;
        }else{
            cuentas[idc] = cuentas[idc] + cuentaC;  
        }
    }
    
    public void borrar(){
        for (int i = 0; i < cuentas.length; i++) {
            cuentas[i] = 0;
        }   
    }
}
