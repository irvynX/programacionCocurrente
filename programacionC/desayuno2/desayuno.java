package desayuno2;

public class desayuno extends Thread {
    private static int agua = 0, cafe = 0, prepararTorta = 0, prepararMochila = 0, calentarDesayuno = 0, comer = 0, listoParaSalir = 0;

    int accion = 0;

    public desayuno(int a) {
        accion = a;
    }

    public void run() {
        switch (accion) {
            case 0:
                try {
                    System.out.println("Calentando agua...");
                    Thread.sleep(5000);
                    System.out.println("Agua lista!");
                    agua = 1;
                    cafe = agua;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                break;

            case 1:
                while (cafe == 0) {
                    try {
                        Thread.sleep(500);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                try {
                    System.out.println("Preparando el cafe...");
                    Thread.sleep(5000);
                    System.out.println("Cafe listo!");
                    cafe = 1;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                break;

            case 2:
                try {
                    System.out.println("Preparando torta...");
                    Thread.sleep(10000);
                    System.out.println("torta lista!");
                    prepararTorta = 1;
                    prepararMochila = prepararTorta;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                break;

            case 3:
                while (prepararMochila == 0) {
                    try {
                        Thread.sleep(500);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                try {
                    System.out.println("Guardando cosas en la mochila...");
                    Thread.sleep(5000);
                    System.out.println("Mochila lista!");
                    prepararMochila++;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                break;

            case 4:
                try {
                    System.out.println("Calentando el desayuno...");
                    Thread.sleep(2000);
                    System.out.println("La comida esta lista!");
                    calentarDesayuno = 1;
                    comer = calentarDesayuno;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                break;

            case 5:
                while (comer == 0) {
                    try {
                        Thread.sleep(500);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                try {
                    System.out.println("Comiendo...");
                    Thread.sleep(10000);
                    System.out.println("Acabe de comer!");
                    comer++;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                break;

            case 6:
                do {
                    try {
                        listoParaSalir = agua + cafe + prepararTorta + prepararMochila + calentarDesayuno + comer;
                        Thread.sleep(500);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                } while (listoParaSalir < 8);
                System.out.println("Todo listo para salir");
                break;
            default:
                break;
        }
    }

}
