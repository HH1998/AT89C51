#include "bsp_key.h "

int key_press(void)                     //���񰴼�����
{
       char key=0xff;
       int i=0;
       if(P2!=0xff)
       {
              delay(1);
              if(P2!=0xff)
              {
                     key=P2;
                     while((i<20)&&(P2!=0xff))
                     {
                            i++;
                            delay(1);
                     }
              }
       }
       return key;
}

void key_control(char key)                      //���ư�����ͬ״̬��Ӧ�Ĳ�ͬ���
{
        switch (key)
        {
                case (0xfe):                                    //��λ
                {
                        yiwei();
                };
                break;
                
                case (0xfd):                                    //��˸
                {
                flag=~flag;
                if(flag!=0)                                     //�رն�ʱ���ж�
                {
                        TR1=0;
                }
                if (flag==0)                                    //������ʱ���ж�
                {
                        TR1=1;
                }
                }
                break;
                
                case (0xfb):                                    //��
                if(flag !=0)
                {
                        jia();
                };break;
                
                case (0xf7):                            //��
                if(flag !=0)
                {
                        jian();
                };break;
        }
}

void delay(int t)               //�ӳٺ���
{
       int i,j;
       for(i=t;i>0;i--)
       for(j=1000;j>0;j--);
}




