/************************************************************************
 *               DECLARATION OF I2C_SENSOE BLOCKS                      *
************************************************************************/

// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(INT,ADDR_SLAVE)
  __DECLARE_VAR(INT,SCK_PIN)
  __DECLARE_VAR(INT,SDA_PIN)  
  __DECLARE_VAR(REAL,OUT_0)
  __DECLARE_VAR(REAL,OUT_1)
  __DECLARE_VAR(REAL,OUT_2)
  __DECLARE_VAR(REAL,OUT_3)

  // FB private variables - TEMP, private and located variables

} I2C_THREMO_4_OUT;


//READ_AHT20
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(INT,SCK_PIN)
  __DECLARE_VAR(INT,SDA_PIN)  
  __DECLARE_VAR(REAL,TEMP)
  __DECLARE_VAR(REAL,RH)
  // FB private variables - TEMP, private and located variables
} I2C_AHT20;





/************************************************************************
 *                     END OF ARDUINO I2C_SENSOE BLOCKS                 *
************************************************************************/

static void I2C_THREMO_4_OUT_init__(I2C_THREMO_4_OUT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ADDR_SLAVE,0,retain)
  __INIT_VAR(data__->SCK_PIN,0,retain)
  __INIT_VAR(data__->SDA_PIN,0,retain)  
  __INIT_VAR(data__->OUT_0,0.0,retain)
  __INIT_VAR(data__->OUT_1,0.0,retain)
  __INIT_VAR(data__->OUT_2,0.0,retain)
  __INIT_VAR(data__->OUT_3,0.0,retain)
}

static void I2C_AHT20_init__(I2C_AHT20 *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SCK_PIN,0,retain)
  __INIT_VAR(data__->SDA_PIN,0,retain)  
  __INIT_VAR(data__->TEMP,0.0,retain)
  __INIT_VAR(data__->RH,0.0,retain)

}


/************************************************************************
 *                     END OF ARDUINO I2C_SENSOE BLOCKS                 *
************************************************************************/


// Code part
static void I2C_THREMO_4_OUT_body__(I2C_THREMO_4_OUT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Dummy code - just for editor simulation. Real code is inside iec_std_FB.h file on arduino folder
  __SET_VAR(data__->,OUT_0,,0);
  __SET_VAR(data__->,OUT_1,,0);
  __SET_VAR(data__->,OUT_2,,0);
  __SET_VAR(data__->,OUT_3,,0);

  goto __end;

__end:
  return;
} // READ_I2C_THREMO_4_OUT_body__()

// Code part
static void I2C_AHT20_body__(I2C_AHT20 *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Dummy code - just for editor simulation. Real code is inside iec_std_FB.h file on arduino folder
  __SET_VAR(data__->,TEMP,,0);
  __SET_VAR(data__->,RH,,0);
  goto __end;

__end:
  return;
} // READ_DS18B20_body__()



/************************************************************************
 *                     END OF ARDUINO I2C_SENSOE BLOCKS                 *
************************************************************************/

// WRITE_OLED
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,SETUP_BLOCK)
  __DECLARE_VAR(STRING, LINE1) 
  __DECLARE_VAR(STRING, LINE2) 
  __DECLARE_VAR(STRING, LINE3) 
  __DECLARE_VAR(STRING, LINE4) 
  __DECLARE_VAR(BOOL,SUCCESS)

  void *class_pointer;

  // FB private variables - TEMP, private and located variables

} I2C_OLED;


//definition of external functions
void *init_oled(uint8_t);
void write_oled(void *,char *,char *,char *,char *);

//definition of blocks
static void I2C_OLED_init__(I2C_OLED *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SETUP_BLOCK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LINE1,__STRING_LITERAL(1,"\0"),retain)
  __INIT_VAR(data__->LINE2,__STRING_LITERAL(1,"\0"),retain)
  __INIT_VAR(data__->LINE3,__STRING_LITERAL(1,"\0"),retain)
  __INIT_VAR(data__->LINE4,__STRING_LITERAL(1,"\0"),retain)
  __INIT_VAR(data__->SUCCESS,__BOOL_LITERAL(FALSE),retain)
}

// Code part
static void I2C_OLED_body__(I2C_OLED *data__) {

  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  
  // Initialise TEMP variables
  if (!__GET_VAR(data__->SETUP_BLOCK)) {
      (*data__).class_pointer = init_oled(0);
      __SET_VAR(data__->,SETUP_BLOCK,,__BOOL_LITERAL(TRUE));
  }  
 write_oled((*data__).class_pointer,
            __GET_VAR(data__->LINE1).body,
            __GET_VAR(data__->LINE2).body,
            __GET_VAR(data__->LINE3).body,
            __GET_VAR(data__->LINE4).body
            );
            
  goto __end;

__end:
  return;
} // WRITE_OLED_body__()
