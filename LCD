#include "lcd.h"

void SendData (unsigned char data)
{ 
    D4 = (data & 1)? 1 : 0;
    D5 = (data & 2)? 1 : 0;
    D6 = (data & 4)? 1 : 0;
    D7 = (data & 8)? 1 : 0;
    __delay_us(50);             // Execution Time for Commands
}

void SendCmd (unsigned char cmd)
{
    RS = 0;
    SendData(cmd);
    EN = 1;
    __delay_us(500);
    EN = 0;
}

void LCDInit (void)
{
    SendCmd(0x00);
    __delay_ms(40);
    SendCmd(0x03);
    __delay_ms(5);
    SendCmd(0x03);
    __delay_us(150);
    SendCmd(0x03);
    SendCmd(0x02);
    SendCmd(0x02);
    SendCmd(0x08);
    SendCmd(0x00);
    SendCmd(0x0C);
    SendCmd(0x00);
    SendCmd(0x06); 
}

void LCDWriteChr (unsigned char chr)
{
    RS = 1;
    SendData(chr >> 4); // High Significant Bits
    EN = 1;
    __delay_us(500);
    EN = 0;
    __delay_us(500);
    SendData(chr & 0x0F);   // Low Significant Bits
    EN = 1;
    __delay_us(500);
    EN = 0;
    __delay_us(500);
}

void LCDWritestr (char *c)
{
    unsigned short i;
    for (i = 0; c[i] != '\0'; i++)
       LCDWriteChr(c[i]); 
}

void LCDClr (void)
{
  SendCmd(0);
  SendCmd(1);  
}

void LCDSetCursor (unsigned char row , unsigned char colomn)
{
  if (row == 1)
  {
    SendCmd( (0x80 + colomn - 1) >> 4 );
    SendCmd( (0x80 + colomn - 1) & 0x0F );
  }
  if (row == 2)
  {
    SendCmd( (0xC0 + colomn - 1) >> 4 );
    SendCmd( (0xC0 + colomn - 1) & 0x0F );
  }
  if (row == 3)
  {
    SendCmd( (0x94 + colomn - 1) >> 4 );
    SendCmd( (0x94 + colomn - 1) & 0x0F );
  }
  if (row == 4)
  {
    SendCmd( (0xD4 + colomn - 1) >> 4 );
    SendCmd( (0xD4 + colomn - 1) & 0x0F );
  }
}

void Cursor_Blink(void)
{
  SendCmd(0x00);
  SendCmd(0x0F);
}

void LCD_SR(void)
{
  SendCmd(0x01);
  SendCmd(0x0C);
}

void LCD_SL(void)
{
  SendCmd(0x01);
  SendCmd(0x08);
}

char *itoa(int value) 
 {
     static char buffer[12];        // 12 bytes is big enough for an INT32
     int original = value;          // save original value
 
     int c = sizeof(buffer) - 1;
 
     buffer[c] = 0;                 // write trailing null in last byte of buffer    
 
     if (value < 0)                 // if it's negative, note that and take the absolute value
         value = -value;
     
     do                             // write least significant digit of value that's left
     {
         buffer[--c] = (value % 10) + '0';    
         value /= 10;
     } while (value);
 
     if (original < 0) 
         buffer[--c] = '-';
 
     return &buffer[c];
 }
