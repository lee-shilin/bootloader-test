#include "sys.h"
#include "delay.h"
#include "usart.h"

int main(void)
{		
	uart_init(115200);
	
	printf("go into main\n");

	for(;;)
	{		
		if (jump_flag)
		{
			JumpToApplication();
		}
	}	 
} 

