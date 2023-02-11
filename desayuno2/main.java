package desayuno2;

public class main {
    public static void main(String[] args) {
        Thread desayuno[] = new desayuno[7];

        for (int i = 0; i < desayuno.length; i++){
            desayuno[i] = new desayuno(i);
            desayuno[i].start();
        }
    }
}

/*
S1 - agua = agua + 1;
S2 - cafe = agua;

S3 - prepararTorta = prepararTorta + 1;
S4 - prepararMochila = prepararTorta;

S5 - calentarDesayuno = calentarDesayuno + 1;
S6 - comer = calentarDesayuno;

S7 - listoParaSalir = agua + cafe + prepararTorta + prepararMochila + calentarDesayuno + comer + 2;

L(S1) = agua                        E(S1) =agua
L(S2) = agua                        E(S2) = cafe
L(S3) = prepararTorta               E(S3) = prepararTorta
L(S4) = prepararTorta               E(S4) = prepararMochila
L(S5) = calentarDesayuno            E(S5) = calentarDesayuno
L(S6) = calentarDesayuno            E(S6) = comer
L(S7) = *todas*                     E(S7) = listoParaSalir

L(S1) ( E(S2)= 0    L(S1) ( E(S3)= 0    L(S1) ( E(S4)= 0    L(S1) ( E(S5)= 0    L(S1) ( E(S6)= 0    L(S1) ( E(S7)= 0
E(S1) ( L(S2)= agua E(S1) ( L(S3)= 0    E(S1) ( L(S4)= 0    E(S1) ( L(S5)= 0    E(S1) ( L(S6)= 0    E(S1) ( L(S7)= agua
E(S1) ( E(S2)= 0    E(S1) ( E(S3)= 0    E(S1) ( E(S4)= 0    E(S1) ( E(S5)= 0    E(S1) ( E(S6)= 0    E(S1) ( E(S7)= agua

L(S2) ( E(S3)= 0    L(S2) ( E(S4)= 0    L(S2) ( E(S5)= 0    L(S2) ( E(S6)= 0    L(S2) ( E(S7)= 0
E(S2) ( L(S3)= 0    E(S2) ( L(S4)= 0    E(S2) ( L(S5)= 0    E(S2) ( L(S6)= 0    E(S2) ( L(S7)= cafe
E(S2) ( E(S3)= 0    E(S2) ( E(S4)= 0    E(S2) ( E(S5)= 0    E(S2) ( E(S6)= 0    E(S2) ( E(S7)= agua

L(S3) ( E(S4)= 0                L(S3) ( E(S5)= 0    L(S3) ( E(S6)= 0    L(S3) ( E(S7)= 0
E(S3) ( L(S4)= prepararTorta    E(S3) ( L(S5)= 0    E(S3) ( L(S6)= 0    E(S3) ( L(S7)= prepararTorta
E(S3) ( E(S4)= 0                E(S3) ( E(S5)= 0    E(S3) ( E(S6)= 0    E(S3) ( E(S7)= 0

L(S4) ( E(S5)= 0    L(S4) ( E(S6)= 0    L(S4) ( E(S7)= 0
E(S4) ( L(S5)= 0    E(S4) ( L(S6)= 0    E(S4) ( L(S7)= prepararMochila
E(S4) ( E(S5)= 0    E(S4) ( E(S6)= 0    E(S4) ( E(S7)= 0

// aqui me quede

L(S5) ( E(S6)= 0    L(S5) ( E(S7)= 0
E(S5) ( L(S6)= 0    E(S5) ( L(S7)= prepararMochila
E(S5) ( E(S6)= 0    E(S5) ( E(S7)= 0

L(S6) ( E(S7)= 0
E(S6) ( L(S7)= prepararMochila
E(S6) ( E(S7)= 0

 */