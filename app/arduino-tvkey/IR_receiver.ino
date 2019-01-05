/*
 * IRsend: IRRemoteControlDemo - demonstrates receiving/sending IR codes.
 * Created by Cristiano Borges - STI - Fatesg
 * August, 2017
 */

#include "IRRemoteControl.h"

IRRecv irRecv;
IRSend irSend;

const int IR_RECV_PIN = 2;

const int MAX_IR_BUFFER_LENGTH = 650;
unsigned int irBuffer[MAX_IR_BUFFER_LENGTH];
int currentIrBufferLength = -1;

const int FREQ_KHZ = 38;
unsigned long valid_codes[6] = {15, 245, 1805, 795, 600000, 3000};

void setup() {
  Serial.begin(115200);
}



void loop() {
  if (currentIrBufferLength == -1) {
    irRecv.start(IR_RECV_PIN, irBuffer, MAX_IR_BUFFER_LENGTH, currentIrBufferLength);
    currentIrBufferLength = 0;
  }
    
  if (currentIrBufferLength > 0) {
    delay(500);
    irRecv.stop(IR_RECV_PIN);

    if (currentIrBufferLength > 15) {
      Serial.println();
      Serial.println(currentIrBufferLength);
      Serial.print(F("Code: "));
    
      for (int i = 0; i < currentIrBufferLength; i++) {
        if (i > 0) {
          Serial.print(F(", "));
        }
        unsigned long val = irBuffer[i];
        for (int i = 0; i < 6; i++) {
          
          if ((val > valid_codes[i]) && (val - valid_codes[i] < 50)){
            val = valid_codes[i];
            break;
          }
          if ((val < valid_codes[i]) && (valid_codes[i] - val < 50)){
            val = valid_codes[i];
            break;
          }
        }
        Serial.print(val);
      }
      Serial.println();
    }
    
    currentIrBufferLength = -1;
  }
}
