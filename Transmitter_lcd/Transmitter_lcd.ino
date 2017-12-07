#include <LiquidCrystal.h>



#include <VirtualWire.h>

#include <Wire.h>


#define txPowerPin 8
char msg[3];
char msg1[3];
void setup()
{
    Serial.begin(9600);    // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
   // vw_set_ptt_inverted(true); // Required for DR3100
    
  pinMode(txPowerPin, OUTPUT);
  pinMode(txPowerPin, LOW);
  vw_setup(4800);     // VirtualWire communication speed
  vw_set_tx_pin(9);
}

void loop()
{
    const char *msg = "X";
    digitalWrite(txPowerPin, HIGH);
 
    strcat(msg, msg1);
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx(); // Wait until the whole message is gone
    
    delay(700);
   digitalWrite(txPowerPin, LOW);
 
   delay(5000); 
  
 
    
}
