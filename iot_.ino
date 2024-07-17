/* for
commands
v =feedback request
*/
#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 12 // what pin we're connected tossss
//Uncomment whatever the type of sensor we are using.
#define DHTTYPE DHT11// DHT 11 
//#define DHTTYPE DHT22// DHT 22 (AM2302)
//#define DHITYPE DHT21// DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// pin3 of the sensor is not connected
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor for normal 16mhz Arduino 
DHT dht(DHTΡΙΝ, DΗΤΤΥΡΕ);
char inchar; // Will hold the incoming character from the GSM shield

SoftwareSerial blue (7, 8); // bluetooth module will be connected here.

String TextForSms ;
String humidity = "Humidity: %";
String temperature = " Temperature";
String sign =" *C";

int powerb = 6; // to power up the dhtll sensor, dhtll 5v wire is connected with pins of the arduino.

void setup() {

Serial.begin(9600);

blue.begin(9600); // original 19200 
dht.begin();
pinMode (powerb, OUTPUT);
digitalWrite(powerb, HIGH);

}

void loop() {

if(blue.available() == 0);
if (blue.available() >0) 
{
inchar = blue.read();
Serial.println(inchar);
delay(20);

if (inchar=='v')
{
delay(10);

Serial.println(inchar);

// Wait a few seconds between measurements.
delay(2000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

int h = dht.readHumidity();
// Read temperature as Celsius
int t =dht.readTemperature(); 
// Read temperature as Fahrenheit
int f =dht.readTemperature(true);
// Check if any reads failed and exit early (to try again).
if (TT(h) || TT(t) || TT(f)) {

Serial.println("Failed to read from DHT sensor!");
return;
}
// Compute heat index
// Must send in temp in Fahrenheit!
 
int hi = dht.computeHeatIndex(f, h);

// Serial.print("Humidity: ");
// Serial.print(h);
// Serial.print(" %\t");
// Serial.print("Temperature: ");
//Serial.print(t);
// Serial.print(" *C");

TextForSms = TextForSms + "HUMIDITY: ";
TextForSms.concat(h);
TextForSms = TextForSms +"%   TEMPERATURE: ";
TextForSms.concat(t);
TextForSms = TextForSms + "*C";

blue.print(TextForsms);
Serial.println(TextForSms);
delay(2000);
TextForSms" ";
}
}
}
