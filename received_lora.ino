#include <SPI.h>
#include <LoRa.h>

String MyMessage = ""; // Holds the complete message

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) { // or 915E6 depending on the frequency
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  
  if (packetSize) { 
    MyMessage = ""; // Очистка сообщения перед приемом нового пакета
    
    // Чтение пакета
    while (LoRa.available()) {
      MyMessage += (char)LoRa.read();
    }
    
    // Вывод сообщения после приема
    Serial.print("Received message: ");
    Serial.println(MyMessage);
    
    // Вывод уровня сигнала
    Serial.print("RSSI: ");
    Serial.println(LoRa.packetRssi());
  }
}