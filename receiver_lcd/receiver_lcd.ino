

#include <LiquidCrystal.h>

#include <VirtualWire.h>

#include <Wire.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Set the LCD I2C address
#define rx 2
int i;
void setup()
{
    Serial.begin(9600);  // Debugging only
     lcd.begin(16,2); 
    lcd.print("setup");

    // Initialise the IO and ISR
    //vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(4800);  // Bits per sec

    vw_rx_start();
    vw_set_rx_pin(2);// Start the receiver PLL running
    lcd.clear();       
}

void loop()
{
    
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      lcd.print((char *)buf);
      lcd.write(buf[3]);
      lcd.setCursor(0,1);
      lcd.print("X");//was char *
      delay(5000); //was 5000
      lcd.clear();
    }
   else if (!vw_get_message(buf, &buflen))
   {
     lcd.print("Out of range.");
     delay(5000);
     lcd.clear();
   }
}

