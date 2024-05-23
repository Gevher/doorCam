#include <WiFi.h>
#include <SPI.h>

#define SS_PIN 5

void SPI_Init();
uint8_t SPI_Recive();
uint8_t SPI_Send();

void setup() {
  // put your setup code here, to run once:
  char* ssid = "tech_2ghz";
  char* password = "Bielska143/15!";
  
  Serial.begin(115200);
  SPI_Init();
  WiFi.begin(ssid, password);
  pinMode(21, OUTPUT);
  
}

void loop() {
  delay(1000);
  if(SPI_Recive){
    digitalWrite(21, HIGH);
  }
  else{
    digitalWrite(21, LOW);
  }
}

void SPI_Init(){
    SPI.begin(); // Initialize SPI
    pinMode(SS_PIN, OUTPUT);
    digitalWrite(SS_PIN, HIGH);
}

uint8_t SPI_Recive() {
  uint8_t idataReceived = 0;

  digitalWrite(SS_PIN, LOW); // Enable slave
  idataReceived = SPI.transfer(0x00); // Send dummy byte to receive data
  digitalWrite(SS_PIN, HIGH); // Disable slave
  return idataReceived;
}

uint8_t SPI_Send(){

}