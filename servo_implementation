#include <xc.h>
#include "servo_implement.h"

void TMR1_Init (void)
{
  TMR1 = PreLoad;
  // Choose the local clock source (timer mode)
  TMR1CS = 0;
  // Choose the desired prescaler ratio (1:1)
  T1CKPS0 = 0;
  T1CKPS1 = 0;
  // Switch ON Timer1 Module!
  TMR1ON = 1;
  // -- [[ Interrupts Configurations ]] --
  TMR1IE = 1; // Timer1 Interrupt Enable Bit
  PEIE = 1;   // Peripherals Interrupts Enable Bit
  GIE = 1;    // Global Interrupts Enable Bit
}

void CCP2_Compare_Init(void)
{
    RB1 = 0;
    CCP2CON = 0x09;  // Compare Mode & Clear CCP Pin On Match!
    CCP2IE = 1;
    CCPR2 = PreLoad;
}

void Servo_Init()
{
    TMR1_Init();
    CCP2_Compare_Init();
}

void PWM1_16Bit_DC (unsigned short DC)
{
        CCPR2 = DC;
}

void Servo_MoveTo (unsigned short Range) 
{
   // Angle is ranging from 0 upto 180 
   //unsigned short DC = (Range * 5.555555556) + 46535;  // for 5% and 10%
   unsigned short DC = (Range * 10) + 46135;   // For SG90
   PWM1_16Bit_DC(DC);
}

void servo_write ( unsigned short new_angle ,unsigned short last_angle)
{
 if (last_angle > new_angle)
 {
   for (unsigned short i = last_angle; i > new_angle; i--)
  {
      Servo_MoveTo (i);
      __delay_ms(8);
  }  
 }
 else if (new_angle > last_angle)
 {
 for (unsigned short i = last_angle; i < new_angle; i++)
  {
      Servo_MoveTo (i);
      __delay_ms(8);
  }
 }
 else
    Servo_MoveTo (0);  
}
