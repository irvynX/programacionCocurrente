import java.io.*;
import java.net.*;

class dug extends Thread {

    static final String HOST = "localhost";
    private Socket skCliente;
    static final int Puerto = 9000;
    int cont = 0;
    boolean enamorada = true;

    public dug(String girlfriend) {
    }

    public void run() {
        try {
            skCliente = new Socket(HOST, Puerto);
            String nombre = "Dug";
            String[] mensajes = {"uno gris"};

            
            skCliente.setSendBufferSize(10000);
            OutputStream aux = skCliente.getOutputStream();
    
            DataOutputStream flujo = new DataOutputStream(aux);
            for (int i = 0; i < mensajes.length; i++) {
                flujo.writeUTF( nombre + ": " + mensajes[i]);
            }       
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try {
            skCliente.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
    public static void main(String[] arg) {
        if (arg.length > 0)
            new dug(arg[0]).start();
        ;
    }
}