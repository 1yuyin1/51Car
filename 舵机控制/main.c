#include <regx51.h>
 #include <intrins.h>
sbit PWM=P3^0;  //¶¨Òå¸ø¶æ»úÐÅºÅÏß½ÓµÄI/O¿Ú
 
void Delay(unsigned char i)   //12MHz ÑÓÊ±º¯Êý  
{
    unsigned char a,b;        //¸Ã¶ÎÑÓÊ±º¯ÊýDelay(1)=0.5ms
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
                            ×ÜÖÜÆÚ20ms
                Í¨¹ýµ÷½ 9    9ÚÕ¼¿Õ±ÈÊµÏÖ¶æ»úÐèÒª×ª¶¯µÄ½Ç¶È
¶æ»ú´úÂëÓÃ¶¨Ê±Æ÷¿ØÖÆ¸ü·½±ãÎÈ¶¨£¬±¾ÎÄ·½±ã¶ÁÕßÁË½âÊ¹ÓÃ£¬Ê¹ÓÃÑÓÊ±¼ÆËã
                         Æä¹¦ÄÜ¿ÉÕý³£Ê¹ÓÃ
*****************************************************************/
void zero(void) //0¶È ×Ó³ÌÐò
{   
        PWM=1;
        Delay(1);       //¸ßµçÆ½ Delay(1)=0.5ms¡£ÒòÎªÖÜÆÚÎª20ms£¬ËùÒÔµÍµçÆ½¾ÍÊÇ19.5ms 
        PWM=0;
        Delay(39);      //µÍµçÆ½ Delay(39)=19.5ms
}
 
void one(void) //45¶È ×Ó³ÌÐò
{
        PWM=1;
        Delay(2);      //¸ßµçÆ½  Delay(2)=1ms
        PWM=0;   
        Delay(38);     //µÍµçÆ½  Delay(38)=19ms
}
 
void two(void)  //90¶È ×Ó³ÌÐò
{
         PWM=1;
        Delay(3);       //¸ßµçÆ½ Delay(3)=1.5ms
        PWM=0;
        Delay(37);     //µÍµçÆ½  18.5ms
}
 
void three(void) //135¶È ×Ó³ÌÐò
{
        PWM=1;
        Delay(4);       //¸ßµçÆ½ Delay(4)=2ms
        PWM=0;
        Delay(36);      //µÍµçÆ½ 18ms
}
 
void four(void) //180¶È ×Ó³ÌÐò
{
        PWM=1;
        Delay(5);      //¸ßµçÆ½ Delay(5)=2.5ms
        PWM=0;
        Delay(35);     //µÍµçÆ½ 17.5ms
}
 
 
void main()  //Ö÷³ÌÐò
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