#include <reg51.h>
#include "bsp_Init.h"

/***********************************************************************/

u8 receiveData;

int main()   
{
            Init();  //��ʼ��
            while(1)
            {
                        P1 = receiveData;//��receiveData��ֵ����P1��
            }

}

void Usart() interrupt 4  //�����շ��ж�
{
            /*          �����ж�        */
            RI=0;           //��0��������һ�εĽ���
            receiveData = SBUF;//�����յ������ݱ����� receiveData ��
            SBUF = receiveData;
            while(!TI);
            TI=0;
}