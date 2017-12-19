#include "bsp_I2C.h"

void delay_10us(void)    // ��ʱ10us
{
    unsigned char a;
    for(a=3;a>0;a--);
}

/************************** ��ʼ�ź� **************************/
void I2C_Start(void)
{
            SCL=1;
            delay_10us();
            SDA=1;
            delay_10us();
            SDA=0;
            delay_10us();
            SCL=0;
            delay_10us();
}   

/************************** �����ź� **************************/
void I2C_Stop(void)
{
            SDA=0;
            delay_10us();
            SCL=1;
            delay_10us();
            SDA=1;
            delay_10us();
            SDA=0;
            delay_10us();
}
/************************** �����ֽ� **************************/
char I2C_SendByte (char dat)
{
            u8 a,b;
            for(a=0;a<8;a++)
            {
                        if((dat<<a)&0x80) SDA=1; 
                        else SDA=0;                   //�����λ��ʼ����
                        delay_10us();
                        SCL=1;
                        delay_10us();           //�ȴ�����
                        SCL=0;    
                        delay_10us();
            }
            /* ��λ���ݷ������ */
            SDA=1;
            SCL=1;
            while(SDA)
            {
                        b++;
                        if(b>200)
                        {
                                    SCL=0;
                                    delay_10us();
                                    return 0;  //����0��ʾͨ��ʧ��
                        }
            }
            SCL=0;
            delay_10us();
            return 1;//ͨ�ųɹ�
}

/************************** �����ֽ� **************************/
char I2C_ReciverByte (void)
{
            u8 a=0,dat=0;
            for(a=0;a<8;a++)
            {
                        SCL=1;
                        delay_10us();
                        dat=dat<<1;
                        dat=SDA|dat;
                        delay_10us();
                        SCL=0;
                        delay_10us();
            }
            return dat;
}
