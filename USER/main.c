#include "sys.h"
#include "delay.h"
#include "usart.h"


#define APPLICATION_ADDRESS     (uint32_t)0x08004000

typedef void (*pFunction)(void);

void JumpToApplication(void)
{
    uint32_t JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
    pFunction Jump = (pFunction) JumpAddress;

		__DMB();
		SCB->VTOR = APPLICATION_ADDRESS;
		__DMB();
    
    __set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);

    Jump();
}

int main(void)
 {		
	uart_init(115200);
	 
	printf("BKP->DR1 is %d\n", (uint16_t)BKP->DR1);
	 
	printf("start jump\n");
	JumpToApplication();
	
  while(1)
	{
	}	 
} 

