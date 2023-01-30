       /* 停    止【四电机停止】           {0)   */
      /* 向前直行【四电机正转】            {1}  */
     /* 向后直行【四电机反转】            {2}  */
    /* 向前左拐【右电机正转，左电机停止】  {3}  */
   /* 向前右拐【右电机停止，左电机正转】  {4} */
  /* 向后左拐【右电机反转，左电机停止】  {5} */
 /* 向后右拐【右电机停止，左电机反转】 {6} */
/************小车移动方向*************/
#include<reg52.h>
#include "delay.h"
sbit IN1=P2^7;

sbit IN2=P2^6;

sbit IN3=P2^5;

sbit IN4=P2^4;




void car_go(int x)
{
    IN1=1;
    IN2=0;
    IN3=1;
    IN4=0;
    delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);
}
void car_back(int x)
{
    IN1=0;
    IN2=1;
    IN3=0;
    IN4=1;
delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);
}
void car_stop(int x)
{
   IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);
}
void car_left(int x)
{    IN1=0;
    IN2=1;
    IN3=1;
    IN4=0;
delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);
}
void car_right(int x)
{  
    IN1=1;
    IN2=0;
    IN3=0;
    IN4=1;
delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);

}
void car_leftback(int x)
{ 
   IN1=0;
    IN2=0;
    IN3=0;
    IN4=1;
delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);
}
void car_rightback(int x)
{
    IN1=0;
    IN2=1;
    IN3=0;
    IN4=0;
   delayms(x);
    IN1=0;
    IN2=0;
    IN3=0;
    IN4=0;
    delayms(100-x);
}

