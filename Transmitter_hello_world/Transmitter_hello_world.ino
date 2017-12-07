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
#include <SPI.h>

RH_ASK driver;
#define laser1 1
#define rfTransmitPin 0  //RF Transmitter pin = digital pin 0
void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init()){
         Serial.println("init failed");
    }
          pinMode(rfTransmitPin, OUTPUT);     
           
          pinMode(laser1, INPUT);
          
}

void loop()
{
  digitalRead(laser1);
    const char *msg = "Hello World!";

    if(laser1, HIGH){
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(1000);
    }
    
}
