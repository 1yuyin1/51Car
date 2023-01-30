#include "car.h"
#include "chaoshengbo.h"
#include "oled.h"
#include "oledrfront.h"
#include "delay.h"


int speed;//�ٶ�
void UsartInit()//���ڶ�ʱ��  //9600bps@11.0592MHz
{
    PCON=0x00;    //�ر�Ƶ
    SCON = 0x50;		//8λ����,�ɱ䲨����
    TMOD = 0x20;		//���ö�ʱ��ģʽ
    TL1 = 0xFd;		//���ö�ʱ��ʼֵ
    TH1 = 0xFd;		//���ö�ʱ��ʼֵ
    ET1 = 0;		//��ֹ��ʱ��1�ж�
    TR1 = 1;		//��ʱ��1��ʼ��ʱ
    EA=1;  //���ж�
    ES=1;  //�򿪴����ж�
}

void xianshi()
{   float dis;
    OLED_ShowCHinese(0,0,3);//��	//��һ���β����У��ڶ������У�����������ʾ�ĸ����ģ�����һ����ռ16��
    OLED_ShowCHinese(18,0,4);//��
    OLED_ShowCHinese(0,2,5);//ģ
    OLED_ShowCHinese(18,2,6);//ʽ
    OLED_ShowCHinese(44,2,12);//��
    OLED_ShowCHinese(62,2,13);//��
    OLED_ShowCHinese(0,4,13);//��
    OLED_ShowCHinese(18,4,14);//��
    //���������ʾ�ַ�
    OLED_ShowString(36,0,":",16);//��һ���βα�ʾ�����У��ڶ����βα�ʾ�ţ���������ʾд����ַ������ĸ���ʾ�����С
    OLED_ShowString(36,2,":",16);
    OLED_ShowString(36,4,":",16);
    OLED_ShowString(68,4,"cm",16);
    //���������ʾ����
    dis=chaoshengbo(speed);
    OLED_ShowNum(44,4,dis,3,16);		//��һ��������ʾ�У��ڶ���������ʾ�У�������������ʾ�������֣����ĸ�������ʾ��ʾ���ֵ�λ���������������ʾ�����С
}



void main ()
{   UsartInit();
    Timer2_init();
    OLED_Init();			//��ʼ��OLED
    OLED_Clear(); 		//��������
    while(1) {
        xianshi();
    }
}
void Usart() interrupt 4    //�����ж�
{
    unsigned char receiveData;
    receiveData=SBUF;//���յ�������
    RI = 0;//��������жϱ�־λ
    switch(receiveData)//��������ִ�в���
    {
    /***********************�ٶ��л�******************************/
    case 'a':
        OLED_ShowCHinese(44,0,0);//һ
        speed=30;
        break;
    case 'b':
        OLED_ShowCHinese(44,0,1);//��
        speed=60;
        break;
    case 'c':
        OLED_ShowCHinese(44,0,2);//��
        speed=90;
        break;
    /***********************ģʽ�л�******************************/
    case'f':
            OLED_ShowCHinese(44,2,16);//��
        OLED_ShowCHinese(62,2,17);//��
        zs(speed);   //���ø���
        break;
    /***********************�����л�******************************/
    case '0':
        car_stop(speed);
        break;
    case '1':
        car_go(speed);
        break;
    case '2':
        car_back(speed);
        break;
    case '3':
        car_left(speed);
        break;
    case '4':
        car_right(speed);
        break;
    case '5':
        car_leftback(speed);
        break;
    case '6':
        car_rightback(speed);
        break;
    }

    SBUF=receiveData; //�����յ������ݷ��뵽���ͼĴ���
    while(!TI);	     //�ȴ������������
    TI=0;           //���������ɱ�־λ
}

