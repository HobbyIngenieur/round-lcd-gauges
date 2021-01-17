#define TFT_RST       3  // frei gewählt
#define TFT_DC        1  // frei gewählt
#define TFT_CS        22 // frei gewählt

//SDA am Display = SPI_MOSI am ESP32, GPIO23
//SCL am Display = SPI_CLK  am ESP32, GPIO18

#define USE_HORIZONTAL 2  // Set the display direction 0,1,2,3 four directions

void InitTftHardware (void);
void GC9A01_Initial (void);
void Write_Cmd_Data (unsigned char);
void Write_Cmd (unsigned char);
void Write_Data (unsigned char DH, unsigned char DL);
void Write_Data_U16 (unsigned int y);
void LCD_SetPos (unsigned int Xstart, unsigned int Ystart, unsigned int Xend, unsigned int Yend);
void delayms (unsigned int tt);
