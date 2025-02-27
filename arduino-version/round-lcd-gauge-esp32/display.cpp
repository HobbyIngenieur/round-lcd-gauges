#include "Arduino.h"
#include <SPI.h>
#include "display.h"

//SPISettings settings(32000000, BitOrder::MSBFIRST, SPI_MODE0);
SPISettings settings(80000000, SPI_MSBFIRST, SPI_MODE0);

void InitTftHardware (void)
{
  pinMode (TFT_RST, OUTPUT);
  pinMode (TFT_DC, OUTPUT);
  pinMode (TFT_CS, OUTPUT);
  SPI.begin ();
  delay (50);
}


void  Write_Cmd_Data (unsigned char CMDP)
{
  digitalWrite (TFT_CS, 0);
  digitalWrite (TFT_DC, 1);
  SPI.beginTransaction(settings);
  SPI.transfer(CMDP);
  SPI.endTransaction();
  digitalWrite (TFT_CS, 1);
}


void Write_Cmd (unsigned char CMD)
{
  digitalWrite (TFT_CS, 0);
  digitalWrite (TFT_DC, 0);
  SPI.beginTransaction(settings);
  SPI.transfer(CMD);
  SPI.endTransaction();
  digitalWrite (TFT_CS, 1);
}


void Write_Data_U16 (unsigned int y)
{
  unsigned char m,n;
  m=y>>8;
  n=y;
  Write_Data(m,n);
}


void Write_Data (unsigned char DH,unsigned char DL)
{
  digitalWrite (TFT_CS, 0);
  digitalWrite (TFT_DC, 1);
  SPI.beginTransaction(settings);
  SPI.transfer(DH);
  SPI.transfer(DL);
  SPI.endTransaction();
  digitalWrite (TFT_CS, 1);
}


void delayms (unsigned int count)
{
  delay (count);
}


void GC9A01_Initial(void)
{ 
  digitalWrite (TFT_CS, 1);
  delayms(5);
  digitalWrite (TFT_RST, 0);
  delayms(10);
  digitalWrite (TFT_RST, 1);
  delayms(120);  
  
  
  Write_Cmd(0xEF);
  
  Write_Cmd(0xEB);
  Write_Cmd_Data(0x14); 
  
  Write_Cmd(0xFE);       
  Write_Cmd(0xEF); 
  
  Write_Cmd(0xEB);  
  Write_Cmd_Data(0x14); 
  
  Write_Cmd(0x84);      
  Write_Cmd_Data(0x40); 
  
  Write_Cmd(0x85);      
  Write_Cmd_Data(0xFF); 
  
  Write_Cmd(0x86);      
  Write_Cmd_Data(0xFF); 
  
  Write_Cmd(0x87);      
  Write_Cmd_Data(0xFF);
  
  Write_Cmd(0x88);      
  Write_Cmd_Data(0x0A);
  
  Write_Cmd(0x89);      
  Write_Cmd_Data(0x21); 
  
  Write_Cmd(0x8A);      
  Write_Cmd_Data(0x00); 
  
  Write_Cmd(0x8B);      
  Write_Cmd_Data(0x80); 
  
  Write_Cmd(0x8C);      
  Write_Cmd_Data(0x01); 
  
  Write_Cmd(0x8D);      
  Write_Cmd_Data(0x01); 
  
  Write_Cmd(0x8E);      
  Write_Cmd_Data(0xFF); 
  
  Write_Cmd(0x8F);      
  Write_Cmd_Data(0xFF); 
  
  Write_Cmd(0xB6);
  Write_Cmd_Data(0x00);       
  Write_Cmd_Data(0x00); 
  
  Write_Cmd(0x36);
  
  if(USE_HORIZONTAL==0)Write_Cmd_Data(0x18);
  else if(USE_HORIZONTAL==1)Write_Cmd_Data(0x28);
  else if(USE_HORIZONTAL==2)Write_Cmd_Data(0x48);
  else Write_Cmd_Data(0x88);
  
  Write_Cmd(0x3A);      
  Write_Cmd_Data(0x05); 
    
  Write_Cmd(0x90);      
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x08); 
  
  Write_Cmd(0xBD);      
  Write_Cmd_Data(0x06);
  
  Write_Cmd(0xBC);      
  Write_Cmd_Data(0x00); 
  
  Write_Cmd(0xFF);      
  Write_Cmd_Data(0x60);
  Write_Cmd_Data(0x01);
  Write_Cmd_Data(0x04);
  
  Write_Cmd(0xC3);      
  Write_Cmd_Data(0x13);
  Write_Cmd(0xC4);      
  Write_Cmd_Data(0x13);
  
  Write_Cmd(0xC9);      
  Write_Cmd_Data(0x22);
  
  Write_Cmd(0xBE);      
  Write_Cmd_Data(0x11); 
  
  Write_Cmd(0xE1);      
  Write_Cmd_Data(0x10);
  Write_Cmd_Data(0x0E);
  
  Write_Cmd(0xDF);      
  Write_Cmd_Data(0x21);
  Write_Cmd_Data(0x0c);
  Write_Cmd_Data(0x02);
  
  Write_Cmd(0xF0);   
  Write_Cmd_Data(0x45);
  Write_Cmd_Data(0x09);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x26);
  Write_Cmd_Data(0x2A);
  
  Write_Cmd(0xF1);    
  Write_Cmd_Data(0x43);
  Write_Cmd_Data(0x70);
  Write_Cmd_Data(0x72);
  Write_Cmd_Data(0x36);
  Write_Cmd_Data(0x37);  
  Write_Cmd_Data(0x6F);
  
  Write_Cmd(0xF2);   
  Write_Cmd_Data(0x45);
  Write_Cmd_Data(0x09);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x26);
  Write_Cmd_Data(0x2A);
  
  Write_Cmd(0xF3);   
  Write_Cmd_Data(0x43);
  Write_Cmd_Data(0x70);
  Write_Cmd_Data(0x72);
  Write_Cmd_Data(0x36);
  Write_Cmd_Data(0x37); 
  Write_Cmd_Data(0x6F);
  
  Write_Cmd(0xED);  
  Write_Cmd_Data(0x1B); 
  Write_Cmd_Data(0x0B); 
  
  Write_Cmd(0xAE);      
  Write_Cmd_Data(0x77);
  
  Write_Cmd(0xCD);      
  Write_Cmd_Data(0x63);   
  
  Write_Cmd(0x70);      
  Write_Cmd_Data(0x07);
  Write_Cmd_Data(0x07);
  Write_Cmd_Data(0x04);
  Write_Cmd_Data(0x0E); 
  Write_Cmd_Data(0x0F); 
  Write_Cmd_Data(0x09);
  Write_Cmd_Data(0x07);
  Write_Cmd_Data(0x08);
  Write_Cmd_Data(0x03);
  
  Write_Cmd(0xE8);      
  Write_Cmd_Data(0x34);
  
  Write_Cmd(0x62);      
  Write_Cmd_Data(0x18);
  Write_Cmd_Data(0x0D);
  Write_Cmd_Data(0x71);
  Write_Cmd_Data(0xED);
  Write_Cmd_Data(0x70); 
  Write_Cmd_Data(0x70);
  Write_Cmd_Data(0x18);
  Write_Cmd_Data(0x0F);
  Write_Cmd_Data(0x71);
  Write_Cmd_Data(0xEF);
  Write_Cmd_Data(0x70); 
  Write_Cmd_Data(0x70);
  
  Write_Cmd(0x63);      
  Write_Cmd_Data(0x18);
  Write_Cmd_Data(0x11);
  Write_Cmd_Data(0x71);
  Write_Cmd_Data(0xF1);
  Write_Cmd_Data(0x70); 
  Write_Cmd_Data(0x70);
  Write_Cmd_Data(0x18);
  Write_Cmd_Data(0x13);
  Write_Cmd_Data(0x71);
  Write_Cmd_Data(0xF3);
  Write_Cmd_Data(0x70); 
  Write_Cmd_Data(0x70);
  
  Write_Cmd(0x64);      
  Write_Cmd_Data(0x28);
  Write_Cmd_Data(0x29);
  Write_Cmd_Data(0xF1);
  Write_Cmd_Data(0x01);
  Write_Cmd_Data(0xF1);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x07);
  
  Write_Cmd(0x66);      
  Write_Cmd_Data(0x3C);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0xCD);
  Write_Cmd_Data(0x67);
  Write_Cmd_Data(0x45);
  Write_Cmd_Data(0x45);
  Write_Cmd_Data(0x10);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x00);
  
  Write_Cmd(0x67);      
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x3C);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x00);
  Write_Cmd_Data(0x01);
  Write_Cmd_Data(0x54);
  Write_Cmd_Data(0x10);
  Write_Cmd_Data(0x32);
  Write_Cmd_Data(0x98);
  
  Write_Cmd(0x74);      
  Write_Cmd_Data(0x10); 
  Write_Cmd_Data(0x85); 
  Write_Cmd_Data(0x80);
  Write_Cmd_Data(0x00); 
  Write_Cmd_Data(0x00); 
  Write_Cmd_Data(0x4E);
  Write_Cmd_Data(0x00);         
  
  Write_Cmd(0x98);      
  Write_Cmd_Data(0x3e);
  Write_Cmd_Data(0x07);
  
  Write_Cmd(0x35);  
  Write_Cmd(0x21);
  
  Write_Cmd(0x11);
  delayms(120);
  Write_Cmd(0x29);
  delayms(20);
}


void LCD_SetPos (unsigned int Xstart,unsigned int Ystart,unsigned int Xend,unsigned int Yend)
{
  Write_Cmd(0x2a);   
  Write_Cmd_Data(Xstart>>8);
  Write_Cmd_Data(Xstart);
  Write_Cmd_Data(Xend>>8);
  Write_Cmd_Data(Xend);

  Write_Cmd(0x2b);   
  Write_Cmd_Data(Ystart>>8);
  Write_Cmd_Data(Ystart);
  Write_Cmd_Data(Yend>>8);
  Write_Cmd_Data(Yend);
  
  Write_Cmd(0x2c);//LCD_WriteCMD(GRAMWR);
}
