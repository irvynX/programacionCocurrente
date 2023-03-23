#define pin_led 27//Defininmos el pin de conexión de la tira LED
#define numero_led 20//Definimos el número de LED´s de nuestra tira. En nuestro caso es 30 LED´s en 0,5m 

int pinJack = 27;
int valorJack = 0;
int maximo_anterior = 0;
int minimo_anterior = 1023;
int maximo_final=0;
int minimo_final=0;


unsigned long tiempoAhora =0;

//Creamos un objeto de la tira
//Primer parámetro = cantidad de pixeles en la tira
//Segundo parámetro = pin de conexión a Arduino
//Tercer parámetro:
  //NEO_KHZ800  800 KHz velocidad de datos (WS2812 y nuevos)
  //NEO_KHZ400  400 KHz velocidad de datos (WS2811 y anteriores)
  //NEO_GRB     flujo de datos en el orden GRB (WS2812 y nuevos)
  //NEO_RGB     fluo de datos en el orden RGB (versiones más antiguas)
Adafruit_NeoPixel tira_LED(numero_led, pin_led, NEO_GRB + NEO_KHZ800);

void vumetro(void);

void setup(){
  Serial.begin(9600);
  tira_LED.begin();//Iniciamos la tira LED
  tira_LED.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  tira_LED.show();//mandamos un valor 0 a la  tira LED, es decir, iniciamos con la tira LED apagada
  tiempoAhora = millis();
}

void loop(){
  while(millis()-tiempoAhora< 50){
    valorJack = analogRead(pinJack);
    Serial.print("ValorJack: ");
    Serial.println(valorJack);
    if(valorJack>maximo_anterior){//Si el valor leido por el ADC en el pin del jack es mayor que el guardado anteriormente (maximo_anterior lo iniciamos en 0)...
       maximo_anterior=valorJack;//...guardamos el nuevo máximo
    }
    if(valorJack<minimo_anterior){
      minimo_anterior = valorJack;
    }
    valorJack=0;//e iniciamos en cero de nuevo la variable de registro de datos
  }


  maximo_final=map(maximo_anterior, 300, 750, 0, 100);
  maximo_final=constrain(maximo_final, 0 ,100);
  minimo_final=map(minimo_anterior, 300, 750, 0, 100);
  minimo_final=constrain(minimo_final, 0 ,100);
  Serial.print("Valor máximo = ");
  Serial.println(maximo_anterior);
  Serial.print("Valor mínimo = ");
  Serial.println(minimo_anterior);
  Serial.print("Maximo anterior mapeado = ");
  Serial.println(maximo_final);
  Serial.print("Minimo anterior mapeado = ");
  Serial.println(minimo_final);
  //delay(2000);
  vumetro();
  
  tira_LED.clear();
  //------------Reiniciamos las variable---------/////
  maximo_anterior = 0;
  minimo_anterior = 1023;
  tiempoAhora=millis();//Guardamos el nuevo tiempo anterior antes de entrar de nuevo en el while
}

void vumetro(){
  //Serial.print("He entrado");
  int i = 0;
  if(minimo_final==maximo_final || minimo_final+1==maximo_final || minimo_final == maximo_final+1){
    for(i=0; i<16; i++){
      tira_LED.setPixelColor(i, tira_LED.Color(0,0,0));//Si lo que tenemos a la entrada es el nivel de continua, el máximo y el mínimo serán iguales. En este caso apagamos la tira LED por completo
      tira_LED.show();
    }
  }
  else{

    int numero_led_encendidos = map(maximo_final, 0, 100, 0, 30);
    numero_led_encendidos = constrain(numero_led_encendidos, 0 ,30);
    Serial.println(numero_led_encendidos);
    for(i=0; i<numero_led_encendidos; i++){
      //Serial.print("Aquí también");
      tira_LED.setPixelColor(i, tira_LED.Color(random(255), random(255), random(0)));
      tira_LED.show();
    }   
  }
}
