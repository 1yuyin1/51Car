#include "reg51.h"
#include "oled.h"
 
void main(void)
{	
		unsigned int t=1;
		OLED_Init();			//��ʼ��OLED  
		OLED_Clear(); 		//��������
			
				//���������ʾ����
				OLED_ShowCHinese(0,0,3);//��	//��һ���β����У��ڶ������У�����������ʾ�ĸ����ģ�����һ����ռ16��
				OLED_ShowCHinese(20,0,4);//��
//				OLED_ShowCHinese(44,0,1);//��
//				OLED_ShowCHinese(0,2,5);//ģ
//				OLED_ShowCHinese(18,2,6);//ʽ
//				OLED_ShowCHinese(44,2,12);//��
//        OLED_ShowCHinese(62,2,13);//��
//        OLED_ShowCHinese(0,4,13);//��
//        OLED_ShowCHinese(18,4,14);//��
				//���������ʾ�ַ�
//      OLED_ShowString(36,0,":",16);//��һ���βα�ʾ�����У��ڶ����βα�ʾ�ţ���������ʾд����ַ������ĸ���ʾ�����С
//      OLED_ShowString(36,2,":",16);
//      OLED_ShowString(36,4,":",16);
				//��ʾ���ֱ���
//				OLED_ShowNum(44,4,t,1,16);		//��һ��������ʾ�У��ڶ���������ʾ�У�������������ʾ�������֣����ĸ�������ʾ��ʾ���ֵ�λ���������������ʾ�����С
//	delay_ms(8000);
 while(1){
}
}