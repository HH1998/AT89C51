#include "bsp_Init.h"

extern char SendByte (char dat);
extern void Start( void );
extern void Stop ( void );
extern void delay_10us ( void );


void Init(void)
{
            /*          ���ڳ�ʼ��            */
            TMOD=0x20;  
            TL1 = 0xFD;       //�趨��ʱ��ֵ
            TH1 = 0xFD;       //�趨��ʱ����װֵ
            PCON=0x00;
            TR1=1;
            SCON=0x50;
            EA=1;
            ES=1;
}




