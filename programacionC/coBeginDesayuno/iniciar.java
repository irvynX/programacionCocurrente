public class iniciar{
    public static void main(String[] args) {
        s1 s1 = new s1();
        s2 s2 = new s2(s1);
        s3 s3 = new s3();
        s4 s4 = new s4();
        s5 s5 = new s5(s3);


        s1.start();
        s2.start();
        s3.start();
        s4.start();
        s5.start();
    }  
}