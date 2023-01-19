package Matriz1;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class Matriz  { 

private Scanner teclado;
    private int[][] mat;
    
    public void cargar() {
        teclado=new Scanner(System.in);
        System.out.print("Cuantas fila tiene la matriz:");
        int filas=teclado.nextInt();
        System.out.print("Cuantas columnas tiene la matriz:");
        int columnas=teclado.nextInt();
        mat=new int[filas][columnas];
        for(int f=0;f<mat.length;f++) {
            for(int c=0;c<mat[f].length;c++) {
                System.out.print("Ingrese componente:");
                mat[f][c]=teclado.nextInt();
            }
        }
    }
    
    public void imprimir() {
        for(int f=0;f<mat.length;f++) {
            for(int c=0;c<mat[f].length;c++) {
                System.out.print(mat[f][c]+" ");
            }
            System.out.println();
        }
    }
        public void suma() {
            int S=0;
        for(int f=0;f<mat.length;f++) {
            for(int c=0;c<mat[f].length;c++) {
            S= S + mat[f][c];
            }
        }
        System.out.println("la suma de los componentes es:");
        System.out.println(S);
    }
}

