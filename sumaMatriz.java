import java.util.Scanner;

public class sumaMatriz {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        System.out.print("ingresa el tamaño de la fila: ");
        int fila = entrada.nextInt();
        System.out.print("ingresa el tamaño de la columna: ");
        int columna = entrada.nextInt();
        int [][] matriz = new int[columna][fila];

        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.print("ingresa el dato [" + i + "] [" + j + "] :");
                matriz[i][j] = entrada.nextInt();
            }
        }
        System.out.println("La matriz es: ");
        imprimirMatriz(matriz);
        System.out.println("Suma de filas:");
        sumaFilas(matriz);
        System.out.println("Suma de columnas:");
        sumaColumnas(matriz);

        entrada.close();
    }

    static void imprimirMatriz(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.printf("%d ", matriz[i][j]);
            }
            System.out.println();
        }
    }

    static void sumaFilas(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            int suma = 0;
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.printf("%d ", matriz[i][j]);
                suma += matriz[i][j];
            }
            System.out.printf("= %d\n", suma);
        }
    }

    static void sumaColumnas(int[][] matriz) {
        // Imprimir la matriz normalmente
        imprimirMatriz(matriz);
        // Debajo de ella imprimir una línea divisora
        for (int i = 0; i < matriz[0].length; i++) {
            System.out.print(" -");
        }
        System.out.println();
        // Luego recorrer por columna y sumar
        for (int i = 0; i < matriz[0].length; i++) {
            int suma = 0;
            for (int j = 0; j < matriz.length; j++) {
                suma += matriz[j][i];
            }
            System.out.printf("%d ", suma);
        }
        System.out.println();
    }
}
