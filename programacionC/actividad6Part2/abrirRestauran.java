package actividad6Part2;

public class abrirRestauran {
    public static void main(String[] args) {
        menu menu = new menu();
        cuentas cuentas = new cuentas();
        meseros mPrueba[] = new meseros[7];

        for (int i = 0; i < mPrueba.length; i++) {
            mPrueba[i] = new meseros(i, cuentas, menu);
            mPrueba[i].start();
        }
    }
}
