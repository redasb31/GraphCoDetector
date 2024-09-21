#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

        char *keta;
        int i=0,j=0;
        int sum=0;
        int a=0;

        for(;;)
        {
                keta = (char *)malloc(sizeof( char )*1001);
                gets(keta);

                if(keta[0] == 0x30)
                {
                        break;
                }
                else
                {
                        while(1)
                        {
                                if(keta[i] == '\0')
                                {
                                        break;
                                }
                                i++;
                        }


                        for(j = 0;j < i ; j++)
                        {
                                if(keta[j] == 0x30)
                                        a = 0;
                                else if(keta[j] == 0x31)
                                        a = 1;
                                else if(keta[j] == 0x32)
                                        a = 2;
                                else if(keta[j] == 0x33)
                                        a = 3;
                                else if(keta[j] == 0x34)
                                        a = 4;
                                else if(keta[j] == 0x35)
                                        a = 5;
                                else if(keta[j] == 0x36)
                                        a = 6;
                                else if(keta[j] == 0x37)
                                        a = 7;
                                else if(keta[j] == 0x38)
                                        a = 8;
                                else if(keta[j] == 0x39)
                                        a = 9;
                                sum = sum + a;
                        }

                        printf("%d", sum);
                        printf("\n");
                }
                i=0;
                sum=0;
                a=0;
                free( keta );
        }
        return 0;
}