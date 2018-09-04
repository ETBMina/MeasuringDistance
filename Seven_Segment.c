#include"stdint.h"
#include"tm4c123gh6pm.h"
void SystemInit (void)
{}
void init_portB(void)
{
	//1.
	//SYSCTL_RCGCGPIO_R |= 0x00000002;
	SYSCTL_RCGC2_R |= 0x00000002;
        while( ( SYSCTL_PRGPIO_R   & 0x00000002  ) ==0){}
	//2.
	GPIO_PORTB_LOCK_R =0x4c4f434b; //unlock
	GPIO_PORTB_CR_R=  0xff ;//allow changes
	//3.
	GPIO_PORTB_AMSEL_R=0x00;
	//4.
	GPIO_PORTB_PCTL_R=0x00000000;
	//5.
	GPIO_PORTB_DIR_R=0xff;
	//6.
	GPIO_PORTB_AFSEL_R =0x00;
	//7.
	GPIO_PORTB_DEN_R = 0xff;
}	
void init_portD()
{
	SYSCTL_RCGC2_R |= 0x00000008;//choose an empty port
        while( ( SYSCTL_PRGPIO_R   & 0x00000008  ) ==0){}//same here\\rest just change the name
	//2.
	GPIO_PORTD_LOCK_R =0x4c4f434b; //unlock
	GPIO_PORTD_CR_R=  0x0f ;//allow changes
	//3.
	GPIO_PORTD_AMSEL_R=0x00;
	//4.
	GPIO_PORTD_PCTL_R=0x00000000;
	//5.
	GPIO_PORTD_DIR_R=0x0f;
	//6.
	GPIO_PORTD_AFSEL_R =0x00;
	//7.
	GPIO_PORTD_DEN_R = 0x0f;

}	
void Seven_Segment_Init (void)
{
	init_portB();
	init_portD();
	//init_portxxxxxx();\\make it first
}	
void print_First_7_segment ( int x)
{
	//you can take either switches to put the numbers in upper 4 or lower 4 
	//or u just can put equal ox0/1/2/3....at lower 
	switch(x)
	{
		case 0 :
			       GPIO_PORTD_DATA_R &=0xf0;
          	 break;
   	case 1 :		
			       GPIO_PORTD_DATA_R |=0x01;
			       GPIO_PORTD_DATA_R &=0xf1;
		         break;

    case 2 :		
			       GPIO_PORTD_DATA_R |=0x02;
			       GPIO_PORTD_DATA_R &=0xf2;
		         break;
    case 3 :		
			       GPIO_PORTD_DATA_R |=0x03;
			       GPIO_PORTD_DATA_R &=0xf3;
		         break;
    case 4 :		
			       GPIO_PORTD_DATA_R |=0x04;
			       GPIO_PORTD_DATA_R &=0xf4;
		         break;
    case 5 :		
			       GPIO_PORTD_DATA_R |=0x05;
			       GPIO_PORTD_DATA_R &=0xf5;
		         break;
    case 6 :		
			       GPIO_PORTD_DATA_R |=0x06;
			       GPIO_PORTD_DATA_R &=0xf6;
		         break;
    case 7 :		
			       GPIO_PORTD_DATA_R |=0x07;
			       GPIO_PORTD_DATA_R &=0xf7;
		         break;
    case 8 :		
			       GPIO_PORTD_DATA_R |=0x08;
			       GPIO_PORTD_DATA_R &=0xf8;
		         break;
    case 9 :		
			       GPIO_PORTD_DATA_R |=0x09;
			       GPIO_PORTD_DATA_R &=0xf9;
		         break;
	}	
}

void print_Third_7_segment( int x )
{
	switch(x)
	{
		case 0 :
			       GPIO_PORTB_DATA_R &=0xf0;
          	 break;
   	case 1 :		
			       GPIO_PORTB_DATA_R |=0x01;
			       GPIO_PORTB_DATA_R &=0xf1;
		         break;

    case 2 :		
			       GPIO_PORTB_DATA_R |=0x02;
			       GPIO_PORTB_DATA_R &=0xf2;
		         break;
    case 3 :		
			       GPIO_PORTB_DATA_R |=0x03;
			       GPIO_PORTB_DATA_R &=0xf3;
		         break;
    case 4 :		
			       GPIO_PORTB_DATA_R |=0x04;
			       GPIO_PORTB_DATA_R &=0xf4;
		         break;
    case 5 :		
			       GPIO_PORTB_DATA_R |=0x05;
			       GPIO_PORTB_DATA_R &=0xf5;
		         break;
    case 6 :		
			       GPIO_PORTB_DATA_R |=0x06;
			       GPIO_PORTB_DATA_R &=0xf6;
		         break;
    case 7 :		
			       GPIO_PORTB_DATA_R |=0x07;
			       GPIO_PORTB_DATA_R &=0xf7;
		         break;
    case 8 :		
			       GPIO_PORTB_DATA_R |=0x08;
			       GPIO_PORTB_DATA_R &=0xf8;
		         break;
    case 9 :		
			       GPIO_PORTB_DATA_R |=0x09;
			       GPIO_PORTB_DATA_R &=0xf9;
		         break;
	}	
	
}
void print_Second_7_segment( int x )
{
	
	switch(x)
	{
		case 0 :
			       GPIO_PORTB_DATA_R &=0x0f;
          	 break;
   
		case 1 :		
			       GPIO_PORTB_DATA_R |=0x10;
			       GPIO_PORTB_DATA_R &=0x1f;
		         break;

    case 2 :		
			       GPIO_PORTB_DATA_R |=0x20;
			       GPIO_PORTB_DATA_R &=0x2f;
		         break;
    case 3 :		
			       GPIO_PORTB_DATA_R |=0x30;
			       GPIO_PORTB_DATA_R &=0x3f;
		         break;
    case 4 :		
			       GPIO_PORTB_DATA_R |=0x40;
			       GPIO_PORTB_DATA_R &=0x4f;
		         break;
    case 5 :		
			       GPIO_PORTB_DATA_R |=0x50;
			       GPIO_PORTB_DATA_R &=0x5f;
		         break;
    case 6 :		
			       GPIO_PORTB_DATA_R |=0x60;
			       GPIO_PORTB_DATA_R &=0x6f;
		         break;
    case 7 :		
			       GPIO_PORTB_DATA_R |=0x70;
			       GPIO_PORTB_DATA_R &=0x7f;
		         break;
    case 8 :		
			       GPIO_PORTB_DATA_R |=0x80;
			       GPIO_PORTB_DATA_R &=0x8f;
		         break;
    case 9 :		
			       GPIO_PORTB_DATA_R |=0x90;
			       GPIO_PORTB_DATA_R &=0x9f;
		         break;
	}
}
void print(int x)
{
	int hundred=0, teneth=0 ,units=0;
	hundred =x/100;
	x=x-(100*hundred);
	teneth=x/10;
	x=x-(10*teneth);
	units=x;
        //print_First_7_segment(hundred);//remove and test on debuger i tested from 0 to 99 u 0 to 999 
        // 0  8   31  99 123 159 500 900 999 
	//or put it in for loop and that is better and but a delay module in between in while(1)
	print_Second_7_segment(teneth);
	print_Third_7_segment(units);
	
} 
int main(void)
{
	Seven_Segment_Init ();
	GPIO_PORTB_DATA_R =0xf4;
  while(1)
	{
	print(9);   
	}
	return 0;
}