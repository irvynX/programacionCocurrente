/*
S1 -> llenarbote = sacarTapetes;
S2 -> aspirarAuto = mojarTapetes;
S3 -> mojarTapetes = tallar + enjuagar tapetes;
S4 -> tallar + enjuagar tapetes = sacarTapetes;
S5 -> secarTapates = lavarAuto;
S6 -> secarAuto = acomodarTapetes;
S7 -> pulir= cerrarAuto;

L(S1) = sacarTapetes						E(S1) = llenarBote
L(S2) = mojarTapetes						E(S2) = aspirarAuto
L(S3) = tallar, enjuagar tapetes		    E(S3) = mojarTapetes
L(S4) = sacarTapetes			            E(S4) = tallar, enjuagar tapetes
L(S5) = lavarAuto							E(S5) = secarTapetes
L(S6) = acomodarTapetes					    E(S6) = secarAuto
L(S7) = cerrarAuto 						    E(S7) = pulir

L(S1) ∩ E(S2)= ∅	L(S1) ∩ E(S3)= ∅    L(S1) ∩ E(S4)= 0   L(S1) ∩ E(S5)= ∅    L(S1) ∩ E(S6)= ∅    L(S1) ∩ E(S7)= ∅
E(S1) ∩ L(S2)= ∅	E(S1) ∩ L(S3)= ∅    E(S1) ∩ L(S4)= ∅   E(S1) ∩ L(S5)= ∅    E(S1) ∩ L(S6)= ∅    E(S1) ∩ L(S7)= ∅
E(S1) ∩ E(S2)= ∅	E(S1) ∩ E(S3)= ∅    E(S1) ∩ E(S4)= ∅   E(S1) ∩ E(S5)= ∅    E(S1) ∩ E(S6)= ∅    E(S1) ∩ E(S7)= ∅

L(S2) ∩ E(S3)= mT	L(S2) ∩ E(S4)= ∅    L(S2) ∩ E(S5)= 0   L(S2) ∩ E(S6)= ∅    L(S2) ∩ E(S7)= ∅
E(S2) ∩ L(S3)= ∅	E(S2) ∩ L(S4)= ∅    E(S2) ∩ L(S5)= ∅   E(S2) ∩ L(S6)= ∅    E(S2) ∩ L(S7)= ∅
E(S2) ∩ E(S3)= ∅	E(S2) ∩ E(S4)= ∅    E(S2) ∩ E(S5)= ∅   E(S2) ∩ E(S6)= ∅    E(S2) ∩ E(S7)= ∅

L(S3) ∩ E(S4)= ∅	L(S3) ∩ E(S5)= ∅    L(S3) ∩ E(S6)= 0   L(S2) ∩ E(S7)= ∅
E(S3) ∩ L(S4)= ∅	E(S3) ∩ L(S5)= ∅    E(S3) ∩ L(S6)= ∅   E(S2) ∩ L(S7)= ∅
E(S3) ∩ E(S4)= ∅	E(S3) ∩ E(S5)= ∅    E(S3) ∩ E(S6)= ∅   E(S2) ∩ E(S7)= ∅

L(S4) ∩ E(S5)= ∅	L(S4) ∩ E(S6)= ∅    L(S4) ∩ E(S7)= 0
E(S4) ∩ L(S5)= ∅	E(S4) ∩ L(S6)= ∅    E(S4) ∩ L(S7)= ∅
E(S4) ∩ E(S5)= ∅	E(S4) ∩ E(S6)= ∅    E(S4) ∩ E(S7)= ∅

L(S5) ∩ E(S6)= ∅	L(S5) ∩ E(S7)= ∅
E(S5) ∩ L(S6)= ∅	E(S5) ∩ L(S7)= ∅
E(S5) ∩ E(S6)= ∅	E(S5) ∩ E(S7)= ∅

L(S6) ∩ E(S7)= ∅
E(S6) ∩ L(S7)= ∅
E(S6) ∩ E(S7)= ∅

aspirarAuto necesita mojar tapetes
mojar tapetes necesita terminar de aspirar
*/
package lavaraAutos;

public class main {
    public static void main(String[] args) {
        sacarTapetes sacarTapetes = new sacarTapetes();
        llenarBote llenarBote = new llenarBote();
        mojarTapetes mojarTapetes = new mojarTapetes();
        aspirarAuto aspirarAuto = new aspirarAuto();
        terminarAspirar terminarAspirar = new terminarAspirar();
        tallarEnjuagar tallarEnjuagar = new tallarEnjuagar();
        lavarAuto lavarAuto = new lavarAuto();
        secarTapetes secarTapetes = new secarTapetes();
        acomodarTapetes acomodarTapetes = new acomodarTapetes();
        secarAuto secarAuto = new secarAuto();
        cerrarAuto cerrarAuto = new cerrarAuto();
        pulir pulir = new pulir();

        sacarTapetes.run();
        llenarBote.run();
        mojarTapetes.run();
        aspirarAuto.run();
        terminarAspirar.run();
        
    }
}
