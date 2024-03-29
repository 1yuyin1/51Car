#include <regx51.h>
 #include <intrins.h>
sbit PWM=P3^0;  //定义给舵机信号线接的I/O口
 
void Delay(unsigned char i)   //12MHz 延时函数  
{
    unsigned char a,b;        //该段延时函数Delay(1)=0.5ms
    for(;i>0;i--)
      for(b=71;b>0;b--)
        for(a=2;a>0;a--);
}
void delayms(int t)		//@11.0592MHz
{   while(t--) {
        unsigned char i, j;

        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j);
        } while (--i);
    }
}
/****************************************************************
                            总周期20ms
                通过调� 9    9谡伎毡仁迪侄婊枰慕嵌�
舵机代码用定时器控制更方便稳定，本文方便读者了解使用，使用延时计算
                         其功能可正常使用
*****************************************************************/
void zero(void) //0度 子程序
{   
        PWM=1;
        Delay(1);       //高电平 Delay(1)=0.5ms。因为周期为20ms，所以低电平就是19.5ms 
        PWM=0;
        Delay(39);      //低电平 Delay(39)=19.5ms
}
 
void one(void) //45度 子程序
{
        PWM=1;
        Delay(2);      //高电平  Delay(2)=1ms
        PWM=0;   
        Delay(38);     //低电平  Delay(38)=19ms
}
 
void two(void)  //90度 子程序
{
         PWM=1;
        Delay(3);       //高电平 Delay(3)=1.5ms
        PWM=0;
        Delay(37);     //低电平  18.5ms
}
 
void three(void) //135度 子程序
{
        PWM=1;
        Delay(4);       //高电平 Delay(4)=2ms
        PWM=0;
        Delay(36);      //低电平 18ms
}
 
void four(void) //180度 子程序
{
        PWM=1;
        Delay(5);      //高电平 Delay(5)=2.5ms
        PWM=0;
        Delay(35);     //低电平 17.5ms
}
 
 
void main()  //主程序
{

two();
delayms(500);
three();
delayms(500);
two();
delayms(500);
one();
delayms(500);




}
 
//end