#define BLYNK_TEMPLATE_ID "TMPL3NslAlq3V"
#define BLYNK_TEMPLATE_NAME "IoT1"
#define BLYNK_AUTH_TOKEN "01Xezj89Tx5S6b3gh8pGKVbIyLZxk4RG"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 // Name the sensor as an object

char auth[] = "01Xezj89Tx5S6b3gh8pGKVbIyLZxk4RG";
char ssid[] = "vivo 1818";
char pass[] = "12345678";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth,ssid,pass);
  Serial.println("Blyink connected sucessfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return; 
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature");
  Serial.print(t);
  Serial.println("degrees celsius.");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  delay(1000);
}
