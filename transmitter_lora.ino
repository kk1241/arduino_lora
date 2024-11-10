/*  
 *   Transmitter side Code
 * 
  Module SX1278 // Arduino UNO/NANO    
    Vcc         ->   3.3V
    MISO        ->   D12
    MOSI        ->   D11     
    SLCK        ->   D13
    Nss         ->   D10 
    GND         ->   GND    
 */
#include <SPI.h>
#include <LoRa.h>
 
void setup() {
  Serial.begin(9600);
   
  while (!Serial);  
  Serial.println("LoRa Sender");
  
  if (!LoRa.begin(433E6)) { 
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() {
String MyMessage = "Hello nikita";
  LoRa.beginPacket();  
  LoRa.print(MyMessage);
  LoRa.endPacket();
  delay(100);
 }