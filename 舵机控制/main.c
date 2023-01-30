#include <regx51.h>
 #include <intrins.h>
sbit PWM=P3^0;  //���������ź��߽ӵ�I/O��
 
void Delay(unsigned char i)   //12MHz ��ʱ����  
{
    unsigned char a,b;        //�ö���ʱ����Delay(1)=0.5ms
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
                            ������20ms
                ͨ����� 9    9�ռ�ձ�ʵ�ֶ����Ҫת���ĽǶ�
��������ö�ʱ�����Ƹ������ȶ������ķ�������˽�ʹ�ã�ʹ����ʱ����
                         �书�ܿ�����ʹ��
*****************************************************************/
void zero(void) //0�� �ӳ���
{   
        PWM=1;
        Delay(1);       //�ߵ�ƽ Delay(1)=0.5ms����Ϊ����Ϊ20ms�����Ե͵�ƽ����19.5ms 
        PWM=0;
        Delay(39);      //�͵�ƽ Delay(39)=19.5ms
}
 
void one(void) //45�� �ӳ���
{
        PWM=1;
        Delay(2);      //�ߵ�ƽ  Delay(2)=1ms
        PWM=0;   
        Delay(38);     //�͵�ƽ  Delay(38)=19ms
}
 
void two(void)  //90�� �ӳ���
{
         PWM=1;
        Delay(3);       //�ߵ�ƽ Delay(3)=1.5ms
        PWM=0;
        Delay(37);     //�͵�ƽ  18.5ms
}
 
void three(void) //135�� �ӳ���
{
        PWM=1;
        Delay(4);       //�ߵ�ƽ Delay(4)=2ms
        PWM=0;
        Delay(36);      //�͵�ƽ 18ms
}
 
void four(void) //180�� �ӳ���
{
        PWM=1;
        Delay(5);      //�ߵ�ƽ Delay(5)=2.5ms
        PWM=0;
        Delay(35);     //�͵�ƽ 17.5ms
}
 
 
void main()  //������
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