package coBeginLavadora;

public class iniciar {
    public static void main(String[] args) {
        s1 s1 = new s1();
        s2 s2 = new s2();
        s3 s3 = new s3(s2,s1);
        s4 s4 = new s4(s3);
        s5 s5 = new s5(s4);

        s1.start();
        s2.start();
        s3.start();
        s4.start();
        s5.start();
    }
}

//Begin
//    Cobegin
//        S1: lavadora_llena = lavadora + agua
//        S2: ropa_separada = ropa + persona
//    Coend
//    Begin
//        S3: ropa_lavada = lavadora_llena + ropa_separada
//        S4: ropa_enjuagada = ropa_lavada + persona
//        S5: colgar_ropa = ropa_enjuagada + persona
//    End
//End

