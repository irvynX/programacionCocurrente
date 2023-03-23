// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        26 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 20 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 125 // Time (in milliseconds) to pause between pixels
int valor = 0;
int previo = 0;
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  // END of Trinket-specific code.
  
  pinMode(27,INPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}

void loop() {
  previo = valor;
  pixels.clear(); // Set all pixel colors to 'off'
  valor = analogRead(27);
  if(valor>1){
    if(previo<1){
      pixels.fill(pixels.Color(0,0,255), 0, NUMPIXELS);
  
     pixels.show();
    }
  }else{
    pixels.fill(pixels.Color(0,0,0), 0, NUMPIXELS);
  
     pixels.show();
  }

  Serial.print(previo);
  Serial.print(" - ");
  Serial.println(valor);

  //if((previo-valor)>2 || (valor-previo)>2){
   /* if(valor>previo){
      for(int i=previo; i<valor; i++){
         pixels.setPixelColor(i, pixels.Color(0, 255, 0));
  
         pixels.show();
      }
    }
    if(previo>valor){
      for(int i=valor; i<previo; i++){
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  
        pixels.show();
      }
    }  
  //}
  /*
  for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(255,255,255));
  
    pixels.show();
    delay(DELAYVAL); // Pause before next pass through loop*/
  //}*/

//pixels.clear();
//for(int i=0; i<NUMPIXELS; i++){
         //pixels.setPixelColor(i, pixels.Color(255, 255, 255));
         //pixels.fill(pixels.Color(0,0,255), 0, valor);
  
         //pixels.show();
         //delay(DELAYVAL);
     // }
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
}
