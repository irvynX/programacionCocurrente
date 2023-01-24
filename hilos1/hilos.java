package hilos1;

public class hilos extends Thread {
	
	public void run(){ 
		
		System.out.println("Hola soy un hilo :)");
		
		
	}
	

	public static void main(String[] args) {
		hilos miprimerHilo=new hilos();
		miprimerHilo.start();
		
	}

}
