/*
**********************************************************************
  Medidor estéreo VU para 1 o 2 anillos, Matríz o tiras LED WS2812, con test de leds al encenderlo.
  Configurado para ser usado con cualquier salida de amplificación de audio. 
  (salida de auriculares cambiando las resistencias de 100k por unas de 100 ohm) o directo a un amplificador con sus respectivas resistencias.
  Con control de sensibilidad y brillo, y 2 pulsadores para cambiar los modos de visualización.
  Cambio de color de los LEDs del Vúmetro con un pulsador. y un pulsador extra para la retención de visualización de picos de audio.
  Puede usar la salida de la pc o reproductor de audio (audifonos) o directo de un amplificador para hacer funcionar el Vúmetro.
  Respuesta lineal y logarítmica de las lecturas de audio. configurable en el código.
  Editado y compilado por Isidro Louie Hernández López:
  Diseñado para ser utilizado con un Arduino Mega, UNO, Nano Micro, Leonardo o dispositivo compatible.
**********************************************************************
  Aviso: busque @EB en el sketch para establecer variables importantes
  para que el Sketch funcione con su configuración personalizada.
  Eliminar comentario es igual a eliminar las diagonales del codigo para definir la programación (//) (activar función)
**********************************************************************
  Actualizado 14/6/2019  Córdoba, Veracruz, México.

  Este código lo puede configurar a su gusto personal, algunas opciones ya estan predefinidas en el programa.
  Por favor, deje este encabezado intacto.

  contacto: www.facebook.com/ChiquilloSubnormal19
            chikion_medas96@hotmail.com
  Código Modificado Y Varias Lineas De Código Propio Agregadas. Archivo Tomado De La Librería, Arduino/Ejemplos/AdafruitCircuitPlayground/vu-meter
  
**********************************************************************
*/

//La idea!!!!!!
//Después de haber visto algunos medidores VU antiguos analógos de led pensé que sería genial tener uno también, pero hacerlo yo!.
//Fue cuando armé mi primer prototipo con un integrado LM3914N ya hace algunos años, después miré algunos Vumetros con arduino y decidí armar el mío.
//Entonces armé mis primeros prototipos bastante sencillos con un arduino que me habían prestado.
//Así que compré un ARDUINO UNO y unos módulos LED WS2812 de Adafruit algunas cosas más y comencé a construirlo.
//Empecé con un script Arduino muy simple que viene en una librería de adafruit que usaba un microfóno, un canal y encendía una tira de LED.
//Luego de varios intentos modifiqué y agregué varias características al script:
//Ahora soporta canales estéreo, control de brillo de los LEDs, sensibilidad de la señal de audio y algunos efectos interesantes.
//Función de retención de punto led conmutable con opción de 'velocidad de caída'
//Sensibilidad a la respuesta de audio ajustable con un potenciómetro de 20K
//Ajuste del brillo de los LED ajustable con un potenciómetro de 20K
//Soporte para 1 tira o 2 de LED que muestra el canal izquierdo y derecho, matríz o 2 anillos de LED que muestran un canal cada uno:
//Caída lenta o rápida de los LED y punto flotante, cambio de colores, modos de visualización y un pequeño escaneo de encendido de los LED al encender arduino.
//variables que se pueden configurar para admitir cualquier cantidad de LED y personalizar aún más el medidor VU a su gusto.
//Actualmente estoy usando un Arduino/Genuino Micro. De Arduino y Adafruit.
//Necesita la biblioteca Adafruit_NeoPixel para que la secuencia de comandos funcione. (Incluido en el Rar)

//Última actualización 14/6/2019  Córdoba, Veracruz, México.
//Con Licencia de   .Creative Commons 2019 (CC BY-NC-SA).

//Al ejecutar este archivo, usted se muestra de acuerdo con esta licencia
//Archivo(gratuito de uso limitado)
//En primer lugar, las razones de por qué este archivo es gratuito:
//Usted puede distribuir, modificar, compartir este archivo siempre y cuando no cambie el nombre del autor.
//Está estrictamente prohibido usar este archivo con fines de lucro, este archivo esta registrado con copyright, pero podra usarlo para fines personales sin uso de venta del mismo:
//cualquier uso con fines de lucro de este archivo esta penado por la ley de derechos de autor:
//Distribución.
//Éstas son algunas reglas básicas acerca de la distribución de este archivo.
//Distribución privada.
//Puede dar copias individuales de este archivo en tanto que no modifique esta licencia o nombre de autor.
//Colocación en web.
//Si quiere colocar una réplica de este archivo en su web, puede hacerlo en tanto que no modifique esta licencia o nombre de autor

//Gracias y buena suerte les deseamos I Louie & LuDi.



#include <Adafruit_NeoPixel.h>

//
// configuración de depuración
//
//#define DEBUG                                               // depuración: habilitar serial.print 
#define DEBUG_NO_PEAK_SWITCH                              // depuración: si no hay interruptor de muestreo picos conectado (3er pulsador opcional) @EB
//#define DEBUG_TEST_LEDS                                   // depuración: muestra cada led encendido (color) lentamente al inicio
//#define DEBUG_PRINT_LOOP_TIME                            // depuración: serial.print (bucle en ms)
//#define DEBUG_PRINT_ANALOGVALUES                        // depuración: valores de entrada analógica serial.print
//#define DEBUG_NO_PEAKS                                 // depuración: no muestrar picos máximos en lectura de los LEDs, ignorando otras configuraciones
#define DEBUG_PEAKS                                   // depurar: muestra picos de saturación de audio (Clip), ignorando otras configuraciones
//
// elimina el promedio de los niveles de entrada al número definido por averageNumOfReadings. aumentar el valor hará que el Vúmetro sea menos sensible a niveles altos de audio
//
//#define averageReadings                                     // niveles de entrada promedio
//#define averageNumOfReadings 3                              // número de lecturas
//
// elimina las diagonales (//)para mapear la entrada de audio lineal a la respuesta no lineal (logarítmica)
//
//#define nonLinearSinAudio                   // elimina la diagonal para mapear la señal de entrada de audio lineal a una respuesta de reducción de audio inversa no lineal
//#define nonLinearReverseSinAudio            // elimina la diagonal para mapear la señal de entrada de audio lineal a una respuesta no lineal, audio-cónica (onda sinusoidal inversa)
//#define nonLinearLogAudio                   // elimina la diagonal para asignar la señal de entrada de audio lineal a una respuesta de registro
#define nonLinearAvr2                         // elimina la diagonal para promediar la entrada original con la respuesta no lineal (La que uso actualmente)

//
// configuración de saturación de audio
//
#define displayOverflow                                     // Mostrar Picos (clipping) o no
//#define compressOverflowPeaks                             // Compresión de los picos (clipping)  o no
//#define compressOverflowNumOfTimes 2                      // Numero de veces para aplicar la compresión de desbordamiento
//float compressOverflowFactor = .05;                       // Factor de compresión

//
// elimina la diagonal cuando se usan entradas de alto nivel (salida de audio elevada)
//
#define highLevelInput                                      // @EB definir para entradas de audio de alto nivel
//
// elimina la diagonal para configurar el tipo de tiras o anillo(s) conectado(s) segun los que haya conectado @EB
//

#define led_strip_matrix_64                              //Doble tira de LEDs de 64 LEDs cada una (actualmente usado conectadas)
//#define led_ring_16
//#define led_ring_60_ps
//#define led_rhombus_64_ps
//#define led_strip_60
//#define led_strip_16_qr
//#define led_strip_30
//#define led_2_rings_64
//#define led_2_rings_30
//#define led_strip_64
//#define led_strip_144
//#define led_2_strip_63
//#define led_2_strip_64_qr

//

const int useSensorValues = true;                         // @EB

//
// Configuración de pines en tarjeta madre arduino
//

int leftPin = 27, rightPin = 27;                          // Entradas de audio analógico izquierda A0, derecha en A1
int brightnessPin = A4, sensitivityPin = A5;              // Potenciómetros para brillo y sensibilidad en  A4 y A5
int leftStripPin = 6;                                     // D-IN a la tira de led izquierda en el pin digital 6
int rightStripPin = 5;                                    // D-IN a la tira de led derecha en el pin digital 5
int showPeaksPin = 9;                                     // Activar o desactivar la visualización de los picos (clipping) en el pin digital 9 (tercer switch opcional)
int showPeaksMomentarySwitch = false;                     // Establecer en falso si no está conectado el 3er switch conectado./desconectado.
int reverseShowPeaks = false;                             // Invierta la configuración de encendido / apagado de leds en caso de que haya cometido un error de cableado ;-) @EB
int selectButton1Pin = 8;                                 // Botón para cambiar los colores de visualización en el pin digital 8
int useSelectButton1 = true;                              // Establecer en falso si no hay un botón pulsador 1 para seleccionar la visualización de colores  @EB
int selectButton2Pin = 10;                                // Botón para cambiar la configuración de visualización de varios modos del Vúmetro en el pin digital 10
int useSelectButton2 = true;                              // Establecer en falso si solo hay un botón pulsador conectado (boton 2 desconectado) @EB

//
// variables de configuración para el número de leds y tira/s led 
//

#if defined (led_strip_matrix_64)
//configuraciones para una tira o matríz de led

int stripNumOfLeds = 20;                                  // número total de leds(2 tiras 64. 1 tira 65)
int stripsOn2Pins = true;                                 // configurado en verdadero si las tiras LED o los anillos están conectados a los 2 pines de entrada (5 y 6)
uint32_t stripColor[65];                                  // la mitad de la cantidad total de leds + 1 (2 tiras 65. 1 tira 33)
int displayMiddleLed = false;                             // muestra el led central (azul). establecido en verdadero para una tira, falso para dos tiras o anillos
int splitStrip = true;                                    // establecido en verdadero cuando se usan 2 tiras o anillos, falso para una tira
int middleOffset = 0;                                     // desplazamiento para el led cuando se usa una tira
int startupAnimationDelay = 1.08;                         // tiempo de la animación de inicio (escaneo de leds al encender Arduino)
int orangeLimitAmount = 0;                                // limite la cantidad de verde de los LED medios para hacerlos más anaranjados
int swapLeftRight = true;                                // intercambia los valores de entrada izquierda y derecha o no

int dropDelay = 5;                                        // retardo del tiempo antes de soltar los leds hacia abajo
float dropFactor = .82;                                   // valor para dejar caer los leds (velocidad de respuesta a la música) *amortiguamiento*

int peakTimeNoDropDelay = 215;                           // tiempo pico de espera cuando no se caen los leds (cuando dropearPeak es falso)
int peakTimeFirstDropDelay = 74;                         // tiempo pico de espera cuando se cae el primer led
int peakTimeDropDelay = 9;                               // tiempo máximo de retención cuando se deja caer el resto de los led
float peakDropFactor = .98;                              // valor para dejar caer el led que muestra los picos
int droppingPeakFade = false;                            // Caída de led desvaneciéndose a negro o no

int bouncingPeaksNumOfLeds = 12;                          // cuántos leds rebotan (máximo)
int bouncingPeaksNumOfLedsMin = 3;                        // cuántos leds rebotan (min) al usar dynamicBouncingPeaks
int bouncingPeakDelay = 8;                                // demora entre las actualizaciones de rebote de los leds
int bouncingPeakCounterInc = 26;                          // aumentar el contador para cada actualización de rebote. nota: usa una función 0-180 para el rebote

//La definición de las siguientes lineas tienen las mismas funciones que (led_strip_matrix_64) con variables como cantidad de LEDs y demás parámetros

#elif defined (led_ring_16)
//configuraciones para un anillo de leds

int stripNumOfLeds = 16;
int stripsOn2Pins = true;
uint32_t stripColor[31];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 6;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 10;
float dropFactor = .94;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 70;
int peakTimeDropDelay = 7;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 6;
int bouncingPeaksNumOfLedsMin = 3;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 10;

#elif defined (led_ring_60_ps)
//ajustes para un anillo de 60 led - configuración de pulsación y giro

int stripNumOfLeds = 60;
int stripsOn2Pins = false;
uint32_t stripColor[31];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 18;
int orangeLimitAmount = 0;
int swapLeftRight = true;

int dropDelay = 5;
float dropFactor = .92;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 140;
int peakTimeDropDelay = 22;
float peakDropFactor = .98;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 4;
int bouncingPeaksNumOfLedsMin = 1;
int bouncingPeakDelay = 8;
int bouncingPeakCounterInc = 50;


#elif defined (led_rhombus_64_ps)
//ajustes para un rombo de 64 leds - configuración de pulsación y giro

int stripNumOfLeds = 64;
int stripsOn2Pins = true;
uint32_t stripColor[33];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 0;
int orangeLimitAmount = 5;
int swapLeftRight = false;

int dropDelay = 8;
float dropFactor = .92;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 110;
int peakTimeDropDelay = 17;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 10;
int bouncingPeaksNumOfLedsMin = 5;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 6;

#elif defined (led_strip_60)
//ajustes para una tira de 60 led

int stripNumOfLeds = 60;
int stripsOn2Pins = false;
uint32_t stripColor[21];
int displayMiddleLed = true;
int splitStrip = false;
int middleOffset = 1;
int startupAnimationDelay = 6;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 5;
float dropFactor = .94;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 70;
int peakTimeDropDelay = 7;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 6;
int bouncingPeaksNumOfLedsMin = 3;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 10;

#elif defined (led_strip_60_qr)
// configuraciones para una tira de 16 led - respuesta rápida

int stripNumOfLeds = 60;
int stripsOn2Pins = true;
uint32_t stripColor[31];
int displayMiddleLed = true;
int splitStrip = false;
int middleOffset = 1;
int startupAnimationDelay = 6;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = .3;
float dropFactor = .92;

int peakTimeNoDropDelay = 0;
int peakTimeFirstDropDelay = 0;
int peakTimeDropDelay = 0;
float peakDropFactor = 1;
int droppingPeakFade = true;

int bouncingPeaksNumOfLeds = 0;
int bouncingPeaksNumOfLedsMin = 0;
int bouncingPeakDelay = 0;
int bouncingPeakCounterInc = 180;

#elif defined (led_strip_30)
//ajustes para una tira de 30 led
int stripNumOfLeds = 30;
int stripsOn2Pins = false;
uint32_t stripColor[16];
int displayMiddleLed = true;
int splitStrip = false;
int middleOffset = 1;
int startupAnimationDelay = 10;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 10;
float dropFactor = .9;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 150;
int peakTimeDropDelay = 15;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 4;
int bouncingPeaksNumOfLedsMin = 2;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 9;

#elif defined (led_2_rings_64)
//ajustes para 2 anillos de 64 led

int stripNumOfLeds = 64;
int stripsOn2Pins = false;
uint32_t stripColor[33];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 5;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 2;
float dropFactor = .96;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 100;
int peakTimeDropDelay = 10;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 4;
int bouncingPeaksNumOfLedsMin = 2;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 9;

#elif defined(led_2_rings_30)
//ajustes para 2 anillos de 30 led

int stripNumOfLeds = 60;
int stripsOn2Pins = false;
uint32_t stripColor[31];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 5;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 2;
float dropFactor = .96;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 100;
int peakTimeDropDelay = 10;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 4;
int bouncingPeaksNumOfLedsMin = 2;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 9;

#elif defined (led_strip_64)
//ajustes para una tira de 64 led-

int stripNumOfLeds = 64;
int stripsOn2Pins = true;
uint32_t stripColor[33];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 1.04;
int orangeLimitAmount = 0;
int swapLeftRight = true;

int dropDelay = 5;
float dropFactor = .89;

int peakTimeNoDropDelay = 216;
int peakTimeFirstDropDelay = 74;
int peakTimeDropDelay = 9;
float peakDropFactor = .92;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 2;
int bouncingPeaksNumOfLedsMin = 1;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 6;

#elif defined (led_strip_144)
//ajustes para una tira de 144 led

int stripNumOfLeds = 144;
int stripsOn2Pins = false;
uint32_t stripColor[73];
int displayMiddleLed = true;
int splitStrip = false;
int middleOffset = 1;
int startupAnimationDelay = 1;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 4;
float dropFactor = .92;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 100;
int peakTimeDropDelay = 5;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 10;
int bouncingPeaksNumOfLedsMin = 4;
int bouncingPeakDelay = 2;
int bouncingPeakCounterInc = 10;

#elif defined (led_2_strip_63)
//ajustes para 2 tiras de 63 led

int stripNumOfLeds = 63;
int stripsOn2Pins = true;
uint32_t stripColor[64];
int displayMiddleLed = true;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 1;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 5;
float dropFactor = .94;

int peakTimeNoDropDelay = 250;
int peakTimeFirstDropDelay = 70;
int peakTimeDropDelay = 7;
float peakDropFactor = .94;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 12;
int bouncingPeaksNumOfLedsMin = 4;
int bouncingPeakDelay = 4;
int bouncingPeakCounterInc = 10;

#elif defined (led_2_strip_64_qr)
//ajustes para 2 tiras de 64 led - respuesta rápida
int stripNumOfLeds = 64;
int stripsOn2Pins = true;
uint32_t stripColor[33];
int displayMiddleLed = false;
int splitStrip = true;
int middleOffset = 0;
int startupAnimationDelay = 1.04;
int orangeLimitAmount = 0;
int swapLeftRight = false;

int dropDelay = 4;
float dropFactor = .89;

int peakTimeNoDropDelay = 200;
int peakTimeFirstDropDelay = 60;
int peakTimeDropDelay = 6;
float peakDropFactor = .92;
int droppingPeakFade = false;

int bouncingPeaksNumOfLeds = 12;
int bouncingPeaksNumOfLedsMin = 4;
int bouncingPeakDelay = 3;
int bouncingPeakCounterInc = 10;
#endif

//
// configuración de otras variables para los efectos varios función y colores
//

// ajustes básicos
int pulsing = false;                                      // el parpadeo de los led se mostrará desde el medio de cada tira o anillo al iniciar el Vumetro  @EB

int spinCircle = true;                                    // giro de la animación. LEDs conectados a los 2 pines 6 y 5  @EB

int animType = 11;                                        // selección de animación de inicio (11 "arcoiris2 aleatorio)  @EB
int colorScheme = 12;                                     // 0: verde-rojo, 1: azul-verde, 2: azul-rojo, 3: rojo-azul, 4: verde-azul, 5: rojo-verde, 6: azul-blanco-rojo
                                                          // 7: rojo-blanco-azul, 8: verde-blanco-rojo, 9: verde-blanco-azul, 10: arcoiris, 11: arcoiris cambiante giratorio,
                                                          // 12: como el 11, pero se extendió con el color del factor "Scheme12Factor"  @EB
int maxColorScheme = 12;                                  // utilizado para recorrer los esquemas de color con el botón de cambio
int colorScheme11SpinDelay = stripNumOfLeds / 1 ;         // retraso para el esquema de giro "11"
int colorScheme12Factor = 2.5;                            // velocidad de dispersión del arcoiris para el esquema 12 @EB

int minValue = 10;                                        // valor mínimo de entrada de audio analógico
int sensitivityValue = 110;                               // 0 - 255, valor inicial (valor leído del potenciómetro si usa Valores del sensor) = true)

#ifdef highLevelInput
int maxValue = 700;                                     // valor máximo de entrada de audio analógico (0-1023 es igual a 0-5V). 300 para entrada de bajo nivel, 700 para audio alto
int maxSensitivity = 2 * 255;                           // establecer a un ajuste más alto para amplificar niveles bajos de entrada.
                                                        // intente con 4 * 255 para una entrada de bajo nivel,  2 * 255 para un nivel alto
#else
int maxValue = 300;                                     // valor máximo de entrada de audio analógicp (0-1023 es igual a 0-5V). 300 para entrada de bajo nivel, 700 para audio alto
int maxSensitivity = 4 * 255;                           // establecer a un ajuste más alto para amplificar niveles bajos de entrada.
                                                        // intente con 4 * 255 para una entrada de bajo nivel, 2 * 255 para un alto
#endif

int ledBrightness = 55;                                   // 0 - 255, valor inicial (valor leído desde el potenciómetro si usa Valores del sensor) = true)
int sensorDeviationBrightness = 3;                        // elimina los valores fluctuantes
int overflowDelay = 10;                                   // tiempo de retención de picos máximos de audio
//
// ajustes de picos (clipping) @EB
//
int displayPeaks = false;                                // el valor se establecerá con el interruptor si usa valores de sensor = true
int displayTopAsPeak = true;                             // mostrar siempre el LED superior (DOT) en un color diferente (muestra de máximo nivel)
int droppingPeak = true;                                 // mostrar led (DOT) cayendo o no. nota: displayPeaks tiene que ser true
int bouncingPeaks = true;                                // mostrar los picos de rebote o no. nota: displayPeaks tiene que ser true
int dynamicBouncingPeaks = true;                         // menos rebotes con picos más bajos. nota: bouncingPeaks tiene que ser true

//
// inicio de otras variables
//

int numOfSegments, halfNumOfSegments, stripMiddle, maxDisplaySegments;
float sensitivityFactor;
float nonLinearResponseFactor;

int brightnessValue, prevBrightnessValue;
float ledFactor, ledFactor_div_numOfSegments;

uint32_t stripMiddleColor, stripOverflowColor, stripHoldColor;
uint32_t colorValue;

int leftValue = 0, rightValue = 0, maxReadValue = 0;
int leftValueN = 0, rightValueN = 0;
int leftAnalogValue = 0, rightAnalogValue = 0;
float log10MaxDisplaySegments;

int prevLeftValue = 0, prevRightValue = 0;
int prevLeftAnalogValue = 0, prevRightAnalogValue = 0;

int selectButton1PinState = 0, prevSelectButton1PinState = 0;
int selectButton2PinState = 0, prevSelectButton2PinState = 0;

int selectButton1PinSetting = colorScheme;
int selectButton2PinSetting = 0;

int i, j;
int dropLeft, dropRight;
int leftDropTime, rightDropTime;

int leftPeak = 0, rightPeak = 0;
int leftPeakTime = 0, rightPeakTime = 0;
int leftFirstPeak = true, rightFirstPeak = true;
int showPeaksPinSetting, prevShowPeaksPinSetting;

int stripPulseMiddle = 0;
int halfLeftValue, halfRightValue, halfPrevLeftValue, halfPrevRightValue;

int leftPeakBouncing = false, rightPeakBouncing = false;
int leftPeakBounce = 0, rightPeakBounce = 0;
int prevLeftPeakBounce = 0, prevRightPeakBounce = 0;
int leftPeakBounceCounter = 0, rightPeakBounceCounter = 0;
int leftPeakBounceDelayCounter = 0, rightPeakBounceDelayCounter = 0;
int leftBouncingPeaksNumOfLeds = 0, rightBouncingPeaksNumOfLeds = 0;
float bounceFactor;

int colorScheme11SpinValue = 0, colorScheme11SpinDelayValue = 0;
int colorSchemeFactor = 1;
long selectButton1Timer;

int spinDelayCounter = 0, spinCounter = 0, spinTurnsCounter = 0, spinTurnsMax = 0, spinTurnsDelay = 0, spinTurnsDelayMax = 0;
int spinCounterInc = 1;
int spinDelay = 0;
//
// iniciando LEDs NeoPixel
//

Adafruit_NeoPixel left_strip = Adafruit_NeoPixel(stripNumOfLeds, leftStripPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel right_strip = Adafruit_NeoPixel(stripNumOfLeds, rightStripPin, NEO_GRB + NEO_KHZ800);

//
// Inicio
//

void setup() {
#ifdef DEBUG
  Serial.begin(9600);
#endif

  randomSeed(analogRead(2));

  if (stripsOn2Pins) {
    numOfSegments = stripNumOfLeds;
    maxDisplaySegments = numOfSegments - 1;

    stripMiddle = stripNumOfLeds;
    stripPulseMiddle = stripMiddle / 2;
    spinCircle = false;
  }
  else {
    numOfSegments = stripNumOfLeds / 1;
    stripMiddle = stripNumOfLeds / 1;
    maxDisplaySegments = stripMiddle - 1;

    stripPulseMiddle = stripMiddle / 1;
  }

  halfNumOfSegments = numOfSegments / 1;
  bounceFactor = (float) bouncingPeaksNumOfLeds / (maxDisplaySegments - bouncingPeaksNumOfLeds);
  nonLinearResponseFactor = 90 / (float) maxDisplaySegments;
  log10MaxDisplaySegments = log10(maxDisplaySegments);

  pinMode(showPeaksPin, INPUT);

  if (useSelectButton1)
    pinMode(selectButton1Pin, INPUT);

  left_strip.begin();
  if (stripsOn2Pins)
    right_strip.begin();

  if (useSensorValues) {
    readSensorValues();
    setInitialDisplayPeaks();
  }
  else {
    setStripColors();
    setSensitivityFactor();
  }

#ifdef DEBUG_TEST_LEDS
  displayTest();
#endif

  startupAnimation();
}

//
// bucle principal+
//

void loop() {
#ifdef DEBUG_PRINT_LOOP_TIME
  long time = millis();
#endif


  if (useSensorValues)
    readSensorValues();

  readValues();

#if defined (DEBUG_NO_PEAKS)
  displayPeaks = false;
#endif

#if defined (DEBUG_PEAKS)
  displayPeaks = true;
#endif

  if (pulsing) {
    drawPulsingValues();
  }
  else {
    drawValues();
    if (displayPeaks) {
      getPeaks();
      drawPeaks();
    }
  }

  left_strip.show();
  if (stripsOn2Pins)
    right_strip.show();

  storePrevValues();

  checkSpinCircle();

#ifdef DEBUG_PRINT_LOOP_TIME
  time = millis() - time;
  Serial.println(time);
#endif
}

//
// funciones
//

void setInitialDisplayPeaks() {
#if !defined (DEBUG_NO_PEAK_SWITCH)
  showPeaksPinSetting = digitalRead(showPeaksPin);

  if (showPeaksPinSetting == HIGH)
    displayPeaks = false;
#endif

  if (reverseShowPeaks) {
    if (!displayPeaks)
      displayPeaks = true;
    else
      displayPeaks = false;
  }

  prevShowPeaksPinSetting = showPeaksPinSetting;
}

void readSensorValues() {
  //
  // 3er botón Switch de hold peaks
  //

#if !defined (DEBUG_NO_PEAK_SWITCH)
  showPeaksPinSetting = digitalRead(showPeaksPin);

  if (showPeaksMomentarySwitch) {
    if (showPeaksPinSetting == LOW && prevShowPeaksPinSetting == HIGH) {
      if (displayPeaks == true) {
        displayPeaks = false;
        clearLeftPeak();
        clearRightPeak();
        if (showPeaksMomentarySwitch)
          while (digitalRead(showPeaksPin) == LOW) {}
      }
      else {
        displayPeaks = true;
      }
    }
  }
  else {
    if (reverseShowPeaks) {
      if (showPeaksPinSetting == HIGH && prevShowPeaksPinSetting == LOW)
        displayPeaks = true;
      else if (showPeaksPinSetting == LOW && prevShowPeaksPinSetting == HIGH) {
        displayPeaks = false;
        clearLeftPeak();
        clearRightPeak();
      }
    }
    else {
      if (showPeaksPinSetting == LOW && prevShowPeaksPinSetting == HIGH)
        displayPeaks = true;
      else if (showPeaksPinSetting == HIGH && prevShowPeaksPinSetting == LOW) {
        displayPeaks = false;
        clearLeftPeak();
        clearRightPeak();
      }
    }
  }
  if (pulsing) {
    if (displayPeaks)
      displayTopAsPeak = true;
    else
      displayTopAsPeak = false;
  }

  prevShowPeaksPinSetting = showPeaksPinSetting;
#endif


  //
  // switches de selección 1 y 2
  //
  if (useSelectButton1) {
    selectButton1PinState = digitalRead(selectButton1Pin);

    if (selectButton1PinState == HIGH && prevSelectButton1PinState == LOW)
      selectButton1Timer = millis();

    if (selectButton1PinState == HIGH && prevSelectButton1PinState == HIGH) {
      if ((millis() - selectButton1Timer) > 1000) {
        pulsing = !pulsing;
        setStripColors();
        displayNumber(colorScheme, 250);

        while (digitalRead(selectButton1Pin) == HIGH) {}
        selectButton1PinState = LOW;
        clearValues();
      }
    }
    else if (selectButton1PinState == LOW && prevSelectButton1PinState == HIGH) {
      selectButton1PinSetting++;
      if (selectButton1PinSetting > maxColorScheme) {
        selectButton1PinSetting = 0;
      }
      colorScheme = selectButton1PinSetting;

      if (colorScheme == 12)
        colorScheme11SpinValue = (colorScheme11SpinValue * colorScheme12Factor);

      setStripColors();
      displayNumber(colorScheme, 250);
    }
    prevSelectButton1PinState = selectButton1PinState;
  }

  if (useSelectButton2) {
    selectButton2PinState = digitalRead(selectButton2Pin);

    if (selectButton2PinState == HIGH && prevSelectButton2PinState == LOW) {
      selectButton2PinSetting++;

      switch (selectButton2PinSetting) {
        case 0:
        case 3: {
            pulsing = false;
            spinCircle = false;
            selectButton2PinSetting = 0;
            break;
          }
        case 1: {
            pulsing = true;
            spinCircle = false;
            break;
          }
        case 2: {
            pulsing = true;
            spinCircle = true;
            break;
          }
      }

      setStripColors();
      displayNumber(colorScheme, 250);
    }

    prevSelectButton2PinState = selectButton2PinState;
  }

  //
  // brillo
  //
  brightnessValue = analogRead(brightnessPin);
  brightnessValue = map(brightnessValue, 0, 1023, 0, 255);

  if (abs(brightnessValue - prevBrightnessValue) > sensorDeviationBrightness) {
    ledBrightness = brightnessValue;
    setStripColors();
    prevBrightnessValue = brightnessValue;
  }

  //
  // color (11, giro de arcoiris )
  //

  if (colorScheme == 11 || colorScheme == 12) {
    colorScheme11SpinDelayValue++;
    if (colorScheme11SpinDelayValue == colorScheme11SpinDelay) {
      colorScheme11SpinDelayValue = 0;
      colorScheme11SpinValue++;
      if (colorScheme11SpinValue > maxDisplaySegments * colorSchemeFactor)
        colorScheme11SpinValue = 0;
      setStripColors();
    }
  }

  //
  // sensibilidad del Vumetro
  //
  sensitivityValue = analogRead(sensitivityPin);
  sensitivityValue = map(sensitivityValue, 0, 1023, 0, 255);
  setSensitivityFactor();
}

void setSensitivityFactor() {
  //valor de sensibilidad_div_num de Segmentos = valor de sensibilidad / num de Segmentos;
  sensitivityFactor = ((float) sensitivityValue / 255 * (float) maxSensitivity / 255);
}

void readValues() {
#ifdef averageReadings
  leftAnalogValue = 0;
  rightAnalogValue = 0;

  for (i = 0; i <= averageNumOfReadings; i++) {
    leftAnalogValue += analogRead(leftPin);
    rightAnalogValue += analogRead(rightPin);
  }

  leftAnalogValue /= averageNumOfReadings;
  rightAnalogValue /= averageNumOfReadings;

#else
  leftAnalogValue = analogRead(leftPin);
  rightAnalogValue = analogRead(rightPin);
#endif

  if (swapLeftRight) {
    int tempValue = leftAnalogValue;
    leftAnalogValue = rightAnalogValue;
    rightAnalogValue = tempValue;
  }

  if (leftAnalogValue < prevLeftAnalogValue) {
    leftDropTime++;
    if (leftDropTime > dropDelay) {
      leftAnalogValue = prevLeftAnalogValue * dropFactor;
      leftDropTime = 0;
    }
    else
      leftAnalogValue = prevLeftAnalogValue;
  }

  if (rightAnalogValue < prevRightAnalogValue) {
    rightDropTime++;
    if (rightDropTime > dropDelay) {
      rightAnalogValue = prevRightAnalogValue * dropFactor;
      rightDropTime = 0;
    }
    else
      rightAnalogValue = prevRightAnalogValue;
  }

#ifdef DEBUG_PRINT_ANALOGVALUES
  Serial.print(leftAnalogValue);
  Serial.print(" ");
  Serial.println(rightAnalogValue);
#endif

  // mapa de  valores
  leftValue = map(leftAnalogValue * sensitivityFactor, minValue, maxValue, 0, maxDisplaySegments);
  rightValue = map(rightAnalogValue * sensitivityFactor, minValue, maxValue, 0, maxDisplaySegments);

  // si se define, convertir a (inversa) respuesta no lineal de audio
  boolean flagNonLinear = false;

#if defined (nonLinearSinAudio)
  flagNonLinear = true;
  leftValueN = ((sin(((leftValue * nonLinearResponseFactor) + 270) * 0.0174533) + 1) * maxDisplaySegments);
  rightValueN = ((sin(((rightValue * nonLinearResponseFactor) + 270) * 0.0174533) + 1) * maxDisplaySegments);

#elif defined (nonLinearReverseSinAudio)
  flagNonLinear = true;
  leftValueN = ((sin(((leftValue * nonLinearResponseFactor)) * 0.0174533)) * maxDisplaySegments);
  rightValueN = ((sin(((rightValue * nonLinearResponseFactor)) * 0.0174533)) * maxDisplaySegments);

#elif defined (nonLinearLogAudio)
  flagNonLinear = true;
  leftValueN = ((log10(leftValue  + 1) / log10MaxDisplaySegments * maxDisplaySegments));
  rightValueN = ((log10(rightValue  + 1) / log10MaxDisplaySegments * maxDisplaySegments));

#endif

  if (flagNonLinear == true) {
#if defined (nonLinearAvr2)
    leftValue = (leftValue + leftValueN) / 2;
    rightValue = (rightValue + rightValueN) / 2;
#else
    leftValue = leftValueN;
    rightValue = rightValueN;
#endif
  }

  // @EB_DEPURACIÓN

#ifdef displayOverflow
#ifdef compressOverflowPeaks
  for (i = 1; i <= compressOverflowNumOfTimes; i++) {
    if (leftValue > maxDisplaySegments) {
      //          Serial.print(i);
      //          Serial.print("  ");
      //          Serial.print(Valor izquierdo);
      //          Serial.print("  ");
      leftValue = leftValue - leftValue * compressOverflowFactor * i;
      //          Serial.print(Valor izquierdo);
      //          Serial.print("  ");
      //          Serial.println(Mostrar todos los segmentos);
    }
  }
#endif
#endif

  if (leftValue > maxDisplaySegments) {
    leftValue = maxDisplaySegments;
#ifdef displayOverflow
    drawOverflow();
#endif
  }

#ifdef displayOverflow
#ifdef compressOverflowPeaks
  if (rightValue > maxDisplaySegments)
    rightValue = rightValue - rightValue * compressOverflowFactor;
#endif
#endif

  if (rightValue > maxDisplaySegments) {
    rightValue = maxDisplaySegments;
#ifdef displayOverflow
    drawOverflow();
#endif
  }
}

void storePrevValues() {
  prevLeftAnalogValue = leftAnalogValue;
  prevRightAnalogValue = rightAnalogValue;

  prevLeftValue = leftValue;
  prevRightValue = rightValue;
}

void getPeaks() {
  if (leftValue > leftPeak) {
    if (dynamicBouncingPeaks || prevLeftPeakBounce > 0)
      clearLeftBouncePeak();

    leftPeak = leftValue;
    leftPeakTime = 0;
    leftFirstPeak = true;

    if (bouncingPeaks) {
      leftPeakBouncing = true;
      leftPeakBounceCounter = 0;
      leftPeakBounceDelayCounter = 0;

      if (dynamicBouncingPeaks)
        leftBouncingPeaksNumOfLeds = max(bouncingPeaksNumOfLedsMin, (leftPeak * bounceFactor));
      else
        leftBouncingPeaksNumOfLeds = bouncingPeaksNumOfLeds;
    }
  }
  else {
    leftPeakTime++;
    if (droppingPeak) {
      if (leftFirstPeak) {
        if (leftPeakTime > peakTimeFirstDropDelay) {
          clearLeftPeak();
          leftFirstPeak = false;
        }
      }
      else {
        if (leftPeakTime > peakTimeDropDelay) {
          clearLeftPeak();
        }
      }
    }
    else {
      if (leftPeakTime > peakTimeNoDropDelay) {
        clearLeftPeak();
      }
    }
  }

  if (leftPeakBouncing) {
    if (leftFirstPeak) {
      leftPeakBounceDelayCounter++;
      if (leftPeakBounceDelayCounter >= bouncingPeakDelay) {
        leftPeakBounceDelayCounter = 0;
        leftPeakBounceCounter += bouncingPeakCounterInc;
        if (leftPeakBounceCounter >= 180) {
          clearLeftBouncePeak();
          clearLeftBounce();
        }
        else {
          leftPeakBounce = min((sin(leftPeakBounceCounter * 0.0174533) * leftBouncingPeaksNumOfLeds), (maxDisplaySegments - leftPeak));
          if (leftPeakBounce != prevLeftPeakBounce) {
            clearLeftBouncePeak();
          }
          prevLeftPeakBounce = leftPeakBounce;
        }
      }
    }
  }

  if (rightValue > rightPeak) {
    if (dynamicBouncingPeaks || prevRightPeakBounce > 0)
      clearRightBouncePeak();

    rightPeak = rightValue;
    rightPeakTime = 0;
    rightFirstPeak = true;

    if (bouncingPeaks) {
      rightPeakBouncing = true;
      rightPeakBounceCounter = 0;
      rightPeakBounceDelayCounter = 0;

      if (dynamicBouncingPeaks)
        rightBouncingPeaksNumOfLeds = max(bouncingPeaksNumOfLedsMin, (rightPeak * bounceFactor));
      else
        rightBouncingPeaksNumOfLeds = bouncingPeaksNumOfLeds;
    }
  }
  else {
    rightPeakTime++;
    if (droppingPeak) {
      if (rightFirstPeak) {
        if (rightPeakTime > peakTimeFirstDropDelay) {
          clearRightPeak();
          rightFirstPeak = false;
        }
      }
      else {
        if (rightPeakTime > peakTimeDropDelay)
          clearRightPeak();
      }
    }
    else {
      if (rightPeakTime > peakTimeNoDropDelay)
        clearRightPeak();
    }
  }

  if (rightPeakBouncing) {
    if (rightFirstPeak) {
      rightPeakBounceDelayCounter++;
      if (rightPeakBounceDelayCounter >= bouncingPeakDelay) {
        rightPeakBounceDelayCounter = 0;
        rightPeakBounceCounter += bouncingPeakCounterInc;

        if (rightPeakBounceCounter >= 180) {
          clearRightBouncePeak();
          clearRightBounce();
        }
        else {
          rightPeakBounce = min((sin(rightPeakBounceCounter * 0.0174533) * rightBouncingPeaksNumOfLeds), (maxDisplaySegments - rightPeak));
          if (rightPeakBounce != prevRightPeakBounce) {
            clearRightBouncePeak();
          }
          prevRightPeakBounce = rightPeakBounce;
        }
      }
    }
  }
}

void checkSpinCircle () {
  if (spinCircle) {
    if (spinTurnsMax == 0) {
      spinTurnsMax = random(stripNumOfLeds / 4, stripNumOfLeds * 3);  // gira al menos un cuarto de vuelta, máximo 3 vueltas

      if (random(10) > 4)
        spinCounterInc = -spinCounterInc;

      spinTurnsDelayMax = random(100, 1000); // @EB_DEPURAR

      spinDelay = random(20, 75); // @EB_DEPURAR
    }

    if (spinTurnsCounter == spinTurnsMax) {
      spinTurnsDelay++;
      if (spinTurnsDelay == spinTurnsDelayMax) {
        spinTurnsDelay = 0;
        spinTurnsCounter = 0;
        spinTurnsMax = 0;
      }
    }
    else {
      spinDelayCounter++;

      if (spinDelayCounter > spinDelay) {
        clearZeroAndPeaks();

        spinCounter += spinCounterInc;
        if (spinCounter > stripNumOfLeds)
          spinCounter = 0;
        else if (spinCounter < 0)
          spinCounter = stripNumOfLeds;

        spinTurnsCounter++;
        spinDelayCounter = 0;
      }
    }
  }
}

int getSpinCircleValue(int value) {
  if (!spinCircle)
    return value;
  else {
    int calcValue = value + spinCounter;
    if (calcValue >= stripNumOfLeds)
      calcValue -= stripNumOfLeds;
    return calcValue;
  }
}

void drawValues() {
  if (splitStrip) {
    for (i = middleOffset; i < leftValue; i++)
      left_strip.setPixelColor(getSpinCircleValue(i), stripColor[i]);

    if (!displayPeaks && displayTopAsPeak)
      left_strip.setPixelColor(getSpinCircleValue(leftValue), stripHoldColor);

    for (i = prevLeftValue; i >= leftValue; i--)
      left_strip.setPixelColor(getSpinCircleValue(i), 0);

    if (stripsOn2Pins) {
      for (i = middleOffset; i < rightValue; i++)
        right_strip.setPixelColor(i, stripColor[i]);

      if (!displayPeaks && displayTopAsPeak)
        right_strip.setPixelColor(rightValue, stripHoldColor);

      for (i = prevRightValue; i >= rightValue; i--)
        right_strip.setPixelColor(i, 0);
    }
    else {
      for (i = middleOffset; i < rightValue; i++)
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + i), stripColor[i]);

      if (!displayPeaks && displayTopAsPeak)
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + rightValue), stripHoldColor);

      for (i = prevRightValue; i >= rightValue; i--)
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + i), 0);
    }
  }
  else {
    for (i = middleOffset; i < leftValue; i++)
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + i), stripColor[i]);

    if (!displayPeaks && displayTopAsPeak)
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + leftValue), stripHoldColor);

    for (i = prevLeftValue; i >= leftValue; i--)
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + i), 0);

    for (i = middleOffset; i < rightValue; i++)
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - i), stripColor[i]);

    if (!displayPeaks && displayTopAsPeak)
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - rightValue), stripHoldColor);

    for (i = prevRightValue; i >= rightValue; i--)
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - i), 0);
  }

  if (displayMiddleLed)
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle), stripMiddleColor);
}

void drawPulsingValues() {
  halfLeftValue = (leftValue + 1) / 2;
  halfRightValue = (rightValue + 1) / 2;
  halfPrevLeftValue = (prevLeftValue + 1) / 2;
  halfPrevRightValue = (prevRightValue + 1) / 2;

  if (splitStrip) {
    for (i = 0; i < halfLeftValue; i++) {
      colorValue = stripColor[i * 2];
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle + i), colorValue);
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle - i), colorValue);
    }

    if (displayTopAsPeak) {
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle + halfLeftValue), stripHoldColor);
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle - halfLeftValue), stripHoldColor);
    }

    for (i = halfPrevLeftValue; i >= halfLeftValue; i--) {
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle + i), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle - i), 0);
    }

    if (stripsOn2Pins) {
      for (i = 0; i < halfRightValue; i++) {
        colorValue = stripColor[i * 2];
        right_strip.setPixelColor((stripPulseMiddle + i), colorValue);
        right_strip.setPixelColor((stripPulseMiddle - i), colorValue);
      }

      if (displayTopAsPeak) {
        right_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle + halfRightValue), stripHoldColor);
        right_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle - halfRightValue), stripHoldColor);
      }

      for (i = halfPrevRightValue; i >= halfRightValue; i--) {
        right_strip.setPixelColor((stripPulseMiddle + i), 0);
        right_strip.setPixelColor((stripPulseMiddle - i), 0);
      }
    }
    else {
      for (i = 0; i < halfRightValue; i++) {
        colorValue = colorValue = stripColor[i * 2];
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + i), colorValue);
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - i), colorValue);
      }

      if (displayTopAsPeak) {
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + halfRightValue), stripHoldColor);
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - halfRightValue), stripHoldColor);
      }

      for (i = halfPrevRightValue; i >= halfRightValue; i--) {
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + i), 0);
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - i), 0);
      }
    }
  }
  else {
    for (i = 0; i < halfLeftValue; i++) {
      colorValue = colorValue = stripColor[i * 2];
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + i), colorValue);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - i), colorValue);
    }

    if (displayTopAsPeak) {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + halfLeftValue), stripHoldColor);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - halfLeftValue), stripHoldColor);
    }

    for (i = halfPrevLeftValue; i >= halfLeftValue; i--) {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + i), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - i), 0);
    }

    for (i = 0; i < halfRightValue; i++) {
      colorValue = colorValue = stripColor[i * 2];
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle + i)), colorValue);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle - i)), colorValue);
    }

    if (displayTopAsPeak) {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle + halfRightValue)), stripHoldColor);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle - halfRightValue)), stripHoldColor);
    }

    for (i = halfPrevRightValue; i >= halfRightValue; i--) {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle + i)), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle - i)), 0);
    }
  }

  if (displayMiddleLed) {
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle - stripPulseMiddle), stripMiddleColor);
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle), stripMiddleColor);
  }
}

void clearZeroAndPeaks() {
  left_strip.setPixelColor(getSpinCircleValue(middleOffset), 0);
  left_strip.setPixelColor(getSpinCircleValue(stripMiddle), 0);

  if (displayTopAsPeak) {
    if (splitStrip) {
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle + halfLeftValue), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripPulseMiddle - halfLeftValue), 0);

      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + halfRightValue), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - halfRightValue), 0);
    }
    else {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle + halfLeftValue), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + stripPulseMiddle - halfLeftValue), 0);

      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle + halfRightValue)), 0);
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (stripPulseMiddle - halfRightValue)), 0);
    }
  }
}

void drawPeaks() {
  if (leftPeak > 0) {
    if (droppingPeakFade && leftPeakBouncing == false)
      stripHoldColor = left_strip.Color(max(1, (255 * leftPeak * ledFactor_div_numOfSegments)), 0, 0);
    else
      stripHoldColor = stripColor[numOfSegments];

    if (splitStrip)
      left_strip.setPixelColor(getSpinCircleValue(leftPeak + leftPeakBounce), stripHoldColor);
    else
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + (leftPeak + leftPeakBounce)), stripHoldColor);
  }

  if (rightPeak > 0) {
    if (droppingPeakFade && rightPeakBouncing == false)
      stripHoldColor = left_strip.Color(max(1, (255 * rightPeak * ledFactor_div_numOfSegments)), 0, 0);
    else
      stripHoldColor = stripColor[numOfSegments];

    if (splitStrip) {
      if (stripsOn2Pins) {
        right_strip.setPixelColor(getSpinCircleValue(rightPeak + rightPeakBounce), stripHoldColor);
      }
      else {
        left_strip.setPixelColor(getSpinCircleValue(stripMiddle + rightPeak + rightPeakBounce), stripHoldColor);
      }
    }
    else {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (rightPeak + rightPeakBounce)), stripHoldColor);
    }
  }

  // (pico (clipping) izquierdo > 0 || pico (clipping) derecho > 0)
  //  mostrar tira led izquierda();
}

void clearLeftPeak() {
  if (splitStrip)
    left_strip.setPixelColor(getSpinCircleValue(leftPeak + prevLeftPeakBounce), 0);
  else
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle + (leftPeak + prevLeftPeakBounce)), 0);

  if (droppingPeak)
    leftPeak = leftPeak * peakDropFactor;
  else
    leftPeak = 0;
  leftPeakTime = 0;
}

void clearRightPeak() {
  if (splitStrip) {
    if ( stripsOn2Pins) {
      right_strip.setPixelColor(getSpinCircleValue(rightPeak + prevRightPeakBounce), 0);
    }
    else {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + rightPeak + prevRightPeakBounce), 0);
    }
  }
  else {
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (rightPeak + prevRightPeakBounce)), 0);
  }

  if (droppingPeak)
    rightPeak = rightPeak * peakDropFactor;
  else
    rightPeak = 0;
  rightPeakTime = 0;
}

void clearLeftBouncePeak() {
  if (splitStrip)
    left_strip.setPixelColor(getSpinCircleValue(leftPeak + prevLeftPeakBounce), 0);
  else
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle + (leftPeak + prevLeftPeakBounce)), 0);
}

void clearRightBouncePeak() {
  if (splitStrip) {
    if (stripsOn2Pins) {
      right_strip.setPixelColor(getSpinCircleValue(rightPeak + prevRightPeakBounce), 0);
    }
    else {
      left_strip.setPixelColor(getSpinCircleValue((stripMiddle + rightPeak + prevRightPeakBounce)), 0);
    }
  }
  else {
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle - (rightPeak + prevRightPeakBounce)), 0);
  }
}

void clearLeftBounce() {
  leftPeakBouncing = false;
  leftPeakBounceCounter = 0;
  leftPeakBounce = 0;
  prevLeftPeakBounce = 0;
  leftBouncingPeaksNumOfLeds = 0;
}

void clearRightBounce() {
  rightPeakBouncing = false;
  rightPeakBounceCounter = 0;
  rightPeakBounce = 0;
  prevRightPeakBounce = 0;
  leftBouncingPeaksNumOfLeds = 0;
}

void clearValues() {
  leftAnalogValue = 0;
  rightAnalogValue = 0;
  prevLeftAnalogValue = 0;
  prevRightAnalogValue = 0;
  leftPeak = 0;
  rightPeak = 0;
}


void drawOverflow() {
  for (i = 0; i <= numOfSegments; i++) {
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle - i), stripOverflowColor);
    if (stripsOn2Pins) {
      right_strip.setPixelColor(i, stripOverflowColor);
    }
    else {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + i), stripOverflowColor);
    }
  }
  left_strip.show();
  if (stripsOn2Pins)
    right_strip.show();

  delay(overflowDelay);

  for (i = 0; i <= numOfSegments; i++) {
    left_strip.setPixelColor(getSpinCircleValue(stripMiddle - i), 0);
    if (stripsOn2Pins) {
      right_strip.setPixelColor(i, 0);
    }
    else {
      left_strip.setPixelColor(getSpinCircleValue(stripMiddle + i), 0);
    }
  }
  left_strip.show();
  if (stripsOn2Pins)
    right_strip.show();
}

void setStripColors() {
  int r, g, b;
  int p1, p2;

  ledFactor = (float) ledBrightness / 255;
  ledFactor_div_numOfSegments = (float) ledFactor / (float) numOfSegments;
  stripMiddleColor = left_strip.Color(0, 0, 255 * ledFactor);

  switch (colorScheme) {
    case 0: {
        int orangeLimit;
        float orangeFactor = orangeLimitAmount / halfNumOfSegments;

        for (i = 0; i <= numOfSegments; i++) {
          if (i <= halfNumOfSegments)
            orangeLimit = (i * orangeFactor);
          else
            orangeLimit = ((numOfSegments - i) * orangeFactor);

          stripColor[i] = left_strip.Color((255 * i * ledFactor_div_numOfSegments), ((255 - orangeLimit) * (numOfSegments - i) * ledFactor_div_numOfSegments), 0);
        }
        break;
      }

    case 1: {
        for (i = 0; i <= numOfSegments; i++) {
          stripColor[i] = left_strip.Color(0, (255 * i * ledFactor_div_numOfSegments), (255 * (numOfSegments - i) * ledFactor_div_numOfSegments));
        }
        break;
      }

    case 2: {
        for (i = 0; i <= numOfSegments; i++) {
          stripColor[i] = left_strip.Color((255 * i * ledFactor_div_numOfSegments), 0, (255 * (numOfSegments - i) * ledFactor_div_numOfSegments));
        }
        break;
      }

    case 3: {
        for (i = 0; i <= numOfSegments; i++) {
          stripColor[i] = left_strip.Color((255 * (numOfSegments - i) * ledFactor_div_numOfSegments), 0, (255 * i * ledFactor_div_numOfSegments));
        }
        break;
      }

    case 4: {
        for (i = 0; i <= numOfSegments; i++) {
          stripColor[i] = left_strip.Color(0, (255 * (numOfSegments - i) * ledFactor_div_numOfSegments), (255 * i * ledFactor_div_numOfSegments));
        }
        break;
      }

    case 5: {
        for (i = 0; i <= numOfSegments; i++) {
          stripColor[i] = left_strip.Color((255 * (numOfSegments - i) * ledFactor_div_numOfSegments), (255 * i * ledFactor_div_numOfSegments), 0);
        }
        break;
      }

    case 6: {
        for (i = 0; i <= numOfSegments; i++) {
          r = (255 * i * ledFactor_div_numOfSegments);
          g = (255 * min(i, numOfSegments - i) * ledFactor_div_numOfSegments);
          b = (200 * (numOfSegments - i) * ledFactor_div_numOfSegments);
          stripColor[i] = left_strip.Color(r, g, b);
        }
        break;
      }

    case 7: {
        for (i = 0; i <= numOfSegments; i++) {
          b = (255 * i * ledFactor_div_numOfSegments);
          g = (255 * min(i, numOfSegments - i) * ledFactor_div_numOfSegments);
          r = (255 * (numOfSegments - i) * ledFactor_div_numOfSegments);
          stripColor[i] = left_strip.Color(r, g, b);
        }
        break;
      }

    case 8: {
        for (i = 0; i <= numOfSegments; i++) {
          r = (255 * i * ledFactor_div_numOfSegments);
          b = (255 * min(i, numOfSegments - i) * ledFactor_div_numOfSegments);
          g = (255 * (numOfSegments - i) * ledFactor_div_numOfSegments);
          stripColor[i] = left_strip.Color(r, g, b);
        }
        break;
      }

    case 9: {
        for (i = 0; i <= numOfSegments; i++) {
          b = (255 * i * ledFactor_div_numOfSegments);
          r = (255 * min(i, numOfSegments - i) * ledFactor_div_numOfSegments);
          g = (255 * (numOfSegments - i) * ledFactor_div_numOfSegments);
          stripColor[i] = left_strip.Color(r, g, b);
        }
        break;
      }

    case 10:
      colorScheme11SpinValue = 0;

    case 11:

    case 12: {
        p1 = (85 * numOfSegments / 255);
        p2 = (170 * numOfSegments / 255);
        int wheel;

        if (colorScheme == 12)
          colorSchemeFactor = colorScheme12Factor;
        else
          colorSchemeFactor = 1;

        for (i = 0; i <= numOfSegments; i++) {
          //rueda de leds = int(float(i + esquema de color 11 (SpinValue) / factor de esquema de color) % num, de Segmentos;  // rueda de reversa

          wheel = int(float(i - colorScheme11SpinValue) / colorSchemeFactor + numOfSegments) % numOfSegments;

          if (wheel < p1) {
            wheel = map(wheel, 0, p1, 0, 255);
            r = (wheel * ledFactor);
            g = ((255 - wheel) * ledFactor);
            b = 0;
          }
          else if (wheel < p2) {
            wheel = map(wheel, p1, p2, 0, 255);
            r = ((255 - wheel) * ledFactor);
            g = 0;
            b = (wheel * ledFactor);
          }
          else {
            wheel = map(wheel, p2, numOfSegments, 0, 255);
            r = 0;
            g = (wheel * ledFactor);
            b = ((255 - wheel) * ledFactor);
          }

          stripColor[i] = left_strip.Color(r, g, b);
        }
        break;
      }
  }

  if (colorScheme >= 10)
    stripHoldColor = left_strip.Color(255 * ledFactor, 0, 0); // Configurado a color rojo para la rueda de colores
  else
    stripHoldColor = stripColor[numOfSegments];

  stripOverflowColor = stripHoldColor;   // tira_izquierda. Color(min(255, 255 * Factor led * 1.5), 0, 0);
}

void startupAnimation() {
  for (j = 0; j < 2; j++) {
    for (i = 0; i <= numOfSegments; i++) {
      if (animType == 1)
        left_strip.setPixelColor(stripMiddle - (numOfSegments - i), stripColor[i]);
      else
        left_strip.setPixelColor(stripMiddle - i, stripColor[i]);

      if (stripsOn2Pins)
        right_strip.setPixelColor(i, stripColor[i]);
      else
        left_strip.setPixelColor(stripMiddle + i, stripColor[i]);

      left_strip.show();
      if (stripsOn2Pins)
        right_strip.show();

      delay(startupAnimationDelay);
    }

    for (i = 0; i <= numOfSegments; i++) {
      if (animType == 1)
        left_strip.setPixelColor(stripMiddle - (numOfSegments - i), 0);
      else
        left_strip.setPixelColor(stripMiddle - i, 0);

      if (stripsOn2Pins)
        right_strip.setPixelColor(i, 0);
      else
        left_strip.setPixelColor(stripMiddle + i, 0);

      left_strip.show();
      if (stripsOn2Pins)
        right_strip.show();

      delay(startupAnimationDelay);
    }
  }
}

void displayNumber (int number, int displayDelay) {
  left_strip.clear();
  if (stripsOn2Pins)
    right_strip.clear();

  number++; // @EB_DEPURAR : mostrar valor 0 en led 1

  for (i = 0; i <= number; i++) {
    if (i % 5 == 0)
      colorValue = stripMiddleColor;
    else
      colorValue = stripColor[0];

    left_strip.setPixelColor(middleOffset + i, colorValue);

    if (stripsOn2Pins)
      right_strip.setPixelColor(middleOffset + i, colorValue);
    else
      left_strip.setPixelColor(stripMiddle + middleOffset + i, colorValue);

    delay(45 - number * 3); // @EB_DEPURACIÓN

    left_strip.show();
    if (stripsOn2Pins)
      right_strip.show();
  }

  if (pulsing) {
    left_strip.setPixelColor(middleOffset + maxDisplaySegments, stripMiddleColor);

    if (stripsOn2Pins)
      right_strip.setPixelColor(maxDisplaySegments, stripMiddleColor);
    else
      left_strip.setPixelColor(stripMiddle + maxDisplaySegments, stripMiddleColor);

    left_strip.show();
    if (stripsOn2Pins)
      right_strip.show();
  }

  delay(displayDelay);

  left_strip.clear();
  if (stripsOn2Pins)
    right_strip.clear();
}


//
// para la depuración
//

#ifdef DEBUG_TEST_LEDS
void displayTest() {
  for (i = 0; i <= numOfSegments; i++) {
    left_strip.setPixelColor(stripMiddle - i, stripColor[i]);

    if (stripsOn2Pins)
      right_strip.setPixelColor(i, stripColor[i]);
    else
      left_strip.setPixelColor(stripMiddle + i, stripColor[i]);

    left_strip.show();
    if (stripsOn2Pins)
      right_strip.show();

    delay(50);
  }
  delay(5000);

  for (i = 0; i <= numOfSegments; i++) {
    left_strip.setPixelColor(stripMiddle - i, 0);

    if (stripsOn2Pins)
      right_strip.setPixelColor(i, 0);
    else
      left_strip.setPixelColor(stripMiddle + i, 0);

    left_strip.show();
    if (stripsOn2Pins)
      right_strip.show();
  }
}

void serialDisplayRGB(int r, int g, int b) {
  Serial.print(i);
  Serial.print(" ");
  Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.println(b);
}
#endif
