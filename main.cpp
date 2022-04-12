#include "DigitalOut.h"
#include "PinNames.h"
#include "mbed.h"
#include "ThisThread.h"

DigitalOut oled1(LED1);
InterruptIn ibutton1(BUTTON1);
static auto sleep_time = 1000ms;
int b = 0;


Ticker toggle_led_ticker;

void led_ticker()
    {
        oled1 = !oled1;
    } 

 void pressed()
    {   
        if (b < 3) 
            b++;
            else
                b=0;
        
    }

int main()

{
   
    ibutton1.rise(&pressed);
    
    while (true) {
        if (b == 0) {

            oled1 = 1; //вкл светодиода
            ThisThread::sleep_for(1s);
            oled1 = 0;
            ThisThread::sleep_for(1s);
    }
    if (b == 2) {
            oled1 = 1; //вкл светодиода
            ThisThread::sleep_for(5s);
            oled1 = 0;
            ThisThread::sleep_for(5s);
    }
    
    }
}