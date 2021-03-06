#include <SPI.h>

#include <RadioHead.h>
#include <RHCRC.h>
#include <RHDatagram.h>
#include <RHEncryptedDriver.h>
#include <RHGenericDriver.h>
#include <RHGenericSPI.h>
#include <RHHardwareSPI.h>
#include <RHMesh.h>
#include <RHNRFSPIDriver.h>
#include <RHReliableDatagram.h>
#include <RHRouter.h>
#include <RHSoftwareSPI.h>
#include <RHSPIDriver.h>
#include <RHTcpProtocol.h>
#include <RH_ASK.h>
#include <RH_CC110.h>
#include <RH_E32.h>
#include <RH_MRF89.h>
#include <RH_NRF24.h>
#include <RH_NRF51.h>
#include <RH_NRF905.h>
#include <RH_RF22.h>
#include <RH_RF24.h>
#include <RH_RF69.h>
#include <RH_RF95.h>
#include <RH_Serial.h>
#include <RH_TCP.h>
#include <LiquidCrystal.h>
RH_ASK driver;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define rfReceivePin A0  //RF Receiver pin = Analog pin 0
void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");

           lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("STRIKE 123456789");
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      lcd.setCursor(7,1);
      lcd.print("X");
      int i;
      // Message with a good checksum received, dump it.
     
      Serial.print("Message: ");
      Serial.println((char*)buf);         
    }
     Serial.print("Message: ");
      Serial.println((char*)buf);     
}
