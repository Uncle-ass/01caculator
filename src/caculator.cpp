#include<iostream.h>
void main()
{
   int i,count,*p;
   cin>>count;
   p=new int[count];
   for(i=0;i<count;i++)
      cin>>p[i];
   for(i=0;i<count;i++)
      cout<<p[i]<<" ";
   delete []p;
}
#include "stdafx.h"
#include"stdlib.h"
#include"stdio.h"
#include"time.h"
#include "iostream"
#define N 4   //���Ʋ���������ĸ���
int main(int argc, char* argv[]) //����3����Ķ���ʽ�����ƵĲ�����1���˳���2�����ţ�3���Ӽ���Ľ���Ƿ��Ǹ�����4�������Ƿ�������
{
    int a[3];            //��ʾ���������3��
    int f[4];            //��Ʋ��� f[0]�Ƿ��г˳�;f[1]�Ƿ������ţ�f[2]�Ӽ������޸�����f[3]������������
    int d[2]={0,0};  //d[]�ֱ��ʾ�����ţ������ŵ�λ��
    int e[2];       //e[0]��ʾ��һ��λ�õ��������;e[1]��ʾ�ڶ���λ�õ����������
    int z[N];       //����ÿһ��ʽ�ӽ��
    int f1[N];       //��¼ÿһ��ʽ�ӵĶԴ�
    int n;
    int x;            //������
    srand((unsigned)time(NULL));
    n=0;
    printf("�Ƿ��г˳�?\n0,����\t1,��\n������ѡ��\n");
    scanf("%d",&f[0]);
    printf("�Ƿ�������?\n0,����\t1,��\n������ѡ��\n");
    scanf("%d",&f[1]);    
    printf("�Ӽ������޸���?\n0,����\t1,��\n������ѡ��\n");
    scanf("%d",&f[2]);
    printf("������������?\n0,����\t1,��\n������ѡ��\n");
    scanf("%d",&f[3]);
    while(n<N)
    {
        if(f[0]==1)
        {
            e[0]=rand()%4;           // 0��ʾ�� 1��ʾ�� 2��ʾ�� 3��ʾ��
            e[1]=rand()%4;           // 0��ʾ�� 1��ʾ�� 2��ʾ�� 3��ʾ��
        }
        else    
        {
            e[0]=rand()%2;           // 0��ʾ�� 1��ʾ��
            e[1]=rand()%2;           // 0��ʾ�� 1��ʾ��
        }
        if(f[1]==1)
        {
            d[0]=rand()%3;
            if(d[0]!=0)
            {
                d[1]=d[0]+1;
            }
        }
        a[0]=rand()%100;
        a[1]=rand()%100;
        a[2]=rand()%100;
        if(d[0]==1)
        {
            switch(e[0])
            {
                case 0:z[n]=a[0]+a[1];break;
                case 1:
                    {
                        if(f[2]==0)
                            a[1]=rand()%a[0];
                        z[n]=a[0]-a[1];break;
                    }
                case 2:z[n]=a[0]*a[1];break;
                case 3:
                    {/**/
                        if(f[3]==0)
                        {
                            while(a[1]%a[0]!=0)
                            {    
                                a[0]=rand()%100;
                                a[0]=a[0]*a[1];
                                if(a[0]<100)
                                    break;
                                else
                                    a[0]=rand()%100;
                            }
                        }
                        
                        z[n]=a[0]/a[1];break;
                    }
            }
            switch(e[1])
            {
                case 0:z[n]=z[n]+a[2];break;
                case 1:
                    {
                        if(f[2]==0)
                            a[2]=rand()%z[n];
                        z[n]=z[n]-a[2];break;
                    }
                case 2:z[n]=z[n]*a[2];break;
                case 3:
                    {/**/
                        if(f[3]==0)
                        {
                            while(z[n]%a[2]!=0)
                                a[2]=rand()%z[n];
                        }
                        
                        z[n]=z[n]/a[2];break;
                    }
            }
        }
        else if(d[0]==2)
        {
            switch(e[1])
            {
                case 0:z[n]=a[1]+a[2];break;
                case 1:
                    {
                        if(f[2]==0)
                            a[2]=rand()%a[1];
                        z[n]=a[1]-a[2];break;
                    }
                case 2:z[n]=a[1]*a[2];break;
                case 3:
                    {/**/
                        if(f[3]==0)
                        {
                            while(a[1]%a[2]!=0)
                            {
                                a[1]=rand()%100;
                                a[1]=a[1]*a[2];
                                if(a[1]<100)
                                    break;
                                else
                                    a[1]=rand()%100;
                            }

                        }
                        z[n]=a[1]/a[2];break;
                    }
            }
            switch(e[0])
            {
                case 0:z[n]=a[0]+z[n];break;
                case 1:
                    {
                        if(f[2]==0)
                        {
                            while(a[0]-z[n]<0)
                            {
                                a[0]=rand()%100;
                                a[0]=z[n]+a[0];
                                if(a[0]<=100)
                                    break;
                                else 
                                    a[0]=rand()%100;
                            }
                        }
                        z[n]=a[0]-z[n];break;
                    }
                case 2:z[n]=a[0]*z[n];break;
                case 3:
                    {
                        /**/if(f[3]==0)
                        {
                            while(a[0]%z[n]!=0)
                            {
                                a[0]=rand()%100;
                                a[0]=z[n]*a[0];
                                if(a[0]<=100)
                                    break;
                                else
                                    a[0]=rand()%100;
                            }
                        }
                        z[n]=a[0]/z[n];break;
                    }
            }
        }
        else
        {
            if(e[0]>=2)
            {
                switch(e[0])
                {
                    case 2:z[n]=a[0]*a[1];break;
                    case 3:
                        {
                        /*    */if(f[3]==0)
                            {
                                while(a[0]%a[1]!=0)
                                {
                                    a[0]=rand()%100;
                                    a[0]=a[1]*a[0];
                                    if(a[0]<=100)
                                        break;
                                    else
                                        a[0]=rand()%100;
                                }
                            }
                            z[n]=a[0]/a[1];break;
                        }
                }
                switch(e[1])
                {
                    case 0:z[n]=z[n]+a[2];break;
                    case 1:
                        {
                            if(f[2]==0)
                            {
                                if(z[n]-a[2]<0)
                                    a[2]=rand()%z[n];
                            }
                            z[n]=z[n]-a[2];break;
                        }
                    case 2:z[n]=z[n]*a[2];break;
                    case 3:
                        {/**/
                            if(f[3]==0)
                            {
                                while(z[n]%a[2]!=0)
                                    a[2]=rand()%z[n];
                            }
                            
                            z[n]=z[n]/a[2];break;
                        }
                }
            }
            else if(e[1]<=1)
            {
                switch(e[0])
                {
                case 0:z[n]=a[0]+a[1];break;
                case 1:
                    {
                        if(f[2]==0)
                        {
                            if(a[0]-a[1]<=0)
                                a[1]=rand()%a[0];
                        }
                        z[n]=a[0]-a[1];break;
                    }
                }
                switch(e[1])
                {
                    case 0:z[n]=z[n]+a[2];break;
                    case 1:
                        {
                            if(f[2]==0)
                            {
                                if(z[n]-a[2]<=0)
                                    a[2]=rand()%z[n];
                            }
                            z[n]=z[n]-a[2];break;
                        }
                }
            }
            else
            {
                switch(e[1])
                {
                    case 2:z[n]=a[1]*a[2];break;
                    case 3:
                        {/**/
                            if(f[3]==0)
                            {
                                while(a[1]%a[2]!=0)
                                {
                                    a[1]=rand()%100;
                                    a[1]=a[2]*a[1];
                                    if(a[1]<=100)
                                        break;
                                    a[1]=rand()%100;
                                }
                            }
                            z[n]=a[1]/a[2];break;
                        }
                }
                switch(e[0])
                {
                    case 0:z[n]=a[0]+z[n];break;
                    case 1:
                        {
                            if(f[2]==0)
                            {
                                while(a[0]-z[n]<0)
                                {
                                    a[0]=rand()%100;
                                    a[0]=z[n]+a[0];
                                    if(a[0]<=100)
                                        break;
                                    else 
                                        a[0]=rand()%100;
                                }
                            }
                            z[n]=a[0]-z[n];break;
                        }
                }
            }

        }                                  
        printf("%d,",n+1);                            //��ʾʽ��
        if(d[0]==1)
            printf("(");
        printf("%d",a[0]);
        switch(e[0])
        {
        case 0:printf("+");break;
        case 1:printf("-");break;
        case 2:printf("*");break;
        case 3:printf("/");break;
        }
        if(d[0]==2)
            printf("(");
        printf("%d",a[1]);
        if(d[1]==2)
            printf(")");
        switch(e[1])
        {
        case 0:printf("+");break;
        case 1:printf("-");break;
        case 2:printf("*");break;
        case 3:printf("/");break;
        }
        printf("%d",a[2]);
        if(d[1]==3)
            printf(")");
        printf("=\n");
        n++;
    }
    printf("������д�´�\n");
    for(n=0;n<N;n++)
    {
        printf("%d.",n+1);
        scanf("%d",&x);
        if(z[n]==x)
            f1[n]=1;
        else
            f1[n]=0;
            
    }
    printf("�Դ�����\n");
    for(n=0;n<N    ;n++)
    {
        printf("%d,",n);
        if(f1[n]==1)
            printf("T");
        else
            printf("F");
        printf("��ȷ��:%d\n",z[n]);
    }
	system("pause");
    return 0;
}