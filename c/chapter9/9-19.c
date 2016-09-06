#include <stdio.h>
struct DATE
{ int y,m,d;
};
struct MA
{ char name[20];
  int n;
};
union MSTAT               //定义共用体类型
{ struct MA married;      //已婚者信息 
  struct DATE divorced;   //离婚者信息
  char dormitory;         //单身者信息
};
struct RECORD             //定义结构体类型
{ char number[6];         //职工编号
  char name[20];          //职工姓名
  char sex;               //职工性别
  char maritalstat;       //婚姻状况
  union MSTAT ms;         //不同婚姻状况下的信息
};
main()
{ struct RECORD a[3];
  int i;
  char flag;              //标识符,'M'表示已婚,'D'表示离婚,'S'表示单身
  for(i=0;i<3;i++)
  { printf("number:");
    scanf("%s",a[i].number);
    printf("name:");
    scanf("%s",a[i].name);
    printf("sex:");
    scanf(" %c",&a[i].sex);
    if(a[i].sex=='m' || a[i].sex=='M')
      a[i].sex='M';
    else
      a[i].sex='F';
    printf("maritalstat(m/d/s):");
    scanf(" %c",&flag);
    if(flag=='m' || flag=='M')
    { a[i].maritalstat='M';
      printf("spouse name:");
      scanf("%s",a[i].ms.married.name);
      printf("number of children:");
      scanf("%d",&a[i].ms.married.n);
    }
    else if(flag=='d' || flag=='D')
    { a[i].maritalstat='D';
      printf("divorced date(yyyy-mm-dd):");
      scanf("%d-%d-%d",&a[i].ms.divorced.y,&a[i].ms.divorced.m,&a[i].ms.divorced.d);
    }
    else
    { a[i].maritalstat='S';
      printf("living quarters for work(y/n):");
      scanf(" %c",&a[i].ms.dormitory);
      if(a[i].ms.dormitory=='y' || a[i].ms.dormitory=='Y')
        a[i].ms.dormitory='Y';
      else
        a[i].ms.dormitory='N';
    }
  }
  printf("number\tname\tsex\tmaritalstat\n");
  for(i=0;i<3;i++)
  { printf("%s\t%s\t%c\t",a[i].number,a[i].name,a[i].sex); 
    if(a[i].maritalstat=='M')
      printf("married spouse name:%s, number of children:%d\n",a[i].ms.married.name,a[i].ms.married.n);
    else if(a[i].maritalstat=='D')
      printf("divorced date:%4d-%2d-%2d\n",a[i].ms.divorced.y,a[i].ms.divorced.m,a[i].ms.divorced.d);
    else
      printf("living quarters for work:%c\n",a[i].ms.dormitory);
  }
}
