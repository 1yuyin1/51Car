       /* ͣ    ֹ���ĵ��ֹͣ��           {0)   */
      /* ��ǰֱ�С��ĵ����ת��            {1}  */
     /* ���ֱ�С��ĵ����ת��            {2}  */
    /* ��ǰ��ա��ҵ����ת������ֹͣ��  {3}  */
   /* ��ǰ�ҹա��ҵ��ֹͣ��������ת��  {4} */
  /* �����ա��ҵ����ת������ֹͣ��  {5} */
 /* ����ҹա��ҵ��ֹͣ��������ת�� {6} */
/************С���ƶ�����*************/
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

