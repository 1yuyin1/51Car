#ifndef ___816led_H__
#define ___816led_H__

void IIC_start();
void IIC_send(unsigned char send_data);
void IIC_end();
void matrix_display(unsigned char matrix_value[]);

#endif
