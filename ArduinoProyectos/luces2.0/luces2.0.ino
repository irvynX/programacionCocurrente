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
                <a href='/lampara' class=')====";

const String Pagina2 = R"====(</a>
          </div>
        <div class="gabinete col-sm-6">
            <div class='d-flex justify-content-around m-1'>
                <h1>PC</h1>
            </div>
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/cambiar' class=')====";
const String Pagina3 = R"====(</a>
            </div>

            <div class='d-flex justify-content-around m-1'>
                <h1>EFECTOS</h1>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:estatico' class='btn btn-outline-primary'>ESTATICO</a>
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
                <h1>ESCRITORIO</h1>
            </div>
            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/cambiar2' class=')====";
const String Pagina4 = R"====(</a>
            </div>

            <div class='d-flex justify-content-around m-1'>
                <h1>EFECTOS</h1>
            </div>
            <div class='d-flex justify-content-around m-1'>
                <a href='/efecto:estatico' class='btn btn-outline-primary'>ESTATICO</a>
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
                <div id='color2'>
                    <input type='color' value="#FF0000">
                </div>
            </div>

            <div class='d-flex justify-content-around m-1 mb-5'>
                <a href='/colo2:255,0,0,'  id='enviar2' class='btn btn-outline-primary'>ENVIAR</a>
            </div>
        </div>
    </div>
)====";
const String Pagina5 = R"====(



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

const uint32_t TiempoEsperaWifi = 5000;

unsigned long TiempoActual = 0;
unsigned long TiempoAnterior = 0;
const long TiempoCancelacion = 500;

WiFiServer servidor(80);

// globales
//  num de leds
int numLeds = 30;
int numLedsReloj = 70;
int dividir = 3;
int restar = 2500;
// pines de los componentes
int gabinete = 23;
int rele = 22;
int escritorio = 21;
int reloj = 19;
int microfono = 34;
// gabinete
int estadoG = 3;
int rojoG = 255;
int verdeG = 0;
int azulG = 0;
// escritorio
int estadoE = 0;
int rojoE = 255;
int verdeE = 0;
int azulE = 0;
// reloj
int estadoR = 0;
int rojoR = 255;
int verdeR = 0;
int azulR = 0;
// foco
int estadoF = 0;
// color aleatorio
int estadoA = 0;
int rojoA = 255;
int verdeA = 0;
// efecto musica
int temp = 0;
int ultimo[] = {0, 0, 0, 0, 0, 0, 0};
int ledMusica[] = {0, 0, 0, 0, 0, 0, 0};
int tiempoActualMusica = 0;
int tiempoPrevioMusica = 0;
int intervaloMusica = 50;
int intervaloMusica2 = 500;
// efecto llenar tira
int tiempoActualLlenar = 0;
int tiempoPrevioLlenar = 0;
int intervaloLlenar = 25;
int ledLlenar = 0;
// efecto respirar
int tiempoActualRes = 0;
int tiempoPrevioRes = 0;
int intervaloRes = 10;
int brillo = 0;
bool respirar = true;
// reloj
int tiempoPrevioR = 0;
int tiempoActualR = 0;
int intervaloR = 15000;
int ledFila = 14;
int notireloj = 0;
int icono1 = -3;
int icono2 = 14;
int brilloR = 255;

// pratiras led
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

// gabinete
Adafruit_NeoPixel pixelsGabinete(numLeds, gabinete, NEO_GRB + NEO_KHZ800);
// escritorio
Adafruit_NeoPixel pixelsEscritorio(numLeds, escritorio, NEO_GRB + NEO_KHZ800);
// reloj
Adafruit_NeoPixel pixelsReloj(numLedsReloj, reloj, NEO_GRB + NEO_KHZ800);

void setup()
{
  // wifi
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

  // preparar salidas y entradas
  pinMode(microfono, INPUT);
  pinMode(rele, OUTPUT);

  pixelsReloj.begin();
  Serial.println("reloj preparado");

  pixelsGabinete.begin();
  Serial.println("tiras led gabinete preparadas");

  pixelsEscritorio.begin();
  Serial.println("tiras led escritorio preparadas");
}

void loop()
{
#if defined(ESP8266)
  MDNS.update();
#endif
  WiFiClient cliente = servidor.available();
  // usuario en la pagina web
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
  // tira led gabinete
  if (estadoG == 0)
  {
    pixelsGabinete.clear();
    pixelsGabinete.show();
  }
  else if (estadoG == 1)
  {
    pixelsGabinete.fill(pixelsGabinete.Color(rojoG, verdeG, azulG), 0, numLeds);
    pixelsGabinete.show();
  }
  else if (estadoG == 2)
  {
    // metodo de musica
    efectoMusica();
  }
  else if (estadoG == 3)
  {
    // metodo llenar tira leds
    llenarTira();
  }
  else if (estadoG == 4)
  {
    // encender y apagar
    repirar();
  }
  else
  {
    estadoG == 1;
  }

  // tira led Escritorio
  if (estadoE == 0)
  {
    pixelsEscritorio.clear();
    pixelsEscritorio.show();
  }
  else if (estadoE == 1)
  {
    pixelsEscritorio.fill(pixelsEscritorio.Color(rojoE, verdeE, azulE), 0, numLeds);
    pixelsEscritorio.show();
  }
  else if (estadoE == 2)
  {
    // metodo de musica
    efectoMusica();
  }
  else if (estadoE == 3)
  {
    // metodo llenar tira leds
    llenarTira();
  }
  else if (estadoE == 4)
  {
    // encender y apagar
    repirar();
  }
  else
  {
    estadoE == 1;
  }

  // reloj
  if (estadoR == 0)
  {
    // metodo del reloj
    reloj();
  }
  else
  {
    // metodo de musica en el reloj
    efectoMusica();
  }

  // foco
  if (estadoF == 1)
  {
    digitalWrite(rele, LOW);
  }
  else
  {
    digitalWrite(rele, HIGH);
  }
}

// metodos
void efectoMusica()
{
  if (temp < map(analogRead(34), 0, 4096, 0, 30))
  {
    temp = map(analogRead(34), 0, 4096, 0, 30);
  }
  tiempoActualMusica = millis();
  if (tiempoActualMusica - tiempoPrevioMusica >= intervaloMusica)
  {
    // recorremos las posiciones
    for (int i = 0; i < 6; i++)
    {
      ledMusica[i + 1] = ledMusica[i];
      ultimo[i + 1] = ultimo[i];
    }
    // posicion del ultimo
    if (ultimo[0] < temp)
    {
      ultimo[0] = temp;
      intervaloMusica2 = intervaloMusica * 3;
    }

    // leemos el valor del microfono
    ledMusica[0] = temp;
    Serial.print("valor: ");
    Serial.println(ledMusica[0]);
    Serial.print("ultimo: ");
    Serial.println(ultimo[0]);
    if (ledMusica[0] > numLeds)
    {
      ledMusica[0] = numLeds;
    }
    if (ledMusica[0] < 0)
    {
      ledMusica[0] = 0;
    }

    // encender leds
    if (estadoG == 2)
    {
      pixelsGabinete.fill(pixelsGabinete.Color(rojoG, verdeG, azulG), 0, ledMusica[0]);
      pixelsGabinete.setPixelColor(ultimo[0], rojoG, verdeG, azulG);
      pixelsGabinete.show();
    }
    if (estadoE == 2)
    {
      pixelsEscritorio.fill(pixelsEscritorio.Color(rojoE, verdeE, azulE), numLeds / 2, (numLeds / 2) + (ledMusica[0] / 2));
      pixelsEscritorio.setPixelColor((numLeds / 2) + (ultimo[0] / 2), rojoE, verdeE, azulE);
      pixelsEscritorio.fill(pixelsEscritorio.Color(rojoE, verdeE, azulE), (numLeds / 2) - (ledMusica[0] / 2), numLeds / 2);
      pixelsEscritorio.setPixelColor((numLeds / 2) - (ultimo[0] / 2), rojoE, verdeE, azulE);
      pixelsEscritorio.show();
    }
    if (estadoR != 0)
    {
      musicaReloj();
    }
    // el valor ultimo lo bajamos
    if (tiempoActualMusica - tiempoPrevioMusica >= intervaloMusica2)
    {
      ultimo[0]--;
      if (ultimo[0] < 0)
      {
        ultimo[0] = 0;
      }
      intervaloMusica2 = intervaloMusica;
    }
    // reiniciamos variables
    tiempoPrevioMusica = millis();
    temp = 0;
  }
}

void musicaReloj()
{
  int t = ledMusica[0] / 5;
  int ul = ultimo[0] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((76 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((77 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((76 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((77 - (ul * 14)), rojoR, verdeR, azulR);

  t = ledMusica[1] / 5;
  ul = ultimo[1] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((75 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((78 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((75 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((78 - (ul * 14)), rojoR, verdeR, azulR);

  t = ledMusica[2] / 5;
  ul = ultimo[2] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((74 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((79 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((74 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((79 - (ul * 14)), rojoR, verdeR, azulR);

  t = ledMusica[3] / 5;
  ul = ultimo[3] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((73 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((80 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((73 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((80 - (ul * 14)), rojoR, verdeR, azulR);

  t = ledMusica[4] / 5;
  ul = ultimo[4] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((72 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((81 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((72 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((81 - (ul * 14)), rojoR, verdeR, azulR);

  t = ledMusica[5] / 5;
  ul = ultimo[5] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((71 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((82 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((71 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((82 - (ul * 14)), rojoR, verdeR, azulR);

  t = ledMusica[6] / 5;
  ul = ultimo[6] / 5;
  for (int i = 0; i < t; i++)
  {
    pixelsReloj.setPixelColor((70 - (i * 14)), rojoR, verdeR, azulR);
    pixelsReloj.setPixelColor((83 - (i * 14)), rojoR, verdeR, azulR);
  }
  pixelsReloj.setPixelColor((70 - (ul * 14)), rojoR, verdeR, azulR);
  pixelsReloj.setPixelColor((83 - (ul * 14)), rojoR, verdeR, azulR);

  pixelsReloj.show();
}

void llenarTira()
{
  tiempoActualLlenar = millis();
  if (tiempoActualLlenar - tiempoPrevioLlenar >= intervaloLlenar)
  {
    if (estadoG == 3)
    {
      pixelsGabinete.setPixelColor(ledLlenar - 1, 0, 0, 0);
      pixelsGabinete.setPixelColor(ledLlenar, rojoG, verdeG, azulG);
      pixelsGabinete.show();
    }
    if (estadoE == 3)
    {
      pixelsEscritorio.setPixelColor(ledLlenar - 1, 0, 0, 0);
      pixelsEscritorio.setPixelColor(ledLlenar, rojoE, verdeE, azulE);
      pixelsEscritorio.show();
    }
    ledLlenar++;
    if (ledLlenar > numLeds)
    {
      ledLlenar = 0;
    }
    Serial.print("lugar del led: ");
    Serial.println(ledLlenar);

    // reiniciamos variables
    tiempoPrevioLlenar = millis();
  }
}

void repirar()
{
  if (tiempoActualRes - tiempoPrevioRes >= intervaloRes)
  {
    if (estadoG == 4)
    {
      pixelsGabinete.setBrightness(brillo);
      pixelsGabinete.show();
    }
    if (estadoE == 4)
    {
      pixelsEscritorio.setBrightness(brillo);
      pixelsEscritorio.show();
    }
    if (respirar == true)
    {
      brillo++;
      if (brillo > 255)
      {
        respirar = false;
      }
    }
    else
    {
      brillo--;
      if (brillo < 1)
      {
        respirar = true;
      }
    }
  }
}

void VerificarMensaje(String mensaje)
{
  if (Mensaje.indexOf("GET /") >= 0)
    {
        digitalWrite(rele, LOW);
        Estado = true;
        Estado2 = true;
        Estado3 = true;
    }
}

void ResponderCliente(WiFiClient &cliente)
{
  cliente.print(Pagina1);
  cliente.print("btn btn-primary'>APAGAR");
  cliente.print(Pagina2);
  cliente.print("btn btn-primary'>APAGAR");
  cliente.print(Pagina3);
  cliente.print("btn btn-primary'>APAGAR");
  cliente.print(Pagina4);
  cliente.print("<!-- position led:");
  cliente.print(" -->");
  cliente.print(Pagina5);
}

// metodos del reloj

void reloj()
{
  // metodo reloj inicio

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
      pixelsReloj.show();
    }
  }

  http.end();
  // fin del metodo
}

void cero(int section)
{
  pixelsR.setPixelColor(0 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), 0, 0, 0);
}

void uno(int section)
{
  pixelsR.setPixelColor(0 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), 0, 0, 0);
}

void dos(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void tres(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void cuatro(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void cinco(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void seis(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), 0, 0, 0);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void siete(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void ocho(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void nueve(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + ledFila * 2 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + ledFila * 2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 3 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 3 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(0 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + ledFila * 4 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + ledFila * 4 + (section), rojoR, verdeR, azulR);
}

void Youtube(int section)
{
  if (1 + ledFila + (section) >= ledFila && 1 + ledFila + (section) < ledFila * 2)
  {
    pixelsR.setPixelColor(1 + ledFila + (section), 255, 255, 255);
  }

  if (1 + ledFila * 2 + (section) >= ledFila * 2 && 1 + ledFila * 2 + (section) < ledFila * 3)
  {
    pixelsR.setPixelColor(1 + ledFila * 2 + (section), 255, 255, 255);
  }
  if (1 + ledFila * 2 + (section) >= ledFila * 2 && 1 + ledFila * 2 + (section) < ledFila * 3)
  {
    pixelsR.setPixelColor(2 + ledFila * 2 + (section), 255, 255, 255);
  }

  if (1 + ledFila * 3 + (section) >= ledFila * 3 && 1 + ledFila * 3 + (section) < ledFila * 4)
  {
    pixelsR.setPixelColor(1 + ledFila * 3 + (section), 255, 255, 255);
  }
}

void Whatsapp(int section)
{
  if (1 + (section) >= 0 && 1 + (section) < ledFila)
  {
    pixelsR.setPixelColor(1 + (section), 255, 255, 255);
  }

  if (1 + ledFila + (section) >= ledFila && 1 + ledFila + (section) < ledFila * 2)
  {
    pixelsR.setPixelColor(1 + ledFila + (section), 255, 255, 255);
  }

  if (1 + ledFila * 2 + (section) >= ledFila * 2 && 1 + ledFila * 2 + (section) < ledFila * 3)
  {
    pixelsR.setPixelColor(1 + ledFila * 2 + (section), 255, 255, 255);
  }

  if (1 + ledFila * 4 + (section) >= ledFila * 4 && 1 + ledFila * 4 + (section) < ledFila * 5)
  {
    pixelsR.setPixelColor(1 + ledFila * 4 + (section), 255, 255, 255);
  }
}

void Facebook(int section)
{
  if (1 + (section) >= 0 && 1 + (section) < ledFila)
  {
    pixelsR.setPixelColor(1 + (section), 255, 255, 255);
  }
  if (1 + (section) >= 0 && 1 + (section) < ledFila)
  {
    pixelsR.setPixelColor(2 + (section), 255, 255, 255);
  }

  if (1 + ledFila + (section) >= ledFila && 1 + ledFila + (section) < ledFila * 2)
  {
    pixelsR.setPixelColor(1 + ledFila + (section), 255, 255, 255);
  }

  if (0 + ledFila * 2 + (section) >= ledFila * 2 && 0 + ledFila * 2 + (section) < ledFila * 3)
  {
    pixelsR.setPixelColor(0 + ledFila * 2 + (section), 255, 255, 255);
  }
  if (0 + ledFila * 2 + (section) >= ledFila * 2 && 0 + ledFila * 2 + (section) < ledFila * 3)
  {
    pixelsR.setPixelColor(1 + ledFila * 2 + (section), 255, 255, 255);
  }
  if (0 + ledFila * 2 + (section) >= ledFila * 2 && 0 + ledFila * 2 + (section) < ledFila * 3)
  {
    pixelsR.setPixelColor(2 + ledFila * 2 + (section), 255, 255, 255);
  }

  if (1 + ledFila * 3 + (section) >= ledFila * 3 && 1 + ledFila * 3 + (section) < ledFila * 4)
  {
    pixelsR.setPixelColor(1 + ledFila * 3 + (section), 255, 255, 255);
  }

  if (1 + ledFila * 4 + (section) >= ledFila * 4 && 1 + ledFila * 4 + (section) < ledFila * 5)
  {
    pixelsR.setPixelColor(1 + ledFila * 4 + (section), 255, 255, 255);
  }
}

void pintarPantalla(int R, int G, int B)
{
  pixelsR.fill(pixels.Color(R, G, B), 0, 70);
  pixelsR.show();
}
