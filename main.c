#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"


void GPIO_INIT(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;
    GPIO_PORTF_DEN_R = 0x1F;
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_PUR_R = 0x11;
}

void GPIO_INTERRUPT_HANDLER(void)
{
    int x=500;
      while(x>0)
      {
          x=x-1;
      }
    GPIO_PORTF_DATA_R ^= 0x02;
    GPIO_PORTF_ICR_R = 0x11;
}

void SysTickHandler(void)
{
    return;
}

int main(void)
{
    GPIO_INIT();
    GPIO_PORTF_IS_R = 0x00;
    GPIO_PORTF_IBE_R = 0x00;
    GPIO_PORTF_IEV_R = 0x00;
    GPIO_PORTF_IM_R = 0x11;
    NVIC_EN0_R =0x40000000;
    while(1)
    {

    }

}
