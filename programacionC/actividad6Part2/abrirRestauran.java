public class abrirRestauran {
    public static void main(String[] args) {
        int num = 3;
        //hilos
        meseros meseros[] = new meseros[num];
        cliente clientes[] = new cliente[num];
        // objetos sincronos
        cuentas cuentas = new cuentas();
        menu menu = new menu();
        organizacionRestauran or = new organizacionRestauran(num);

        System.out.println(menu.menuComida());
        System.out.println(menu.menuBebidas());
        System.out.println("");
        System.out.println("");

        for (int i = 0; i < num; i++) {
            meseros[i] = new meseros(i, cuentas, menu, or);
            meseros[i].start();
            clientes[i] = new cliente(i, cuentas, or, menu);
            clientes[i].start();
        }
    }
}
