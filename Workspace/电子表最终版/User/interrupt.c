#include "interrupt.h"
#include "bsp_key.h"
void INT0_Handler() interrupt 0         //�ⲿ�ж�
{
       key_control(key_press());
}

void TIM0_Handler() interrupt 3         //��ʱ���ж�
{
        TR1=0;
        TH1 = 0x0b;
        TL1 = 0xdc;                     //װ�س�ֵ
        TR1=1;
        a++;
        if(a >= 16)                     //��һ����
        {
                a = 0;
                num=5;
                jia();
        }
}