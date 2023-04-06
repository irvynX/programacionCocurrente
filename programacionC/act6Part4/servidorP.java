import java.io.*;
import java.net.*;

public class servidorP extends Thread {
    static final int PUERTO = 9000;
    String[] mensajesC = {"","","","","",""};
    String[] mensajesR;
    String[] mensajesD;
    int numC = 6;
    int numR = 6;
    int numD = 1;
    int pos = 0;
    int estado = 0;

    public servidorP() {
    }

    public void run() {
        /*
         * try {
         * ServerSocket skServidor = new ServerSocket(PUERTO);
         * System.out.println("Escucho el puerto " + PUERTO);
         * while (true) {
         * Socket skCliente = skServidor.accept();
         * InputStream aux = skCliente.getInputStream();
         * DataInputStream flujo = new DataInputStream(aux);
         * System.out.println(flujo.readUTF());
         * if (estado == 0) {
         * mensajesC[pos] = flujo.readUTF();
         * pos++;
         * if (pos == numC) {
         * System.out.println("dialogos guardados");
         * estado = 1;
         * pos = 0;
         * }
         * }
         * if (estado == 1) {
         * mensajesR[pos] = flujo.readUTF();
         * pos++;
         * if (pos == numR) {
         * System.out.println("dialogos guardados");
         * estado = 2;
         * pos = 0;
         * }
         * }
         * if (estado == 2) {
         * mensajesD[pos] = flujo.readUTF();
         * pos++;
         * if (pos == numD) {
         * System.out.println("dialogos guardados");
         * estado = 3;
         * }
         * }
         * if (estado == 3) {
         * for (int i = 0; i < mensajesC.length; i++) {
         * System.out.println(mensajesC[i]);
         * }
         * for (int i = 0; i < mensajesR.length; i++) {
         * System.out.println(mensajesR[i]);
         * }
         * for (int i = 0; i < mensajesD.length; i++) {
         * System.out.println(mensajesD[i]);
         * }
         * }
         * skCliente.close();
         * }
         * } catch (Exception e) {
         * System.out.println(e.getMessage());
         * }
         */
        try {
            ServerSocket skServidor = new ServerSocket(PUERTO);
            System.out.println("Escucho el puerto " + PUERTO);
            while (true) {
                Socket skCliente = skServidor.accept();
                InputStream aux = skCliente.getInputStream();
                DataInputStream flujo = new DataInputStream(aux);
                System.out.println(flujo.readUTF());
                skCliente.close();
            }

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] arg) {
        new servidorP().start();
    }
}
