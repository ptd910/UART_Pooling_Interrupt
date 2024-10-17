#include<iostream>
#include<SoftwareSerial.h>
using namespace std;
#define RX_PIN D7
#define TX_PIN D8
SoftwareSerial stm32Serial(D7, D8); // RX, TX
String response = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  stm32Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if(stm32Serial.available()>0)
  // {
  //   response= stm32Serial.readStringUntil('\n');
  //   Serial.println(response);
  // }
   // Check if data is available on the Serial Monitor (USB)
  if (Serial.available() > 0) {
    // Read the incoming string from the Serial Monitor
    response = Serial.readStringUntil('\n');  // Read until newline character
    
    // Send the received string to STM32 via SoftwareSerial
    stm32Serial.print(response);
    
    // Print the string back to Serial Monitor for confirmation
    Serial.println("Sent to STM32: " + response);
    
    // Prompt for more input
    Serial.println("Enter another string to send:");
  }
  response="";

  // Optionally, handle incoming data from the STM32
  if (stm32Serial.available() > 0) {
    String stmResponse = stm32Serial.readStringUntil('\n');
    Serial.println("Received from STM32: " + stmResponse);
  }
}

