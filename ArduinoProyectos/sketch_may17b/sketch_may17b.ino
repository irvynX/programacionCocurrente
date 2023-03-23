
    #include <Adafruit_NeoPixel.h>
    #include <FastLED.h>

    Adafruit_NeoPixel pixels(89, 26, NEO_GRB + NEO_KHZ800);
    //Paso 1
const int pins[8] = {2,3,4,5,6,7,8,9}; 

//Paso 2
const byte vumeter[9] = {0b00000000,  //0
                            0b00000001, //1
                            0b00000011, //2
                            0b00000111, //3
                            0b00001111, //4
                            0b00011111, //5
                            0b00111111, //6
                            0b01111111, //7
                            0b11111111  //8
                        };
     int maximo = 0;
     int positionLed = 0;
     int previo = 0;
//Paso 3
void setup() {
    pinMode(26, OUTPUT);  
    pinMode(27, INPUT);  
    pixels.begin();
    Serial.begin(9600);
}

//Paso 4
void loop() {
    previo = positionLed;
    pixels.clear();
    //Lectura del puerto A0
    int valueAnalog = analogRead(27);
    //Serial.print(valueAnalog);
    //Conversión para obtener la secuencia
    positionLed = (valueAnalog-1975)/1;
    if(positionLed < 1){
      positionLed = previo;
    }
    if(positionLed > 20){
      positionLed = 20;
    }
    if(positionLed>maximo){
      maximo = positionLed;
    }
    Serial.println(positionLed);
    lightVumeter(positionLed, previo);
}

//Paso 5
void lightVumeter(int number,int prev) {
  if(number > (prev + 5)){
    int dif = number - prev;
    for(int i=prev; i<number; i++) { // For each pixel...
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
        pixels.show();
    }
  }
  if(number < (prev - 5)){
    for(int i=prev; i>number; i--) { // For each pixel...
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();
    }
  }
}
    
    
    
