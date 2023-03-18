package actividad6Part2;

public class menu {
    public float[] precioB = {10,15,12,8};
    public float[] precioC = {50,60,70,30};
    private String menuC = "\t -----MENU----- \n1.-frijoles y huevo con salchicha: $" + precioC[0] + ".00\n2.-pozole: $" + precioC[1] + ".00\n3.-mole: $" + precioC[2] + ".00\n4.-pan y cafe: $" + precioC[3]; 
    private String menuB = "\t -----MENU----- \n1.-agua de sabor: $" + precioB[0] + ".00\n2.-coca cola: $" + precioB[1] + ".00\n3.-refresco de sabor: $" + precioB[2] + ".00\n4.-agua: $" + precioB[3];
    
    
    public String menuComida(){
        return menuC;
    }

    public String menuBebidas(){
        return menuB;
    }
}

