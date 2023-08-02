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
} // READ_DS18B20_body__()