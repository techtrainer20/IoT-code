#include <DHT.h>
#include <ESP8266WiFi.h>
 
#define DHTPIN 13          //DHT11 is connected to GPIO Pin 2

String apiKey = "QW5A6OGIAVSGPYHI";     //  Enter your Write API key from ThingSpeak
const char* ssid =  "spv";     // Enter your WiFi Network's SSID
const char* pass =  "987654321"; // Enter your WiFi Network's Password
const char* server = "api.thingspeak.com";
 
float humi;
float temp;
 
DHT dht(DHTPIN, DHT11);
WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);
       dht.begin();
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(100);
            Serial.print("*");
     }
      Serial.println("");
      Serial.println("***WiFi connected***");
 
}
 
void loop() 
{
  
      humi = dht.readHumidity();
      temp = dht.readTemperature();
 
      if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
      {  
       String sendData = apiKey+"&field1="+String(temp)+"&field2="+String(humi)+"\r\n\r\n"; 
       
       //Serial.println(sendData);

       client.print("POST /update HTTP/1.1\n");
       client.print("Host: api.thingspeak.com\n");
       client.print("Connection: close\n");
       client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
       client.print("Content-Type: application/x-www-form-urlencoded\n");
       client.print("Content-Length: ");
       client.print(sendData.length());
       client.print("\n\n");
       client.print(sendData);

       Serial.print("Temperature: ");
       Serial.print(temp);
       Serial.print("deg C. Humidity: ");
       Serial.print(humi);
       Serial.println("%. Connecting to Thingspeak.");
       }
      
      client.stop();

      Serial.println("Sending....");
  
 delay(1000);
}
