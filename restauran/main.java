package restauran;

public class main {
    public static void main(String[] args) {
        Mesero mesero[]=new Mesero[2];
        Mesero barman[]=new Mesero[2];
        Cliente cliente[]=new Cliente[2];
 
        //Creamos objetos en cada posicion
        mesero[0]= new Mesero(1,1,"jose Martinez");
        mesero[1]= new Mesero(2,1,"juan Perez");
        barman[0]= new Mesero(3,0,"Pedro Zitle");
        barman[1]= new Mesero(4,0,"Marco Garcia");

        cliente[0]= new Cliente();
        cliente[1]= new Cliente();

        System.out.println(mesero[0].menu());
        System.out.println(mesero[0].getId());
        System.out.println(mesero[0].getNombre());
        System.out.println(mesero[0].getTipo());
    }
}
