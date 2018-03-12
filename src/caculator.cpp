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
#define N 4   //控制产生随机数的个数
int main(int argc, char* argv[]) //还有3个项的多项式，控制的参数有1，乘除；2，括号；3，加减后的结果是否是负数；4，除法是否有余数
{
    int a[3];            //表示随机产生的3数
    int f[4];            //设计参数 f[0]是否有乘除;f[1]是否有括号，f[2]加减结有无负数，f[3]除法有无余数
    int d[2]={0,0};  //d[]分别表示左括号，右括号的位置
    int e[2];       //e[0]表示第一个位置的运算符号;e[1]表示第二个位置的数运算符号
    int z[N];       //存入每一个式子结果
    int f1[N];       //记录每一个式子的对错
    int n;
    int x;            //输入结果
    srand((unsigned)time(NULL));
    n=0;
    printf("是否有乘除?\n0,不是\t1,是\n请输入选项\n");
    scanf("%d",&f[0]);
    printf("是否有括号?\n0,不是\t1,是\n请输入选项\n");
    scanf("%d",&f[1]);    
    printf("加减结有无负数?\n0,不是\t1,是\n请输入选项\n");
    scanf("%d",&f[2]);
    printf("除法有无余数?\n0,不是\t1,是\n请输入选项\n");
    scanf("%d",&f[3]);
    while(n<N)
    {
        if(f[0]==1)
        {
            e[0]=rand()%4;           // 0表示加 1表示减 2表示乘 3表示除
            e[1]=rand()%4;           // 0表示加 1表示减 2表示乘 3表示除
        }
        else    
        {
            e[0]=rand()%2;           // 0表示加 1表示减
            e[1]=rand()%2;           // 0表示加 1表示减
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
        printf("%d,",n+1);                            //显示式子
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
    printf("请依次写下答案\n");
    for(n=0;n<N;n++)
    {
        printf("%d.",n+1);
        scanf("%d",&x);
        if(z[n]==x)
            f1[n]=1;
        else
            f1[n]=0;
            
    }
    printf("对错如下\n");
    for(n=0;n<N    ;n++)
    {
        printf("%d,",n);
        if(f1[n]==1)
            printf("T");
        else
            printf("F");
        printf("正确答案:%d\n",z[n]);
    }
	system("pause");
    return 0;
}