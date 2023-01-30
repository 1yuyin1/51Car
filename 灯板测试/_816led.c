#include <REGX51.H>
#include "delay.h"

sbit SDA=P0^7;
sbit SCL=P0^6;


void IIC_start()
{ SCL=1;
  delayus(3);
  SDA=1;
  delayus(3);
  SDA=0;
  delayus(3);
}
void IIC_send(unsigned char send_data)
{  char i;
  for(i = 0;i < 8;i++)
  {
      SCL=0;
      delayus(3);
      if(send_data & 0x01)
      {
        SDA=1;
      }
      else
      {
        SDA=0;
      }
      delayus(3);
      SCL=1;
      delayus(3);
      send_data = send_data >> 1;
  }
}

void IIC_end()
{
  SCL=0;
  delayus(3);
  SDA=0;
  delayus(3);
  SCL=1;
  delayus(3);
  SDA=1;
  delayus(3);
}

void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  // use the function of the data transmission start condition
  IIC_send(0xc0);  //select address
  int i;
  for(i = 0;i < 16;i++) //pattern data has 16 bits
  {
     IIC_send(matrix_value[i]); //convey the pattern data
  }

  IIC_end();   //end the transmission of pattern data  
  IIC_start();
  IIC_send(0x8A);  //display control, set pulse width to 4/16 s
  IIC_end();
}

