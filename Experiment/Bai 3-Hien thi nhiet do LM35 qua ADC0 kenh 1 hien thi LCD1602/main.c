/**
  ******************************************************************************
  * @file		main.c
  * @author	www.hocdientu123.vn
  * @date		25/06/2019
  ******************************************************************************
  */
#include "main.h"
//---------------------------KHAI BAO CAC BIEN VA HANG-------------------------//
uint16_t temp_adc=0;
uint8_t nhiet_do=0;
uint8_t j=0;
//---------------------------KHAI BAO CAC HAM----------------------------------//
//---------------------------HAM MAIN------------------------------------------//
int main()
	{
		DelayInit();	// goi ham khoi tao du lieu cho cac ham delay
		GPIO_Configuration();	// goi ham cau hinh ngo vao ra cho cac PORT
		GPIO_PinRemapConfig (GPIO_Remap_SWJ_JTAGDisable, ENABLE);//bo che do nap JTAGD
		LCD16X2_Init();				//goi ham cau hinh LCD
		ADC_Configuration();	//goi ham cau hinh chuyen doi ADC
		LCD16X2_Clear();		//xoa man hinh
		LCD16X2_Gotoxy(0,0);//hien thi toa do x,y=(0,0)
		LCD16X2_PutString("GIA TRI LM35");//hien thi chuoi ky tu ra man hinh LCD
		while(1)
		{
					for(j=0;j<20;j++)
					{
							temp_adc+=ADC0_Read();							//doc gia tri ADC
						Delay_us(10);
					}
		  temp_adc=temp_adc/20;
			nhiet_do=((temp_adc*3.3*100)/4095);	//tinh gia tri nhiet do hien thi ra LCD
			LCD16X2_Gotoxy(0,1);							//hien thi tai toa do x,y=(0,1)
			LCD16X2_NumBer(nhiet_do,2);				//hien thi gia tri nhiet do
			LCD16X2_Gotoxy(2,1);						//hien thi tai toa do x,y=(2,1)
			LCD16X2_PutChar(0xDF);					//ky tu nhiet do
		  LCD16X2_PutChar('C');
		} 
	}

