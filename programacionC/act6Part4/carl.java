import java.io.*;
import java.net.*;

class carl extends Thread {

    static final String HOST = "localhost";
    private Socket skCliente;
    static final int Puerto = 9000;
    int cont = 0;
    boolean enamorada = true;
    String[] mensajes = { "uno rojo", "rojo", "es rojo, no", "no hago trampa", "rojo",
            "tal vez necesito lentes nuevos" };
    String nombre = "Carl";
    int i = 0;

    public carl() {
    }

    public void run() {

        while (i<6)
            try {
                skCliente = new Socket(HOST, Puerto);
                skCliente.setSendBufferSize(10000);
                OutputStream aux = skCliente.getOutputStream();

                DataOutputStream flujo = new DataOutputStream(aux);
                flujo.writeUTF(nombre + ": " + mensajes[i]);
                i++;
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
        new carl().start();
    }
}