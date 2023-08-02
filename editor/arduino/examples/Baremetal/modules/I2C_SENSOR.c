
#include <stdlib.h>
#include "Arduino.h"
#include "Wire.h"


#define OK 0
#define ERROR -1

extern "C" int I2C_SENSOR_Init(int);

int I2C_SENSOR_Init(int){

}



#ifdef USE_OLED_BLOCK
    
    #include <string.h>
    #include <SPI.h>
    #include <Wire.h>
    #include <Adafruit_GFX.h>
    #include <Adafruit_SSD1306.h>

    extern "C" void *init_oled(uint8_t);
    extern "C" void write_oled(void *,char *,char *,char *,char *);
    int8_t oled_toggle;
    char buffer[22];

    char* str2chr(String S){
        if(S.length()!=0){
            char *p = const_cast<char*>(S.c_str());
            return p;
        }
    }
    void substring(char s[], char sub[], int p, int l) {
    int c = 0;
    
    while (c < l) {
        sub[c] = s[p+c-1];
        c++;
    }
    sub[c] = '\0';
    }

    // if pin is 0 then use default I2C
    void *init_oled(uint8_t pin) 
    {
        oled_toggle = 0;

        Adafruit_SSD1306 *oled; 
        TwoWire CustomI2C0(0, 1);
        delay(50);   
        oled = new Adafruit_SSD1306(128, 32, &CustomI2C0);        
        oled->begin(0x3c);     
        oled->display();       
        delay(2000); 
        oled->clearDisplay();
        oled->setTextSize(1);      // Normal 1:1 pixel scale   
        oled->setTextColor(SSD1306_WHITE);             
        oled->setCursor(0, 0);
        oled->println("Ready.");         
        oled->display();         
        delay(100);         
        return oled;             
    }
   
    void write_oled(void *class_pointer, char * line1,char * line2,char * line3,char * line4)
    {            
        
        Adafruit_SSD1306 *oled = (Adafruit_SSD1306 *)class_pointer;  

         //once every 200ms. PLC loop is 50ms
        if (oled_toggle++ < 4) return; oled_toggle = 0;
        
        /* OLED is 128x32 or 128x64, font is a 6x8
           this limits the text to 21 characters on either display
        */
        oled->clearDisplay();          
        oled->setTextColor(SSD1306_WHITE); // Draw white text         
        oled->setCursor(0, 0);
        buffer[0] = '\0';
        
        if (strlen(line1) > 21) 
        {   memcpy(buffer,line1,21);
            buffer[21] = '\0';
        } else if (strlen(line1) > 1) strcpy(buffer,line1);  
        oled->println(F(buffer)); 
        
        if (strlen(line2) > 21) 
        {   memcpy(buffer,line2,21);
            buffer[21] = '\0';
        } else if (strlen(line1) > 1) strcpy(buffer,line2);  
        oled->println(F(buffer)); 

        if (strlen(line3) > 21) 
        {   memcpy(buffer,line3,21);
            buffer[21] = '\0';
        } else if (strlen(line1) > 1) strcpy(buffer,line3);  
        oled->println(F(buffer)); 

        if (strlen(line4) > 21) 
        {   memcpy(buffer,line4,21);
            buffer[21] = '\0';
        } else if (strlen(line1) > 1) strcpy(buffer,line4);  
        oled->println(F(buffer)); 
        oled->display(); 
        return;
    }

#endif
