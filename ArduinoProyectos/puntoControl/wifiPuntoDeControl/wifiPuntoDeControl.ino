const String Pagina1 = R"====(HTTP/1.1 200 OK
Content-Type: text/html

<!doctype html>
<html lang="en">

<head>
    <meta charset='utf-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <title>mis luces</title>
    <link href='https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css' rel='stylesheet'
        integrity='sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3' crossorigin='anonymous'>

    <link rel='stylesheet' href='https://cdn.jsdelivr.net/npm/bootstrap-icons@1.8.1/font/bootstrap-icons.css'>
</head>

<body>
    <div class="row">
          <div class='d-flex justify-content-around m-1'>
                <h1>LAMPARA</h1>
          </div>
          <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/lampara' class='btn btn-outline-primary'>)====";

const String Pagina2 = R"====(</a>
          </div>
        <div class="gabinete col-sm-6">
            <div class='d-flex justify-content-around m-1'>
                <h1>TIRA GABINETE</h1>
            </div>
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/cambiar' class='btn btn-outline-primary'>)====";
const String Pagina3 = R"====(</a>
            </div>
        
            <div class='d-flex justify-content-around m-1'>
                <h1>EFECTOS</h1>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:estatico' class='btn btn-outline-primary m-auto'>ESTATICO</a>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:musica' class='btn btn-outline-primary'>MUSICA</a>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:llenarTira' class='btn btn-outline-primary'>LLENAR TIRA</a>
            </div>
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/efecto:respiracion' class='btn btn-outline-primary'>RESPIRACIÓN</a>
            </div>
        
            <div class='d-flex justify-content-around m-1'>
                <h1>COLOR</h1>
            </div>
            <div class="d-flex justify-content-around m-1">
                <div id='color'>
                    <input type='color' value="#FF0000">
                </div>
            </div>
            
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/color:255,0,0,'  id='enviar' class='btn btn-outline-primary'>ENVIAR</a>
            </div>
        </div>
        <div class="escritorio col-sm-6">
            <div class='d-flex justify-content-around m-1'>
                <h1>TIRA ESCRITORIO</h1>
            </div>
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/cambiar2' class='btn btn-outline-primary'>)====";
const String Pagina4 = R"====(</a>
            </div>
        
            <div class='d-flex justify-content-around m-1'>
                <h1>EFECTOS</h1>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:estatico2' class='btn btn-outline-primary m-auto'>ESTATICO</a>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:musica2' class='btn btn-outline-primary'>MUSICA</a>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:llenarTira2' class='btn btn-outline-primary'>LLENAR TIRA</a>
            </div>
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/efecto:respiracion2' class='btn btn-outline-primary'>RESPIRACIÓN</a>
            </div>
        
            <div class='d-flex justify-content-around m-1'>
                <h1>COLOR</h1>
            </div>
            <div class="d-flex justify-content-around m-1">
                <div id='color2'>
                    <input type='color' value="#FF0000">
                </div>
            </div>
            
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/colo2:255,0,0,'  id='enviar2' class='btn btn-outline-primary'>ENVIAR</a>
            </div>
        </div>
    </div>
    
    <script src='https://code.jquery.com/jquery-3.5.1.min.js" integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0='' crossorigin='anonymous'></script>
    <script>
        var color = document.getElementById('color');
        var color2 = document.getElementById('color2');
        var enviar = document.getElementById('enviar');
        var enviar2 = document.getElementById('enviar2');

        color.addEventListener("change", function(e){
            var valor = e.target.value;
            var R = parseInt(valor[1] + valor[2], 16);
            var G = parseInt(valor[3] + valor[4], 16);
            var B = parseInt(valor[5] + valor[6], 16);
            console.log(R);
            console.log(G);
            console.log(B);
            temporal ='';
            temporal += '/color:' + R + ',' + G + ',' + B + ',';

            console.log(temporal);
            enviar.href=temporal;
        })
        color2.addEventListener("change", function(e){
            var valor = e.target.value;
            var R = parseInt(valor[1] + valor[2], 16);
            var G = parseInt(valor[3] + valor[4], 16);
            var B = parseInt(valor[5] + valor[6], 16);
            console.log(R);
            console.log(G);
            console.log(B);
            temporal ='';
            temporal += '/colo2:' + R + ',' + G + ',' + B + ',';

            console.log(temporal);
            enviar2.href=temporal;
        })
    </script>

<script src='https://code.jquery.com/jquery-3.5.1.min.js' integrity='sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0=' crossorigin='anonymous'></script>
</body>

</html>
)====";

#if defined(ESP32)
// Librerias para ESP32
#include <WiFi.h>
#include <WiFiMulti.h>
#include <ESPmDNS.h>
#include <HTTPClient.h>
WiFiMulti wifiMulti;

#elif defined(ESP8266)
// Librerias para ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>
ESP8266WiFiMulti wifiMulti;

#endif

#include <HTTPClient.h>

int rele = 22;
int estadoRele;
boolean Estado3 = true;
boolean Estado = true;
boolean Estado2 = true;

const uint32_t TiempoEsperaWifi = 5000;

unsigned long TiempoActual = 0;
unsigned long TiempoAnterior = 0;
const long TiempoCancelacion = 500;

WiFiServer servidor(80);

// pratiras led
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

// gabinete
Adafruit_NeoPixel pixels(30, 23, NEO_GRB + NEO_KHZ800);
// escritorio
Adafruit_NeoPixel pixels2(30, 21, NEO_GRB + NEO_KHZ800);
// repisa
Adafruit_NeoPixel pixels3(60, 18, NEO_GRB + NEO_KHZ800);
// reloj
Adafruit_NeoPixel pixelsR(70, 19, NEO_GRB + NEO_KHZ800);
// globales
int dividir = 3;
int restar = 2500;

// gabinete
int maximo = 0;
int previo = 0;
int rojo = 255;
int verde = 0;
int azul = 0;
int efecto = 0;
// escritorio
int maximo2 = 0;
int previo2 = 0;
int rojo2 = 255;
int verde2 = 0;
int azul2 = 0;
int efecto2 = 0;
// repisa
int maximo3 = 0;
int previo3 = 0;
int rojo3 = 255;
int verde3 = 0;
int azul3 = 0;
int efecto3 = 0;
// reloj
int rojoR = 255;
int verdeR = 0;
int azulR = 0;
int tiempoPrevioR = 0;
int tiempoActualR = 0;
int intervaloR = 15000;
int ledFila = 14;

// efecto musica
int ultimo1 = 0;
int ultimo2 = 0;
int ultimo3 = 0;
int tiempoPrevio1 = 0;
int tiempoActual1 = 0;
int tiempoPrevio2 = 0;
int tiempoActual2 = 0;
int tiempoPrevio3 = 0;
int tiempoActual3 = 0;
int intervalo1 = 5;
int intervalo2 = 75;
int intervalo3 = 75;
int maximoMusica = 0;

// efecto llenar tira
int intervalo = 25;
int tiempoPrevio = 0;
int tiempoActual = 0;
int led = 30;
int lugarLed = 0;
int led2 = 30;
int lugarLed2 = 0;

// efecto respiracion
int intervaloRes = 5;
int brillo = 0;
bool respirar = true;

// notificacion o alarma
bool enAlarma = false;
int tInicio = 0;
int tActual = 0;
int noti = 15000;
bool REstado;
bool REstado2;
bool repisa;
int REstado3;
int Refecto = 3;
int Refecto2 = 3;
int Refecto3 = 3;
int RintervaloRes = 8;
int Rrojo = 255;
int Rverde = 255;
int Razul = 255;
int Rrojo2 = 255;
int Rverde2 = 255;
int Razul2 = 255;
int Rrojo3 = 255;
int Rverde3 = 255;
int Razul3 = 255;
bool activo = false;

void setup()
{
  Serial.begin(115200);
  Serial.println("\nIniciando multi Wifi");

  wifiMulti.addAP("Totalplay-2DA1-2", "irvyn2703");

  WiFi.mode(WIFI_STA);
  Serial.print("Conectando a Wifi ..");
  while (wifiMulti.run(TiempoEsperaWifi) != WL_CONNECTED)
  {
  }
  Serial.println(".. Conectado");
  Serial.print("SSID:");
  Serial.print(WiFi.SSID());
  Serial.print(" ID:");
  Serial.println(WiFi.localIP());

  if (!MDNS.begin("cuarto"))
  {
    Serial.println("Erro configurando mDNS!");
    while (1)
    {
      delay(1000);
    }
  }
  Serial.println("mDNS configurado");

  servidor.begin();

  MDNS.addService("http", "tcp", 80);

  // tiras led
  pinMode(34, INPUT);
  pinMode(23, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(rele, OUTPUT);

  pixels.begin();
  Serial.println("tiras led gabinete preparadas");

  pixels2.begin();
  Serial.println("tiras led escritorio preparadas");

  pixels3.begin();
  Serial.println("tiras led repisa preparadas");

  pixelsR.begin();
  for (int i = 0; i < 35; i++)
  {
    pixelsR.setPixelColor(i, 255, 255, 255);
    pixelsR.setPixelColor(69 - i, 255, 255, 255);
    pixelsR.setBrightness(255-i*7.2);
    pixelsR.show();
    delay(100);
  }
  pixelsR.setBrightness(1);
  delay(1000);
  pixelsR.clear();
}

void loop()
{
#if defined(ESP8266)
  MDNS.update();
#endif
  WiFiClient cliente = servidor.available();

  if (cliente)
  {
    Serial.println("Nuevo Cliente");
    TiempoActual = millis();
    TiempoAnterior = TiempoActual;
    String LineaActual = "";

    while (cliente.connected() && TiempoActual - TiempoAnterior <= TiempoCancelacion)
    {
      if (cliente.available())
      {
        TiempoActual = millis();
        char Letra = cliente.read();
        if (Letra == '\n')
        {
          if (LineaActual.length() == 0)
          {
            ResponderCliente(cliente);
            break;
          }
          else
          {
            VerificarMensaje(LineaActual);
            LineaActual = "";
          }
        }
        else if (Letra != '\r')
        {
          LineaActual += Letra;
        }
      }
    }

    cliente.stop();
    Serial.println("Cliente Desconectado");
    Serial.println();
  }

  tiempoActualR = millis();
  if (tiempoActualR - tiempoPrevioR >= intervaloR)
  {
    reloj();
    tiempoPrevioR = tiempoActualR;
  }

  if (activo == true)
  {
    tActual = millis();
    if (tActual - tInicio >= noti)
    {
      Estado = REstado;
      Estado2 = REstado2;
      Estado3 = repisa;
      digitalWrite(rele, REstado3);
      efecto = Refecto;
      efecto2 = Refecto2;
      efecto3 = Refecto3;
      intervaloRes = RintervaloRes;
      rojo = Rrojo;
      verde = Rverde;
      azul = Razul;
      rojo2 = Rrojo2;
      verde2 = Rverde2;
      azul2 = Razul2;
      rojo3 = Rrojo3;
      verde3 = Rverde3;
      azul3 = Razul3;
      enAlarma = false;
      /*Serial.println(Estado);
      Serial.println(Estado2);
      Serial.println(Estado3);
      Serial.println(efecto);
      Serial.println(efecto2);
      Serial.println(intervaloRes);
      Serial.println(rojo);
      Serial.println(verde);
      Serial.println(azul);*/
      activo = false;
    }
  }

  if (Estado == true)
  {
    if (efecto == 0)
    {
      pixels.fill(pixels.Color(rojo, verde, azul), 0, 30);
      pixels.show();
    }
  }
  else
  {
    pixels.fill(pixels.Color(0, 0, 0), 0, 30);
    pixels.show();
  }
  if (Estado2 == true)
  {
    if (efecto2 == 0)
    {
      pixels2.fill(pixels2.Color(rojo2, verde2, azul2), 0, 30);
      pixels2.show();
    }
  }
  else
  {
    pixels2.fill(pixels2.Color(0, 0, 0), 0, 30);
    pixels2.show();
  }
  if (Estado3 == true)
  {
    if (efecto3 == 0)
    {
      pixels3.fill(pixels3.Color(rojo3, verde3, azul3), 0, 60);
      pixels3.show();
    }
  }
  else
  {
    pixels3.fill(pixels3.Color(0, 0, 0), 0, 60);
    pixels3.show();
  }

  if (Estado == true || Estado2 == true || Estado3 == true)
  {
    if ((Estado == true && efecto == 1) || (Estado2 == true && efecto2 == 1) || (Estado3 == true && efecto3 == 1))
    {
      // Lectura del puerto A0
      int valueAnalog = analogRead(34);
      // Serial.print(valueAnalog);
      // Conversión para obtener la secuencia
      int positionLed = (valueAnalog - restar) / dividir;
      if (positionLed > maximo)
      {
        maximo = positionLed;
      }
      // Serial.println(positionLed);
      lightVumeter(positionLed);
    }
    if ((Estado == true && efecto == 2) || (Estado2 == true && efecto2 == 2) || (Estado3 == true && efecto3 == 2))
    {
      tiempoActual = millis();

      // Serial.println(lugarLed);
      if (tiempoActual - tiempoPrevio >= intervalo)
      {
        tiempoPrevio = tiempoActual;

        if (Estado == true && efecto == 2)
        {
          pixels.setPixelColor(lugarLed, pixels.Color(rojo, verde, azul));
          // pixels.setPixelColor(lugarLed, pixels.Color(0, 0, 255));
          pixels.setPixelColor((lugarLed - 1), pixels.Color(0, 0, 0));
          pixels.show();
        }
        if (Estado2 == true && efecto2 == 2)
        {
          pixels2.setPixelColor(lugarLed, pixels2.Color(rojo2, verde2, azul2));
          // pixels.setPixelColor(lugarLed, pixels.Color(0, 0, 255));
          pixels2.setPixelColor((lugarLed - 1), pixels2.Color(0, 0, 0));
          pixels2.show();
        }
        if (Estado3 == true && efecto3 == 2)
        {
          pixels3.setPixelColor(lugarLed2, pixels3.Color(rojo3, verde3, azul3));
          // pixels.setPixelColor(lugarLed, pixels.Color(0, 0, 255));
          pixels3.setPixelColor((lugarLed2 - 1), pixels2.Color(0, 0, 0));
          pixels3.show();
        }
        lugarLed++;
        if (lugarLed == led)
        {
          led--;
          lugarLed = 0;
        }
        if (led == 0)
        {
          led = 30;
        }

        lugarLed2++;
        if (lugarLed2 == led2)
        {
          led2--;
          lugarLed2 = 0;
        }
        if (led2 == 0)
        {
          led2 = 60;
        }
      }
    }
    if ((Estado == true && efecto == 3) || (Estado2 == true && efecto2 == 3) || (Estado3 == true && efecto3 == 3))
    {
      tiempoActual = millis();
      if (tiempoActual - tiempoPrevio >= intervaloRes)
      {
        tiempoPrevio = tiempoActual;

        if (respirar == true)
        {
          if (Estado == true && efecto == 3)
          {
            pixels.fill(pixels.Color(rojo, verde, azul), 0, 30);
            // pixels.fill(pixels.Color(0, 0, 255), 0, 20);
            pixels.setBrightness(brillo);
            pixels.show();
          }
          if (Estado2 == true && efecto2 == 3)
          {
            pixels2.fill(pixels2.Color(rojo2, verde2, azul2), 0, 30);
            // pixels.fill(pixels.Color(0, 0, 255), 0, 20);
            pixels2.setBrightness(brillo);
            pixels2.show();
          }
          if (Estado3 == true && efecto3 == 3)
          {
            pixels3.fill(pixels3.Color(rojo3, verde3, azul3), 0, 60);
            // pixels.fill(pixels.Color(0, 0, 255), 0, 20);
            pixels3.setBrightness(brillo);
            pixels3.show();
          }
          brillo++;
          if (brillo >= 255)
          {
            respirar = false;
          }
        }
        else
        {
          if (Estado == true && efecto == 3)
          {
            pixels.fill(pixels.Color(rojo, verde, azul), 0, 30);
            // pixels.fill(pixels.Color(0, 0, 255), 0, 20);
            pixels.setBrightness(brillo);
            pixels.show();
          }
          if (Estado2 == true && efecto2 == 3)
          {
            pixels2.fill(pixels2.Color(rojo2, verde2, azul2), 0, 30);
            // pixels.fill(pixels.Color(0, 0, 255), 0, 20);
            pixels2.setBrightness(brillo);
            pixels2.show();
          }
          if (Estado3 == true && efecto3 == 3)
          {
            pixels3.fill(pixels3.Color(rojo3, verde3, azul3), 0, 60);
            // pixels.fill(pixels.Color(0, 0, 255), 0, 20);
            pixels3.setBrightness(brillo);
            pixels3.show();
          }
          brillo--;
          if (brillo <= 0)
          {
            respirar = true;
          }
        }
      }
    }
  }
}

void cero(int section)
{
  pixelsR.setPixelColor(0 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), 0, 0, 0);
}

void uno(int section)
{
  pixelsR.setPixelColor(0 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), 0, 0, 0);
}

void dos(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void tres(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void cuatro(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void cinco(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void seis(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void siete(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void ocho(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void nueve(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila*2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila*2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila*4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila*4 + (section), rojoR, verdeR, azulR);
}

void reloj(){
  // metodo reloj inicio
    pixelsR.setPixelColor(19, 157, 176, 157);
    pixelsR.setPixelColor(20, 157, 176, 157);
    pixelsR.setPixelColor(43, 157, 176, 157);
    pixelsR.setPixelColor(44, 157, 176, 157);

    HTTPClient http;

    http.begin("http://worldtimeapi.org/api/timezone/America/Mexico_City");

    int httpCode = http.GET();

    if (httpCode > 0)
    {
      if (httpCode == HTTP_CODE_OK)
      {
        String payload = http.getString();
        int mensaje = payload.indexOf("datetime");
        int contador = 0;
        String hora = "";

        while (payload[(mensaje + contador)] != 'T')
        {
          contador++;
        }
        mensaje = mensaje + contador + 1;
        contador = 0;
        while (payload[(mensaje + contador)] != '.')
        {
          hora += payload[(mensaje + contador)];
          contador++;
        }
        // USE_SERIAL.println(hora);

        String aux = "";
        aux += hora[0];
        aux += hora[1];
        int h = aux.toInt();
        int m1 = String(hora[3]).toInt();
        int m2 = String(hora[4]).toInt();

        if (h > 12)
        {
          h = h - 12;
        }

        if (h == 0)
        {
          cero(0);
          cero(4);
        }
        else if (h == 1)
        {
          cero(0);
          uno(4);
        }
        else if (h == 2)
        {
          cero(0);
          dos(4);
        }
        else if (h == 3)
        {
          cero(0);
          tres(4);
        }
        else if (h == 4)
        {
          cero(0);
          cuatro(4);
        }
        else if (h == 5)
        {
          cero(0);
          cinco(4);
        }
        else if (h == 6)
        {
          cero(0);
          seis(4);
        }
        else if (h == 7)
        {
          cero(0);
          siete(4);
        }
        else if (h == 8)
        {
          cero(0);
          ocho(4);
        }
        else if (h == 9)
        {
          cero(0);
          nueve(4);
        }
        else if (h == 10)
        {
          uno(0);
          cero(4);
        }
        else if (h == 11)
        {
          uno(0);
          uno(4);
        }
        else
        {
          uno(0);
          dos(4);
        }

        if (m1 == 0)
        {
          cero(7);
        }
        else if (m1 == 1)
        {
          uno(7);
        }
        else if (m1 == 2)
        {
          dos(7);
        }
        else if (m1 == 3)
        {
          tres(7);
        }
        else if (m1 == 4)
        {
          cuatro(7);
        }
        else if (m1 == 5)
        {
          cinco(7);
        }
        else if (m1 == 6)
        {
          seis(7);
        }
        else if (m1 == 7)
        {
          siete(7);
        }
        else if (m1 == 8)
        {
          ocho(7);
        }
        else
        {
          nueve(7);
        }



        if (m2 == 0)
        {
          cero(11);
        }
        else if (m2 == 1)
        {
          uno(11);
        }
        else if (m2 == 2)
        {
          dos(11);
        }
        else if (m2 == 3)
        {
          tres(11);
        }
        else if (m2 == 4)
        {
          cuatro(11);
        }
        else if (m2 == 5)
        {
          cinco(11);
        }
        else if (m2 == 6)
        {
          seis(11);
        }
        else if (m2 == 7)
        {
          siete(11);
        }
        else if (m2 == 8)
        {
          ocho(11);
        }
        else
        {
          nueve(11);
        }
        pixelsR.show();
      }
    }

    http.end();
    // fin del metodo
}

void notificacion(int R, int G, int B)
{
  Estado = true;
  Estado2 = true;
  Estado3 = true;
  efecto = 3;
  efecto2 = 3;
  efecto3 = 3;
  intervaloRes = 1;
  rojo = R;
  verde = G;
  azul = B;
  rojo2 = R;
  verde2 = G;
  azul2 = B;
  rojo3 = R;
  verde3 = G;
  azul3 = B;
}
void alarma()
{
  Estado = true;
  Estado2 = true;
  Estado3 = true;
  digitalWrite(rele, LOW);
  efecto = 3;
  efecto2 = 3;
  efecto3 = 3;
  intervaloRes = 8;
  rojo = 255;
  verde = 255;
  azul = 255;
  rojo2 = 255;
  verde2 = 255;
  azul2 = 255;
  rojo3 = 255;
  verde3 = 255;
  azul3 = 255;
}

void lightVumeter(int number)
{
  if (number < 0)
  {
    number = 0;
  }
  if (number > 30)
  {
    number = 30;
  }
  /*Serial.print("entrada:");
  Serial.println(number);*/
  if (number > maximoMusica)
  {
    maximoMusica = number;
  }

  tiempoActual1 = millis();
  if (tiempoActual1 - tiempoPrevio1 >= intervalo1)
  {
    /*Serial.print("------------------");
    Serial.println(maximoMusica);*/
    tiempoPrevio1 = tiempoActual1;
    if (maximoMusica <= 30)
    {
      if (maximoMusica > ultimo1)
      {
        ultimo1 = maximoMusica;
        intervalo2 = 300;
      }
      if (Estado == true && efecto == 1)
      {
        pixels.fill(pixels.Color(rojo, verde, azul), 0, maximoMusica);
        pixels.fill(pixels.Color(0, 0, 0), maximoMusica, 30);
        // ultimo
        pixels.setPixelColor(ultimo1, rojo, verde, azul);
        pixels.show();
      }
      if (Estado2 == true && efecto2 == 1)
      {
        pixels2.fill(pixels2.Color(rojo2, verde2, azul2), 15, 15 + maximoMusica / 2);
        pixels2.fill(pixels2.Color(rojo2, verde2, azul2), 15 - maximoMusica / 2, 15);
        pixels2.fill(pixels2.Color(0, 0, 0), 0, 15 - maximoMusica / 2);
        pixels2.fill(pixels2.Color(0, 0, 0), 15 + maximoMusica / 2, 30);
        // ultimo
        pixels2.setPixelColor(15 + ultimo1 / 2, rojo2, verde2, azul2);
        pixels2.setPixelColor(15 - ultimo1 / 2, rojo2, verde2, azul2);
        pixels2.show();
      }
      if (Estado3 == true && efecto3 == 1)
      {
        pixels.fill(pixels.Color(rojo, verde, azul), 0, maximoMusica * 2);
        pixels.fill(pixels.Color(0, 0, 0), maximoMusica * 2, 60);
        // ultimo
        pixels.setPixelColor(ultimo1 * 2, rojo, verde, azul);
        pixels.show();
      }

      tiempoActual2 = millis();
      if (tiempoActual2 - tiempoPrevio2 >= intervalo2)
      {
        intervalo2 = 175;
        tiempoPrevio2 = tiempoActual2;
        if (Estado == true && efecto == 1)
        {
          pixels.setPixelColor(ultimo1, 0, 0, 0);
        }
        if (Estado2 == true && efecto2 == 1)
        {
          pixels2.setPixelColor(15 + ultimo1 / 2, 0, 0, 0);
          pixels2.setPixelColor(15 - ultimo1 / 2, 0, 0, 0);
        }
        if (Estado3 == true && efecto3 == 1)
        {
          pixels3.setPixelColor(ultimo1 * 2, 0, 0, 0);
        }
        if (ultimo1 >= 0)
        {
          ultimo1--;
          if (Estado == true && efecto == 1)
          {
            pixels.setPixelColor(ultimo1, rojo, verde, azul);
            pixels.show();
          }
          if (Estado2 == true && efecto2 == 1)
          {
            pixels2.setPixelColor(15 + ultimo1 / 2, rojo2, verde2, azul2);
            pixels2.setPixelColor(15 - ultimo1 / 2, rojo2, verde2, azul2);
            pixels2.show();
          }
          if (Estado3 == true && efecto3 == 1)
          {
            pixels3.setPixelColor(ultimo1 * 2, rojo, verde, azul);
            pixels3.show();
          }
        }
      }

      /*if (tira == 2)
      {
        if (maximoMusica > ultimo2)
        {
          ultimo2 = maximoMusica;
          intervalo2 = 300;
        }
        pixels2.fill(pixels2.Color(rojo2, verde2, azul2), 0, maximoMusica);
        pixels2.fill(pixels2.Color(0, 0, 0), maximoMusica, 30);
        // ultimo
        pixels2.setPixelColor(ultimo2, rojo2, verde2, azul2);
        pixels2.show();

        if (tiempoActual3 - tiempoPrevio3 >= intervaloRes)
        {
          intervalo3 = 175;
          tiempoPrevio3 = tiempoActual3;
          pixels2.setPixelColor(ultimo2, 0, 0, 0);
          if (ultimo2 >= 0)
          {
            ultimo2--;
            pixels2.setPixelColor(ultimo2, rojo2, verde2, azul2);
            pixels2.show();
          }
        }
      }
    }*/
      maximoMusica = 0;
    }
  }
}

void VerificarMensaje(String Mensaje)
{
  int mensaje;
  if (Mensaje.indexOf("GET /enCasa") >= 0)
  {
    digitalWrite(rele, LOW);
    Estado = true;
    Estado2 = true;
    Estado3 = true;
  }
  if (Mensaje.indexOf("GET /notificacion:Whatsapp") >= 0)
  {
    if (enAlarma == false)
    {
      enAlarma = true;
      REstado = Estado;
      REstado2 = Estado2;
      REstado3 = digitalRead(rele);
      repisa = Estado3;
      Refecto = efecto;
      Refecto2 = efecto2;
      Refecto3 = efecto3;
      RintervaloRes = intervaloRes;
      Rrojo = rojo;
      Rverde = verde;
      Razul = azul;
      Rrojo2 = rojo2;
      Rverde2 = verde2;
      Razul2 = azul2;
      Rrojo3 = rojo3;
      Rverde3 = verde3;
      Razul3 = azul3;
      noti = 15000;
      activo = true;
      tInicio = millis();
      notificacion(0, 255, 0);
    }
  }
  if (Mensaje.indexOf("GET /notificacion:Facebook") >= 0)
  {
    if (enAlarma == false)
    {
      enAlarma = true;
      REstado = Estado;
      REstado2 = Estado2;
      REstado3 = digitalRead(rele);
      repisa = Estado3;
      Refecto = efecto;
      Refecto2 = efecto2;
      Refecto3 = efecto3;
      RintervaloRes = intervaloRes;
      Rrojo = rojo;
      Rverde = verde;
      Razul = azul;
      Rrojo2 = rojo2;
      Rverde2 = verde2;
      Razul2 = azul2;
      Rrojo3 = rojo3;
      Rverde3 = verde3;
      Razul3 = azul3;
      noti = 15000;
      activo = true;
      tInicio = millis();
      notificacion(0, 0, 255);
    }
  }
  if (Mensaje.indexOf("GET /notificacion:Youtube") >= 0)
  {
    if (enAlarma == false)
    {
      enAlarma = true;
      REstado = Estado;
      REstado2 = Estado2;
      REstado3 = digitalRead(rele);
      repisa = Estado3;
      Refecto = efecto;
      Refecto2 = efecto2;
      Refecto3 = efecto3;
      RintervaloRes = intervaloRes;
      Rrojo = rojo;
      Rverde = verde;
      Razul = azul;
      Rrojo2 = rojo2;
      Rverde2 = verde2;
      Razul2 = azul2;
      Rrojo3 = rojo3;
      Rverde3 = verde3;
      Razul3 = azul3;
      noti = 15000;
      activo = true;
      tInicio = millis();
      notificacion(200, 55, 0);
    }
  }
  if (Mensaje.indexOf("GET /notificacion:Correo") >= 0)
  {
    if (enAlarma == false)
    {
      enAlarma = true;
      REstado = Estado;
      REstado2 = Estado2;
      REstado3 = digitalRead(rele);
      repisa = Estado3;
      Refecto = efecto;
      Refecto2 = efecto2;
      Refecto3 = efecto3;
      RintervaloRes = intervaloRes;
      Rrojo = rojo;
      Rverde = verde;
      Razul = azul;
      Rrojo2 = rojo2;
      Rverde2 = verde2;
      Razul2 = azul2;
      Rrojo3 = rojo3;
      Rverde3 = verde3;
      Razul3 = azul3;
      noti = 15000;
      activo = true;
      tInicio = millis();
      notificacion(122, 255, 235);
    }
  }
  if (Mensaje.indexOf("GET /alarma") >= 0)
  {
    if (enAlarma == false)
    {
      enAlarma = true;
      REstado = Estado;
      REstado2 = Estado2;
      REstado3 = digitalRead(rele);
      repisa = Estado3;
      Refecto = efecto;
      Refecto2 = efecto;
      Refecto3 = efecto;
      RintervaloRes = intervaloRes;
      Rrojo = rojo;
      Rverde = verde;
      Razul = azul;
      Rrojo2 = rojo2;
      Rverde2 = verde2;
      Razul2 = azul2;
      Rrojo3 = rojo3;
      Rverde3 = verde3;
      Razul3 = azul3;
      noti = 60000;
      activo = true;
      tInicio = millis();
      alarma();
    }
  }
  if (Mensaje.indexOf("GET /fueraCasa") >= 0)
  {
    digitalWrite(rele, HIGH);
    Estado = false;
    Estado2 = false;
    Estado3 = false;
  }
  if (Mensaje.indexOf("GET /enPc") >= 0)
  {
    Estado = true;
    Estado2 = true;
    Estado3 = true;
  }
  if (Mensaje.indexOf("GET /fueraPc") >= 0)
  {
    Estado = false;
    Estado2 = false;
    Estado3 = false;
  }
  // encender y apagar foco
  if (Mensaje.indexOf("GET /lampara") >= 0)
  {
    if (digitalRead(rele) == 1)
    {
      digitalWrite(rele, LOW);
    }
    else
    {
      digitalWrite(rele, HIGH);
    }
  }
  if (Mensaje.indexOf("GET /lamparaOFF") >= 0)
  {
    digitalWrite(rele, LOW);
    Serial.println(digitalRead(rele));
  }
  if (Mensaje.indexOf("GET /cambiar") >= 0)
  {
    if (Mensaje.indexOf("GET /cambiar2") >= 0)
    {
      if (Estado2 == true)
      {
        Estado2 = false;
      }
      else
      {
        Estado2 = true;
      }
    }
    else
    {
      if (Estado == true)
      {
        Estado = false;
      }
      else
      {
        Estado = true;
      }
    }
  }
  else if (Mensaje.indexOf("GET /efecto:") >= 0)
  {
    if (Mensaje.indexOf("GET /efecto:siguiente") >= 0)
    {
      if (efecto != 3)
      {
        efecto++;
      }
      else
      {
        efecto = 0;
      }
      // tira 2(escritorio)
      if (efecto2 != 3)
      {
        efecto2++;
      }
      else
      {
        efecto2 = 0;
      }
      // tira 3(repisa)
      if (efecto3 != 3)
      {
        efecto3++;
      }
      else
      {
        efecto3 = 0;
      }
    }
    if (Mensaje.indexOf("GET /efecto:estatico") >= 0)
    {
      if (Mensaje.indexOf("GET /efecto:estatico2") >= 0)
      {
        efecto2 = 0;
      }
      else
      {
        efecto = 0;
      }
    }
    if (Mensaje.indexOf("GET /efecto:musica") >= 0)
    {
      if (Mensaje.indexOf("GET /efecto:musica2") >= 0)
      {
        efecto2 = 1;
      }
      else
      {
        efecto = 1;
      }
    }
    if (Mensaje.indexOf("GET /efecto:llenarTira") >= 0)
    {
      if (Mensaje.indexOf("GET /efecto:llenarTira2") >= 0)
      {
        efecto2 = 2;
      }
      else
      {
        efecto = 2;
      }
    }
    if (Mensaje.indexOf("GET /efecto:respiracion") >= 0)
    {
      if (Mensaje.indexOf("GET /efecto:respiracion2") >= 0)
      {
        efecto2 = 3;
      }
      else
      {
        efecto = 3;
      }
    }
  }
  else if (Mensaje.indexOf("GET /color:") >= 0)
  {                                           // cambiar color
    mensaje = Mensaje.indexOf("GET /color:"); // 11 para empezar con los colores
    int contador = 0;
    String temp = "";
    while (Mensaje[(mensaje + 11 + contador)] != ',')
    {
      temp += Mensaje[(mensaje + 11 + contador)];
      contador++;
    }
    rojo = temp.toInt();
    temp = "";
    contador++;
    Serial.println(rojo);
    while (Mensaje[(mensaje + 11 + contador)] != ',')
    {
      temp += Mensaje[(mensaje + 11 + contador)];
      contador++;
    }
    verde = temp.toInt();
    temp = "";
    contador++;
    Serial.println(verde);
    while (Mensaje[(mensaje + 11 + contador)] != ',')
    {
      temp += Mensaje[(mensaje + 11 + contador)];
      contador++;
    }
    azul = temp.toInt();
    temp = "";
    contador++;
    Serial.println(azul);
  }
  else
  {
    if (Mensaje.indexOf("GET /colo2:") >= 0)
    {                                           // cambiar color
      mensaje = Mensaje.indexOf("GET /colo2:"); // 11 para empezar con los colores
      int contador = 0;
      String temp = "";
      while (Mensaje[(mensaje + 11 + contador)] != ',')
      {
        temp += Mensaje[(mensaje + 11 + contador)];
        contador++;
      }
      rojo2 = temp.toInt();
      temp = "";
      contador++;
      Serial.println(rojo);
      while (Mensaje[(mensaje + 11 + contador)] != ',')
      {
        temp += Mensaje[(mensaje + 11 + contador)];
        contador++;
      }
      verde2 = temp.toInt();
      temp = "";
      contador++;
      Serial.println(verde);
      while (Mensaje[(mensaje + 11 + contador)] != ',')
      {
        temp += Mensaje[(mensaje + 11 + contador)];
        contador++;
      }
      azul2 = temp.toInt();
      temp = "";
      contador++;
      Serial.println(azul);
    }
  }
}

void ResponderCliente(WiFiClient &cliente)
{
  cliente.print(Pagina1);
  if (digitalRead(rele) == LOW)
  {
    cliente.print("APAGAR");
  }
  else
  {
    cliente.print("ENCENDER");
  }
  cliente.print(Pagina2);
  if (Estado == true)
  {
    cliente.print("APAGAR");
  }
  else
  {
    cliente.print("ENCENDER");
  }
  cliente.print(Pagina3);
  if (Estado2 == true)
  {
    cliente.print("APAGAR");
  }
  else
  {
    cliente.print("ENCENDER");
  }
  cliente.print(Pagina4);
}
