#include "reg51.h"
#include "oled.h"
 
void main(void)
{	
		unsigned int t=1;
		OLED_Init();			//初始化OLED  
		OLED_Clear(); 		//清屏函数
			
				//这个函数显示中文
				OLED_ShowCHinese(0,0,3);//速	//第一个形参是列，第二个是行，第三个是显示哪个中文，这里一个字占16宽
				OLED_ShowCHinese(20,0,4);//度
//				OLED_ShowCHinese(44,0,1);//二
//				OLED_ShowCHinese(0,2,5);//模
//				OLED_ShowCHinese(18,2,6);//式
//				OLED_ShowCHinese(44,2,12);//测
//        OLED_ShowCHinese(62,2,13);//距
//        OLED_ShowCHinese(0,4,13);//距
//        OLED_ShowCHinese(18,4,14);//离
				//这个函数显示字符
//      OLED_ShowString(36,0,":",16);//第一个形参表示第六行，第二个形参表示排，第三个表示写入的字符，第四个表示字体大小
//      OLED_ShowString(36,2,":",16);
//      OLED_ShowString(36,4,":",16);
				//显示数字变量
//				OLED_ShowNum(44,4,t,1,16);		//第一个参数表示列，第二个参数表示行，第三个参数表示变量数字，第四个参数表示显示数字的位数，第五个参数表示字体大小
//	delay_ms(8000);
 while(1){
}
}