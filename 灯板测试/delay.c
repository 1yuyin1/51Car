#include <REGX52.H>
#include <intrins.h>
void delayus (int t)//΢�뼶��ʱ����
{
    unsigned int num;
    unsigned int x;


    for (num = 0; num < t; num++)
    {
        x = 11;
        while (x != 0)
        {
            x--;
        }
    }


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
