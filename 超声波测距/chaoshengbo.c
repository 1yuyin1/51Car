#include <REGX52.H>
#include "car.h"
#include "delay.h"
#include "Intrins.h"
sbit Trig=P2^1;
sbit Echo=P2^0;
sbit OUT1 = P3^4;	//������
sbit OUT2 = P3^5;	//������
int flag;
float dist;
void Timer2_init()
{

    TMOD|= 0x01;//��ʱ��2������ʽ1
    TH2=0x00;
    TL2=0x00;
    ET2=1;
    EA=1;
}

float chaoshengbo (int y)  //������������
{
    float dist;
    Trig=1;       //�����ź��Ǹߵ�ƽ���壬��ȴ���10us
    delayus(10);
    Trig=0;
    while(!Echo); //�ȴ��ߵ�ƽ
    TR2=1;
    while(Echo);  //�ȴ��͵�ƽ
    TR2=0;
    dist=TH2*256+TL2;//ȡ����ʱ��ֵ��8λ�͵�8λ�ϲ�
    dist/=58;
    TH2=0;
    TL2=0;        //�����ʱ��0�Ĵ����е�ֵ
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
                 ��ʱ���ж��ӳ���
------------------------------------------------*/
void Timer2_Routine() interrupt 5
{
    Echo=0;
}

