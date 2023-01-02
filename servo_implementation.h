#ifndef   SERVO_IMPLEMENT_H
#define	SERVO_IMPLEMENT_H

#define _XTAL_FREQ                4000000
#define PreLoad                   45535

void TMR1_Init (void);
void CCP2_Compare_Init(void);
void Servo_Init(void);
void Servo_MoveTo (unsigned short); 
void PWM1_16Bit_DC (unsigned short);
void servo_write (unsigned short , unsigned short);

#endif	
