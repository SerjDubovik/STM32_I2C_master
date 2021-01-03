#include "stm32f10x.h"
#include "GPIO.h"


void init_GPIO(void)
{

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // ��������� ������������ GPIOA
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;   // ��������� ������������ GPIOB
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;   // ��������� ������������ GPIOC
	RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;   // ��������� ������������ GPIOD
	RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;	  // ��������� ������������ GPIOE


	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);


	/////////////////////////
	// ���������
	/*
	// USART1
	RCC->APB2ENR |=   RCC_APB2ENR_USART1EN;              // ������������ USART1

	//���������������� PORTA.9 ��� TX
	GPIOA->CRH   &= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9);   // ����������� MODE � CNF
	GPIOA->CRH   |=   GPIO_CRH_MODE9 | GPIO_CRH_CNF9_1;  // ����������� ����� � ���������� �-��, 50MHz

	//���������������� PORTA.10 ��� RX
	GPIOA->CRH   &= ~(GPIO_CRH_MODE10 | GPIO_CRH_CNF10);   // ����������� MODE � CNF
	GPIOA->CRH   |=   GPIO_CRH_CNF10_0;                   // ����, ������ ���������
	*/


	//USART2
	RCC->APB2ENR |=   RCC_APB2ENR_AFIOEN;				// ������������ �������������� ������� GPIO
	RCC->APB1ENR |=   RCC_APB1ENR_USART2EN;             // ������������ USART2


	AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;			// ��������� JTAG. ����������� ���� ��� �����������.



	//���������������� GPIOA.0							//
	GPIOA->CRL &= ~GPIO_CRL_MODE0;   					// �������� ������� MODE
	GPIOA->CRL &= ~GPIO_CRL_CNF0;    					// �������� ������� CNF


	// ���������������� GPIOA.1							// ���������� �����-������������
	GPIOA->CRL &= ~GPIO_CRL_MODE1;   					// �������� ������� MODE
	GPIOA->CRL &= ~GPIO_CRL_CNF1;    					// �������� ������� CNF
	GPIOA->CRL |=  GPIO_CRL_MODE1;   					// �����, 50MHz
	GPIOA->CRL &= ~GPIO_CRL_CNF1;    					// ������ ����������, �����������

	// �������� 0 � GPIOA.1								// �������
	GPIOA->BSRR =  GPIO_BSRR_BR1;


	//���������������� PORTA.2 ��� TX
	GPIOA->CRL   &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);  // ����������� MODE � CNF
	GPIOA->CRL   |=   GPIO_CRL_MODE2 | GPIO_CRL_CNF2_1; // ����������� ����� � �������������� �-��, 50MHz

	//���������������� PORTA.3 ��� RX
	GPIOA->CRL   &= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3);  // ����������� MODE � CNF
	GPIOA->CRL   |=   GPIO_CRL_CNF3_0;                  // ����, ������ ���������


	//���������������� GPIOA.4							//
	GPIOA->CRL &= ~GPIO_CRL_MODE4;   					// �������� ������� MODE
	GPIOA->CRL &= ~GPIO_CRL_CNF4;    					// �������� ������� CNF

	//���������������� GPIOA.5							//
	GPIOA->CRL &= ~GPIO_CRL_MODE5;   					// �������� ������� MODE
	GPIOA->CRL &= ~GPIO_CRL_CNF5;    					// �������� ������� CNF

	//���������������� GPIOA.6							//
	GPIOA->CRL &= ~GPIO_CRL_MODE6;   					// �������� ������� MODE
	GPIOA->CRL &= ~GPIO_CRL_CNF6;    					// �������� ������� CNF


	//���������������� GPIOA.7							// ch1n - ����� ���
	GPIOA->CRL &= ~GPIO_CRL_MODE7;   					// �������� ������� MODE
	GPIOA->CRL &= ~GPIO_CRL_CNF7;    					// �������� ������� CNF
	GPIOA->CRL |=  GPIO_CRL_MODE7;   					// �����, 50MHz
	GPIOA->CRL |=  GPIO_CRL_CNF7_1;  					// �������������� �������, �����������


	//���������������� GPIOA.8							// ch1 - ����� ���
	GPIOA->CRH &= ~GPIO_CRH_MODE8;   					// �������� ������� MODE
	GPIOA->CRH &= ~GPIO_CRH_CNF8;    					// �������� ������� CNF
	GPIOA->CRH |=  GPIO_CRH_MODE8;   					// �����, 50MHz
	GPIOA->CRH |=  GPIO_CRH_CNF8_1;  					// �������������� �������, �����������


	//���������������� GPIOA.9							// ch2 - ����� ���
	GPIOA->CRH &= ~GPIO_CRH_MODE9;   					// �������� ������� MODE
	GPIOA->CRH &= ~GPIO_CRH_CNF9;    					// �������� ������� CNF
	GPIOA->CRH |=  GPIO_CRH_MODE9;   					// �����, 50MHz
	GPIOA->CRH |=  GPIO_CRH_CNF9_1;  					// �������������� �������, �����������


	//���������������� GPIOA.10							// ch3 - ����� ���
	GPIOA->CRH &= ~GPIO_CRH_MODE10;  					// �������� ������� MODE
	GPIOA->CRH &= ~GPIO_CRH_CNF10;   					// �������� ������� CNF
	GPIOA->CRH |=  GPIO_CRH_MODE10;  					// �����, 50MHz
	GPIOA->CRH |=  GPIO_CRH_CNF10_1; 					// �������������� �������, �����������

	//���������������� GPIOA.11							// relay1 - ����� ���������� ���� 1
	GPIOA->CRH &= ~GPIO_CRH_MODE11;  					// �������� ������� MODE
	GPIOA->CRH &= ~GPIO_CRH_CNF11;   					// �������� ������� CNF
	GPIOA->CRH |=  GPIO_CRH_MODE11;  					// �����, 50MHz
	GPIOA->CRH &= ~GPIO_CRH_CNF11;   					// ������ ����������, �����������

	//���������������� GPIOA.12							// relay2 - ����� ���������� ���� 2
	GPIOA->CRH &= ~GPIO_CRH_MODE12;  					// �������� ������� MODE
	GPIOA->CRH &= ~GPIO_CRH_CNF12;   					// �������� ������� CNF
	GPIOA->CRH |=  GPIO_CRH_MODE12;  					// �����, 50MHz
	GPIOA->CRH &= ~GPIO_CRH_CNF12;   					// ������ ����������, �����������

	// GPIOA.13											// swd �������
	// GPIOA.14											// swd �������

	//���������������� GPIOA.15							// led1 - ��������� �� �����.
	GPIOA->CRH &= ~GPIO_CRH_MODE15;  					// �������� ������� MODE
	GPIOA->CRH &= ~GPIO_CRH_CNF15;   					// �������� ������� CNF
	GPIOA->CRH |=  GPIO_CRH_MODE15;  					// �����, 50MHz
	GPIOA->CRH &= ~GPIO_CRH_CNF15;   					// ������ ����������, �����������

	//���������������� GPIOB.0							// ch2n - ����� ���
	GPIOB->CRL &= ~GPIO_CRL_MODE0;   					// �������� ������� MODE
	GPIOB->CRL &= ~GPIO_CRL_CNF0;    					// �������� ������� CNF
	GPIOB->CRL |=  GPIO_CRL_MODE0;   					// �����, 50MHz
	GPIOB->CRL |=  GPIO_CRL_CNF0_1;  					// �������������� �������, �����������

	//���������������� GPIOB.1							// ch3n - ����� ���
	GPIOB->CRL &= ~GPIO_CRL_MODE1;   					// �������� ������� MODE
	GPIOB->CRL &= ~GPIO_CRL_CNF1;    					// �������� ������� CNF
	GPIOB->CRL |=  GPIO_CRL_MODE1;   					// �����, 50MHz
	GPIOB->CRL |=  GPIO_CRL_CNF1_1;  					// �������������� �������, �����������

	//���������������� GPIOB.3							// led2 - ��������� �� �����.
	GPIOB->CRL &= ~GPIO_CRL_MODE3;   					// �������� ������� MODE
	GPIOB->CRL &= ~GPIO_CRL_CNF3;    					// �������� ������� CNF
	GPIOB->CRL |=  GPIO_CRL_MODE3;   					// �����, 50MHz
	GPIOB->CRL &= ~GPIO_CRL_CNF3;    					// ������ ����������, �����������

	// PB4 - Pin4
	// PB5 - Pin45

	//���������������� GPIOB.6							// I2C1_SCL
	GPIOB->CRL &= ~GPIO_CRL_MODE6;   					// �������� ������� MODE
	GPIOB->CRL &= ~GPIO_CRL_CNF6;    					// �������� ������� CNF
	GPIOB->CRL |=  GPIO_CRL_MODE6;   					// �����, 50MHz
	GPIOB->CRL |=  GPIO_CRL_CNF6;  						// �������������� �������, �����������		!!!!!!! ���� GPIO_CRL_CNF6_1 ��� �� ��������

	//���������������� GPIOB.7							// I2C1_SDA
	GPIOB->CRL &= ~GPIO_CRL_MODE7;   					// �������� ������� MODE
	GPIOB->CRL &= ~GPIO_CRL_CNF7;    					// �������� ������� CNF
	GPIOB->CRL |=  GPIO_CRL_MODE7;   					// �����, 50MHz
	GPIOB->CRL |=  GPIO_CRL_CNF7;  						// �������������� �������, �����������		!!!!!!! ���� GPIO_CRL_CNF7_1 ��� �� ��������



	// PB8 - Pin6
	// PB9 - Pin7
	// PB10 - Pin8
	// PB11 - Pin9

	//���������������� GPIOB.12							// NSS
	GPIOB->CRH &= ~GPIO_CRH_MODE12;  					// �������� ������� MODE
	GPIOB->CRH &= ~GPIO_CRH_CNF12;   					// �������� ������� CNF
	GPIOB->CRH |=  GPIO_CRH_MODE12;  					// �����, 50MHz
	GPIOB->CRH |=  GPIO_CRH_CNF12_1; 					// �������������� �������, �����������

	//���������������� GPIOB.13							// SCK
	GPIOB->CRH &= ~GPIO_CRH_MODE13;  					// �������� ������� MODE
	GPIOB->CRH &= ~GPIO_CRH_CNF13;   					// �������� ������� CNF
	GPIOB->CRH |=  GPIO_CRH_MODE13;  					// �����, 50MHz
	GPIOB->CRH |=  GPIO_CRH_CNF13_1; 					// �������������� �������, �����������

	//���������������� GPIOB.14							// MISO
	GPIOB->CRH &= ~GPIO_CRH_MODE14;  					// �������� ������� MODE
	GPIOB->CRH &= ~GPIO_CRH_CNF14;   					// �������� ������� CNF
	GPIOB->CRH |=  GPIO_CRH_MODE14;  					// �����, 50MHz
	GPIOB->CRH |=  GPIO_CRH_CNF14_1; 					// �������������� �������, �����������

	//���������������� GPIOB.15							// MOSI
	GPIOB->CRH &= ~GPIO_CRH_MODE15;  					// �������� ������� MODE
	GPIOB->CRH &= ~GPIO_CRH_CNF15;   					// �������� ������� CNF
	GPIOB->CRH |=  GPIO_CRH_MODE15;  					// �����, 50MHz
	GPIOB->CRH |=  GPIO_CRH_CNF15_1; 					// �������������� �������, �����������

	// PC13 - Pin1
	// PC14 - Pin2
	// PC15 - Pin3

} // �������� init_GPIO






void relay_1(unsigned int set)
{
	if(set == on)
	{
		GPIOA->BSRR =  GPIO_BSRR_BS11;  				// GPIOA.11=1
	}
	if(set == off)
	{
		GPIOA->BSRR =  GPIO_BSRR_BR11;  				// GPIOA.11=0
	}
}



void relay_2(unsigned int set)
{
	if(set == on)
	{
		GPIOA->BSRR =  GPIO_BSRR_BS11;  				// GPIOA.11=1
	}
	if(set == off)
	{
		GPIOA->BSRR =  GPIO_BSRR_BR11;  				// GPIOA.11=0
	}
}


void blue_led(unsigned int set)
{
	if(set == on)
	{
		GPIOA->BSRR =  GPIO_BSRR_BS15;  //GPIOA.15=1
	}
	if(set == off)
	{
		GPIOA->BSRR =  GPIO_BSRR_BR15;  //GPIOA.15=0
	}
}


void red_led(unsigned int set)
{
	if(set == on)
	{
		GPIOB->BSRR =  GPIO_BSRR_BS3;  //GPIOB.3=1
	}
	if(set == off)
	{
		GPIOB->BSRR =  GPIO_BSRR_BR3;  //GPIOB.3=0
	}
}


