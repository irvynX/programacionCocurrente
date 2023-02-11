public class Hilo8 extends Thread{
	private static int cont=1;
public Hilo8(String string) {
		super(string);
		// TODO Auto-generated constructor stub
	}
	public void run(){
		aumentar();
	}
	public synchronized void aumentar(){
		  if (Thread.currentThread().getId()%2!=0)
		  {   Thread.yield();	
		  cont+=3;
		
		  }
		  else cont+=1;
		
			  System.out.println("El hilo "+Thread.currentThread().getName()+" aumento el contador= "+ (cont));
	}
	

	public static void main(String[] args) {
		Hilo8 uno=new Hilo8("primer hilo");
	    Hilo8 dos=new Hilo8("segundo hilo");
	    int i=100;
	    dos.setPriority(Thread.MAX_PRIORITY);
	    uno.start();
	    dos.start();
	   
	    while ((i>0)&&(uno.getState()!=Thread.State.TERMINATED)&&(dos.getState()!=Thread.State.TERMINATED)){
		System.out.println("El hilo "+ uno.getId()+" se llama "+uno.getName()+" y su estado es "+uno.getState().toString());
		
		System.out.println("El hilo "+ dos.getId()+" se llama "+dos.getName()+" y su estado es "+dos.getState().toString());
		i--;
	}   
	    try{
	    uno.join();
	    dos.join();
	    }catch (InterruptedException e){
	    	e.printStackTrace();
	    }
	    System.out.println("Los hilos han terminado");

	}
}