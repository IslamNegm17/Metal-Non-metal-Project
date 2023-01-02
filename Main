#include <xc.h>
#include "Configuration Bits.h"
#include "servo_implement.h"
#include "lcd.h"
#include "ultrasonic.h"

void Metal_Field (void);
void non_Metal_Field (void);
short pin_select = 0;
unsigned short dtr;
long distance = 0;
int Proximity_reading = 0;
void main(void) 
{ 
 TRISB = 0x00;
 TRISD = 0x01;
 
 TRISC1 = 1;
 T0CS = 0;         
 PSA = 0;
 
 Servo_Init();
 LCDInit ();
 LCDClr ();
 
 LCDSetCursor (1,1);
 LCDWritestr("Object \0 ");
 
    //-------------------------[Get The Object]----------------------------
    // GRIPPER (UN-HOLDING):-
    pin_select = 5;          
    Servo_MoveTo (70);  
    __delay_ms (1000);
    // BASE :-
    pin_select = 1;          
    Servo_MoveTo (90);  
    __delay_ms (1000);
    
    LCDSetCursor (1,8);
    LCDWritestr("         ");
    distance = CalculateDistance () * 100;
    while (distance > 3 )
    {
      distance = CalculateDistance () * 100;
      LCDSetCursor (1,8);
      LCDWritestr("Not-Found\0");
    }
    __delay_ms (50);
    Proximity_reading = RD0;
    LCDSetCursor (1,8);
    LCDWritestr("         ");
    LCDSetCursor (1,8);
    LCDWritestr("Founded\0");
    if (Proximity_reading == 1)
    {
        LCDSetCursor (2,3);
        LCDWritestr("NON-METAL\0");   
        
    }
    else
    {
        LCDSetCursor (2,5);
        LCDWritestr("METAL\0");
    }    
    
    // ARM 01 :-
    pin_select = 3;          
    Servo_MoveTo (50);  
    __delay_ms (1000);
    // WAIST :-
    pin_select = 2;          
    Servo_MoveTo (160);  
    __delay_ms (1000);
    // GRIPPER (HOLDING):-
    pin_select = 5;          
    Servo_MoveTo (5);  
    __delay_ms (1000);
    
  switch (Proximity_reading)
   {
    case 0:
     {
    //-------------------------[Rise The Object]----------------------------
    // WAIST :-
    pin_select = 2;          
    servo_write (80,160);  
    __delay_ms (1000);
    // ARM 01 :-
    pin_select = 3;          
    servo_write (40,50);  
    __delay_ms (1000);    
    
    non_Metal_Field ();
    dtr = 0;
    break;
     }  
    case 1:
     {
    //-------------------------[Rise The Object]----------------------------
    // WAIST :-
    pin_select = 2;          
    servo_write (80,160);  
    __delay_ms (1000);
    // ARM 01 :-
    pin_select = 3;          
    servo_write (40,50);  
    __delay_ms (1000);
    
    Metal_Field ();
    dtr = 180;
    break;
     }
  } 
    
    
 while (1)
  {
    //-------------------------[Return Home]---------------------------- 
     // WAIST :-
    pin_select = 2;          
    servo_write (80,160);  
    __delay_ms (1000);
     // BASE :-
    pin_select = 1;          
    servo_write (90,dtr);  
    __delay_ms (1000); 
    //-------------------------[Get the Object]---------------------------- 
    pin_select = 0;
    LCDSetCursor (1,8);
    LCDWritestr("         ");
    distance = CalculateDistance () * 100;
    while (distance > 3)
    {
      distance = CalculateDistance () * 100;
      LCDSetCursor (1,8);
      LCDWritestr("Not-Found\0");
    }
    __delay_ms (50);
    Proximity_reading = RD0;
    LCDSetCursor (1,8);
    LCDWritestr("         ");
    LCDSetCursor (1,8);
    LCDWritestr("Founded\0");
    LCDSetCursor (2,3);
    LCDWritestr("          ");
    if (Proximity_reading == 1)
    {
        LCDSetCursor (2,3);
        LCDWritestr("NON-METAL\0");   
        
    }
    else
    {
        LCDSetCursor (2,5);
        LCDWritestr("METAL\0");
    }  
    
    // WAIST :-
    pin_select = 2;          
    servo_write (160,80);  
    __delay_ms (1000);
    // GRIPPER (HOLDING):-
    pin_select = 5;          
    Servo_MoveTo (5);  
    __delay_ms (1000);
    
    switch (Proximity_reading)
   {
    case 0:
     {
    //-------------------------[Rise The Object]----------------------------
    // WAIST :-
    pin_select = 2;          
    servo_write (80,160);  
    __delay_ms (1000);
    // ARM 01 :-
    pin_select = 3;          
    servo_write (50,40);  
    __delay_ms (1000);    
    
    non_Metal_Field ();
    dtr = 0;
    break;
     }
    
    case 1:
     {
    //-------------------------[Rise The Object]----------------------------
    // WAIST :-
    pin_select = 2;          
    servo_write (80,160);  
    __delay_ms (1000);
    // ARM 01 :-
    pin_select = 3;          
    servo_write (50,40);  
    __delay_ms (1000);
    
    Metal_Field ();
    dtr = 180;
    break;
     }
   }
 }
  return;
}
//------------------------------------------------------------------------------------------ 
//------------------------------------------------------------------------------------------
void __interrupt() ISR()
{
  
 if (CCP2IF)
 {    
     switch (pin_select)
     {
         case 1:
         {
           RB0 = 0;
           break;
         }
         case 2:
         {
           RB1 = 0;
           break;
         }
         case 3:
         {
           RB2 = 0;
           break;
         }
         case 4:
         {
           RB3 = 0;
           break;
         }
         case 5:
         {
           RB4 = 0;
           break;
         }
         default:
           break;    
     } 
    CCP2IF = 0;  
 }
 
 if (TMR1IF)
  {
    CCP2CON = 0x00;
    switch (pin_select)
     {
         case 1:
         {
           RB0 = 1;
           break;
         }
         case 2:
         {
           RB1 = 1;
           break;
         }
         case 3:
         {
           RB2 = 1;
           break;
         }
         case 4:
         {
           RB3 = 1;
           break;
         }
         case 5:
         {
           RB4 = 1;
           break;
         }
         default:
           break;   
     } 
    CCP2CON = 0x09;
    TMR1 = 45567;        // 45535 (Preload) + 32 (Interrupt Latency) + 16 (CCP2_ISR)
    TMR1IF = 0;
  }
}

//------------------------------------------------------------------------------------------ 
//------------------------------------------------------------------------------------------
void Metal_Field (void)
{
    __delay_ms (500);
    // BASE :-
    pin_select = 1;          
    servo_write (180,90);  
    __delay_ms (1000);
    // ARM 01 :-
    pin_select = 3;          
    servo_write (50,40);  
    __delay_ms (800);
    // WAIST :-
    pin_select = 2;          
    servo_write (160,80);  
    __delay_ms (1000);
    // GRIPPER (UN-HOLDING):-
    pin_select = 5;          
    Servo_MoveTo (70);  
    __delay_ms (1000);  
}

void non_Metal_Field (void)
{
    __delay_ms (500);
   // BASE :-
    pin_select = 1;          
    servo_write (0,90);  
    __delay_ms (1000);
    // ARM 01 :-
    pin_select = 3;          
    servo_write (50,40);  
    __delay_ms (1000);
    // WAIST :-
    pin_select = 2;          
    servo_write (160,80);  
    __delay_ms (1000);
    // GRIPPER (UN-HOLDING):-
    pin_select = 5;          
    Servo_MoveTo (70);  
    __delay_ms (1000);
}
