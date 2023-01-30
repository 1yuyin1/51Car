#include "car.h"
#include "chaoshengbo.h"
#include "oled.h"
#include "oledrfront.h"
#include "delay.h"


int speed;//速度
void UsartInit()//串口定时器  //9600bps@11.0592MHz
{
    PCON=0x00;    //关倍频
    SCON = 0x50;		//8位数据,可变波特率
    TMOD = 0x20;		//设置定时器模式
    TL1 = 0xFd;		//设置定时初始值
    TH1 = 0xFd;		//设置定时初始值
    ET1 = 0;		//禁止定时器1中断
    TR1 = 1;		//定时器1开始计时
    EA=1;  //总中断
    ES=1;  //打开串口中断
}

void xianshi()
{   float dis;
    OLED_ShowCHinese(0,0,3);//速	//第一个形参是列，第二个是行，第三个是显示哪个中文，这里一个字占16宽
    OLED_ShowCHinese(18,0,4);//度
    OLED_ShowCHinese(0,2,5);//模
    OLED_ShowCHinese(18,2,6);//式
    OLED_ShowCHinese(44,2,12);//测
    OLED_ShowCHinese(62,2,13);//距
    OLED_ShowCHinese(0,4,13);//距
    OLED_ShowCHinese(18,4,14);//离
    //这个函数显示字符
    OLED_ShowString(36,0,":",16);//第一个形参表示第六行，第二个形参表示排，第三个表示写入的字符，第四个表示字体大小
    OLED_ShowString(36,2,":",16);
    OLED_ShowString(36,4,":",16);
    OLED_ShowString(68,4,"cm",16);
    //这个函数显示数字
    dis=chaoshengbo(speed);
    OLED_ShowNum(44,4,dis,3,16);		//第一个参数表示列，第二个参数表示行，第三个参数表示变量数字，第四个参数表示显示数字的位数，第五个参数表示字体大小
}



void main ()
{   UsartInit();
    Timer2_init();
    OLED_Init();			//初始化OLED
    OLED_Clear(); 		//清屏函数
    while(1) {
        xianshi();
    }
}
void Usart() interrupt 4    //串口中断
{
    unsigned char receiveData;
    receiveData=SBUF;//接收到的数据
    RI = 0;//清除接收中断标志位
    switch(receiveData)//根据数据执行操作
    {
    /***********************速度切换******************************/
    case 'a':
        OLED_ShowCHinese(44,0,0);//一
        speed=30;
        break;
    case 'b':
        OLED_ShowCHinese(44,0,1);//二
        speed=60;
        break;
    case 'c':
        OLED_ShowCHinese(44,0,2);//三
        speed=90;
        break;
    /***********************模式切换******************************/
    case'f':
            OLED_ShowCHinese(44,2,16);//跟
        OLED_ShowCHinese(62,2,17);//随
        zs(speed);   //调用跟随
        break;
    /***********************方向切换******************************/
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

    SBUF=receiveData; //将接收到的数据放入到发送寄存器
    while(!TI);	     //等待发送数据完成
    TI=0;           //清除发送完成标志位
}

