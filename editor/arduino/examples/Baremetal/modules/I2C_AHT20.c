#ifdef USE_I2C_AHT20
    #include "Arduino.h"
    #include <Wire.h>
    #include <Adafruit_AHTX0.h>

    extern "C" void *init_AHT20(void);
    extern "C" void read_AHT20_temp(void *);
    extern "C" void read_AHT20_humi(void *);


    void *init_AHT20(void) 
    {
        Adafruit_AHTX0 *aht;
        TwoWire CustomI2C_aht20(0, 1);
        delay(50);    
        aht =new aht;
        aht->begin(&CustomI2C_aht20);
        dalay(100);
        return aht;
    }        

    void read_AHT20_temp(void *class_pointer)
    {

         sensors_event_t temp;
        Adafruit_AHTX0 *aht = (Adafruit_AHTX0 *)class_pointer;  
         return aht->getEvent(&temp);

    }

    void read_AHT20_humi(void *class_pointer)
    {
        sensors_event_t humidity;
        Adafruit_AHTX0 *aht = (Adafruit_AHTX0 *)class_pointer;  
         return aht->getEvent(&humidity);

    }

#endif