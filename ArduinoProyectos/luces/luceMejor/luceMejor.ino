
    #include <Adafruit_NeoPixel.h>
    #include <FastLED.h>

    Adafruit_NeoPixel pixels(20, 23, NEO_GRB + NEO_KHZ800);
int intervaloRes = 5;
int tiempoPrevio = 0;
int tiempoActual = 0;
int led = 20;
int lugarLed = 0;
int brillo = 0;
bool respirar = true;
//Paso 3
void setup() {
    pinMode(23, OUTPUT);  
    pinMode(34, INPUT);  
    pixels.begin();
    Serial.begin(9600);
    //pixels.fill(pixels.Color(0,0,255), 0, 20);
    //pixels.show();
}

//Paso 4
void loop() {
  tiempoActual = millis();
  if (tiempoActual - tiempoPrevio >= intervaloRes) {
    tiempoPrevio = tiempoActual;

    if(respirar == true){
      //pixels.fill(pixels.Color(rojo, verde, azul), 0, 20);
      pixels.fill(pixels.Color(0, 0, 255), 0, 20);
      pixels.setBrightness(brillo);
      pixels.show();
      brillo++;
      if(brillo>=255){
        respirar = false;
      }
    }else{
      //pixels.fill(pixels.Color(rojo, verde, azul), 0, 20);
      pixels.fill(pixels.Color(0, 0, 255), 0, 20);
      pixels.setBrightness(brillo);
      pixels.show();
      brillo--;
      if(brillo<=0){
        respirar = true;
      }
    }
    
  }
}
    
    
    
