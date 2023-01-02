#ifndef LCD__H
#define LCD__H

#include <xc.h> 
#define _XTAL_FREQ          4000000
#define RS                  RD3
#define EN                  RD2
#define D4                  RD4
#define D5                  RD5
#define D6                  RD6
#define D7                  RD7

/*********************************************************************************
 *                 -----[ Sending Data To The LCD ]-----                         *
 * we need now is a routine to parse out half-a-byte of data and send these bits *
 * to the corresponding pins of the IO pins associated with LCD Data,            *
 * Here is a simple implementation for such a routine.                           *
 *********************************************************************************/
void SendData (unsigned char data);

/*********************************************************************************
 *                 -----[ Sending Commands To The LCD ]-----                     *
 * For our case, using a 4-Bit interface, sending an 8-Bit command will be       *
 * done in 2 exact steps. Hence, we will be using the same routine but twice     *
 * instead of once.                                                              *
 *********************************************************************************/
void SendCmd (unsigned char cmd);

/*********************************************************************************
 *                 -----[ Initializing The LCD Module ]-----                     *
 * Now, it?s time to create the LCD initialization routine. This function        *
 * is an exact implementation of the steps                                       *
 * we've discussed earlier in this tutorial. The 4-Bit interface initialization  *
 * steps are indicated in a previous flow chart and our task right now is        *
 * to implement it in C.                                                         *
 *********************************************************************************/
void LCDInit (void);

/*********************************************************************************
 *                 -----[ Writing A Character To The LCD ]-----                  *
 * Sending an 8-Bit character to the LCD followed by an enable pulse (clock)     *
 * will display that character on the LCD. However, in our case of using         *                                     *
 * a 4-Bit interface, this step will be divided into two consequent steps.       *
 * First of which is parsing the 8-Bit character into a high_nibble and          *
 * low_nibble. Then we?ll send the high4 bits first followed by an EN clock,     *
 * then we?ll send the low4 bits followed by another EN clock. And that?s it!    *
 *********************************************************************************/
void LCDWriteChr (unsigned char chr);

/*********************************************************************************
 *                 -----[ Writing Text To The LCD ]-----                         *
 * To send a string to the LCD, we?ll need a loop to repeatedly send characters  *
 * to the LCD until a buffer end is found, and typically it?s                    *                                     *
 * the NULL character ?\0?. Here is the implementation of this routine.          *
 *********************************************************************************/
void LCDWritestr (char *c);

/*********************************************************************************
 *                 -----[ LCD Clear ]-----                                       *
 * Clear all Characters from LCD                                                 *
 *********************************************************************************/
void LCDClr (void);

/*********************************************************************************
 *                 -----[ Set LCD Cursor Position ]-----                         *
 * Set LCD Cursor Position                                                       *
 *********************************************************************************/
void LCDSetCursor (unsigned char row , unsigned char colomn);

/*********************************************************************************
 *                 -----[ Set LCD Cursor Blanking ]-----                         *
 * Set LCD Cursor Position                                                       *
 *********************************************************************************/
void Cursor_Blink(void);

/*********************************************************************************
 *                 -----[ Shift Entire Display Right ]-----                      *
 * Shift Entire Display Right                                                    *
 *********************************************************************************/
void LCD_SR(void);

/*********************************************************************************
 *                 -----[ Shift Entire Display Left ]-----                       *
 * Shift Entire Display Left                                                     *
 *********************************************************************************/
void LCD_SL(void);

/*********************************************************************************
 *                 -----[ Integer to ASCII ]-----                                *
 * Convert the the Integer Value to it's equivalent ASCII                        *
 *********************************************************************************/
char *itoa(int); 
#endif

