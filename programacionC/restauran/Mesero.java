package restauran;

public class Mesero {
    //atributos
    private int id;
    private int tipoMesero;
    private String nombre = "";
    Cocina meseroC = new Cocina();
    Bebidas meseroB = new Bebidas();

    public Mesero(int num,int t,String n) {
        id = num;
        nombre = n;
        tipoMesero = t;
    }

    //metodos
    public int getId() {
        return id;
    }

    public String getNombre(){
        return nombre;
    }

    public String getTipo(){
        if(tipoMesero == 1){
            return "mesero";
        }else{
            return "barman";
        }
    }

    public String menu(){
        String temp="";
        if(tipoMesero == 1){
            for(int i=0; i < meseroC.getNumero() ;i++){
                temp += "plato ";
                temp += i+1;
                temp += "      $";
                temp += meseroC.precio(i);
                temp += "\n";
            } 
        }else{
            for(int i=0; i < meseroB.getNumero() ;i++){
                temp += "bebida ";
                temp += i+1;
                temp += "      $";
                temp += meseroB.precio(i);
                temp += "\n";
            } 
        }
        return temp;
    }

    public int precio(int num){
        if(tipoMesero == 1){
            return meseroC.precio(num);
        }else{
            return meseroB.precio(num);
        }
    }
}
