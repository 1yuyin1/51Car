#include <REGX52.H>
#include "car.h"
#include "delay.h"
#include "Intrins.h"
sbit Trig=P2^1;
sbit Echo=P2^0;
sbit OUT1 = P3^4;	//避障左
sbit OUT2 = P3^5;	//避障右
int flag;
float dist;
void Timer2_init()
{

    TMOD|= 0x01;//定时器2工作方式1
    TH2=0x00;
    TL2=0x00;
    ET2=1;
    EA=1;
}

float chaoshengbo (int y)  //超声波测距程序
{
    float dist;
    Trig=1;       //触发信号是高电平脉冲，宽度大于10us
    delayus(10);
    Trig=0;
    while(!Echo); //等待高电平
    TR2=1;
    while(Echo);  //等待低电平
    TR2=0;
    dist=TH2*256+TL2;//取出定时器值高8位和低8位合并
    dist/=58;
    TH2=0;
    TL2=0;        //清除定时器0寄存器中的值
  if(flag==1){
      if(OUT1 == 1 && OUT2 == 0)
    {
        car_right(y);
    }
    else if(OUT1==0&&OUT2==1)
    {
        car_left(y);
    }
    else if(dist>3)
    {
        car_go(y);

    }
    else if(dist>=2&&dist<=3)
    {
        car_stop(y);

    }
    else if(dist<2)
    {
        car_back(y);
    }
  }
    return dist;
}

void zs(int x)
{ flag=1;
  while(1)
    {
        chaoshengbo(x);
    }
}
/*------------------------------------------------
                 定时器中断子程序
------------------------------------------------*/
void Timer2_Routine() interrupt 5
{
    Echo=0;
}

