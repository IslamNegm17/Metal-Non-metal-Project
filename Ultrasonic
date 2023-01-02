#include "ultrasonic.h"
long dis1 , dis2;
double CalculateDistance (void)
{
   double distance = 0.0f;
   TMR0 = 0;
   TR = 1;
   __delay_us(10);
   TR = 0;
   while (!ECHO);
   dis1 = TMR0;
   while (ECHO);
   dis2 = TMR0;
   //(dis1 > dis2)?(dis2 += dis1):(dis1 = dis1);
   distance = (dis2 - dis1) * 0.01715;
   return distance;
}
