/**
 * BasicHTTPClient.ino
 *
 *  Created on: 24.05.2015
 *
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

#define USE_SERIAL Serial

WiFiMulti wifiMulti;

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 23 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 60 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixelsR(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
/*
const char* ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/\n" \
"MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n" \
"DkRTVCBSb290IENBIFgzMB4XDTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0Nlow\n" \
"SjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxIzAhBgNVBAMT\n" \
"GkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkqhkiG9w0BAQEFAAOC\n" \
"AQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4S0EF\n" \
"q6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8\n" \
"SMx+yk13EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0\n" \
"Z8h/pZq4UmEUEz9l6YKHy9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWA\n" \
"a6xK8xuQSXgvopZPKiAlKQTGdMDQMc2PMTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj\n" \
"/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQABo4IBfTCCAXkwEgYDVR0T\n" \
"AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEEczBxMDIG\n" \
"CCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNv\n" \
"bTA7BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9k\n" \
"c3Ryb290Y2F4My5wN2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAw\n" \
"VAYDVR0gBE0wSzAIBgZngQwBAgEwPwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcC\n" \
"ARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNyeXB0Lm9yZzA8BgNVHR8ENTAz\n" \
"MDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9PVENBWDNDUkwu\n" \
"Y3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n" \
"AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJo\n" \
"uM2VcGfl96S8TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/\n" \
"wApIvJSwtmVi4MFU5aMqrSDE6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwu\n" \
"X4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPMTZ+sOPAveyxindmjkW8lGy+QsRlG\n" \
"PfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M+X+Q7UNKEkROb3N6\n" \
"KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n" \
"-----END CERTIFICATE-----\n";
*/
int rojoR = 255;
int verdeR = 0;
int azulR = 0;

void setup()
{

  USE_SERIAL.begin(115200);

  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  pixelsR.setBrightness(2);
  for (int i = 0; i < 30; i++)
  {
    pixelsR.setPixelColor(i, 255, 255, 255);
    pixelsR.setPixelColor(59 - i, 255, 255, 255);
    pixelsR.show();
    delay(50);
  }
  delay(1000);
  pixelsR.clear();

  wifiMulti.addAP("Totalplay-2DA1-2", "irvyn2703");
}

void loop()
{
  // wait for WiFi connection
  if ((wifiMulti.run() == WL_CONNECTED))
  {

    // metodo reloj inicio
    pixelsR.setPixelColor(19, 157, 176, 157);
    pixelsR.setPixelColor(20, 157, 176, 157);
    pixelsR.setPixelColor(43, 157, 176, 157);
    pixelsR.setPixelColor(44, 157, 176, 157);

    HTTPClient http;

    // USE_SERIAL.print("[HTTP] begin...\n");
    //  configure traged server and url
    // http.begin("http://worldtimeapi.org/api/timezone/America/Mexico_City", ca); //HTTPS
    http.begin("http://worldtimeapi.org/api/timezone/America/Mexico_City"); // HTTP

    // USE_SERIAL.print("[HTTP] GET...\n");
    //  start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0)
    {
      // HTTP header has been send and Server response header has been handled
      // USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK)
      {
        String payload = http.getString();
        // USE_SERIAL.println(payload);
        int mensaje = payload.indexOf("datetime"); // 11 para empezar con los colores
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

        // USE_SERIAL.println(h);
        // USE_SERIAL.println(m1);

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
          cero(9);
        }
        else if (m1 == 1)
        {
          uno(9);
        }
        else if (m1 == 2)
        {
          dos(9);
        }
        else if (m1 == 3)
        {
          tres(9);
        }
        else if (m1 == 4)
        {
          cuatro(9);
        }
        else if (m1 == 5)
        {
          cinco(9);
        }
        else if (m1 == 6)
        {
          seis(9);
        }
        else if (m1 == 7)
        {
          siete(9);
        }
        else if (m1 == 8)
        {
          ocho(9);
        }
        else
        {
          nueve(9);
        }

        pixelsR.show();
      }
    }
    else
    {
      USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
    // fin del metodo
  }

  delay(10000);
}

void cero(int section)
{
  pixelsR.setPixelColor(0 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(12 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), 0, 0, 0);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), 0, 0, 0);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), 0, 0, 0);
}

void uno(int section)
{
  pixelsR.setPixelColor(0 + (section), 0, 0, 0);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(12 + (section), 0, 0, 0);
  pixelsR.setPixelColor(13 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(14 + (section), 0, 0, 0);

  pixelsR.setPixelColor(24 + (section), 0, 0, 0);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), 0, 0, 0);

  pixelsR.setPixelColor(36 + (section), 0, 0, 0);
  pixelsR.setPixelColor(37 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(38 + (section), 0, 0, 0);

  pixelsR.setPixelColor(48 + (section), 0, 0, 0);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), 0, 0, 0);
}

void dos(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), 0, 0, 0);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), 0, 0, 0);

  pixelsR.setPixelColor(48 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void tres(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), 0, 0, 0);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), 0, 0, 0);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void cuatro(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), 0, 0, 0);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), 0, 0, 0);
  pixelsR.setPixelColor(49 + (section), 0, 0, 0);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void cinco(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), 0, 0, 0);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), 0, 0, 0);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void seis(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), 0, 0, 0);
  pixelsR.setPixelColor(2 + (section), 0, 0, 0);

  pixelsR.setPixelColor(12 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), 0, 0, 0);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void siete(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), 0, 0, 0);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), 0, 0, 0);
  pixelsR.setPixelColor(25 + (section), 0, 0, 0);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), 0, 0, 0);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), 0, 0, 0);
  pixelsR.setPixelColor(49 + (section), 0, 0, 0);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void ocho(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(49 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}

void nueve(int section)
{
  pixelsR.setPixelColor(0 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(1 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(2 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(12 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(13 + (section), 0, 0, 0);
  pixelsR.setPixelColor(14 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(24 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(25 + (section), rojoR, verdeR, azulR);
  pixelsR.setPixelColor(26 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(36 + (section), 0, 0, 0);
  pixelsR.setPixelColor(37 + (section), 0, 0, 0);
  pixelsR.setPixelColor(38 + (section), rojoR, verdeR, azulR);

  pixelsR.setPixelColor(48 + (section), 0, 0, 0);
  pixelsR.setPixelColor(49 + (section), 0, 0, 0);
  pixelsR.setPixelColor(50 + (section), rojoR, verdeR, azulR);
}
