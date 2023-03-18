package actividad6Part2;

public class meseros extends Thread{
    private int idMesero;
    private cuentas c;
    private menu m;
    public meseros(int idMesero,cuentas c,menu m){
        this.idMesero = idMesero;
        this.c = c;
        this.m = m;
    }
    
    @Override
    public void run() {
        c.cambiar(idMesero,0,m.precioC[0],false);
        c.revisar(idMesero, 0);
    }


    public void mostrarMenuC(){
        System.out.println(m.menuComida());
    }
    public void mostrarMenuB(){
        System.out.println(m.menuBebidas());
    }
}
