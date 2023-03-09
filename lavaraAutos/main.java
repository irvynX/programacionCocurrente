package lavaraAutos;

public class main {
    public static void main(String[] args) {
        bote bote = new bote();
        agua agua = new agua();
        boteLLeno boteLLeno = new boteLLeno();
        tapetes tapetes = new tapetes();
        tapeteRemojado tapeteRemojado = new tapeteRemojado();
        aspiradora aspiradora = new aspiradora();
        autoAspirado autoAspirado = new autoAspirado();
        cepillo cepillo = new cepillo();
        tapeteTallado tapeteTallado = new tapeteTallado();
        TapeteEnjuagado tapeteEnjuagado = new TapeteEnjuagado();
        aireFresco aireFresco = new aireFresco();
        tapeteSecos tapeteSecos = new tapeteSecos();
        autoEnjabonar autoEnjabonar = new autoEnjabonar();
        jabonEsponja jabonEsponja = new jabonEsponja();
        autoEnjuagado autoEnjuagado = new autoEnjuagado();
        autoSeco autoSeco = new autoSeco();
        pulidoraPasta pulidoraPasta = new pulidoraPasta();
        autoPulido autoPulido = new autoPulido();

        agua.run();
        bote.run();
        tapetes.run();
        aspiradora.run();
        cepillo.run();
        aireFresco.run();
        jabonEsponja.run();
        pulidoraPasta.run();
        while (agua.isAlive() && bote.isAlive()) {
        }
        boteLLeno.run();
        while(boteLLeno.isAlive() && jabonEsponja.isAlive()) {
        }
        autoEnjabonar.run();
        while (aspiradora.isAlive()) {
        }
        autoAspirado.run();
        while (autoAspirado.isAlive() && boteLLeno.isAlive() && autoEnjabonar.isAlive()) {
        }
        autoEnjuagado.run();
        while (autoEnjuagado.isAlive() && aireFresco.isAlive()) {
        }
        autoSeco.run();
        while (autoSeco.isAlive() && pulidoraPasta.isAlive()) {
        }
        autoPulido.run();
        while (boteLLeno.isAlive()){
        }
        tapeteRemojado.run();
        while (tapeteRemojado.isAlive()) {
        }
        tapeteTallado.run();
        while (tapeteTallado.isAlive() && boteLLeno.isAlive()) {
        }
        tapeteEnjuagado.run();
        while (tapeteEnjuagado.isAlive() && aireFresco.isAlive()) {
        }
        tapeteSecos.run();
    }
}
