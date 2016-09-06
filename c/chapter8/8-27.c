#include <stdio.h>

int max(int a,int b,int c);
int min(int a,int b,int c);
int sum(int a,int b,int c);

main()
{ int a,b,c,option,(*p)();
  printf("Input a,b,c:");
  scanf("%d,%d,%d",&a,&b,&c);
  do
  { printf("0:exit\n");
    printf("1:max(a,b,c)\n");
    printf("2:min(a,b,c)\n");
    printf("3:sum(a,b,c)\n");
    printf("select 0-3:");
    scanf("%d",&option);
    switch(option)
    { case 1:  p=max;
               printf("max(a,b,c)=%d\n",(*p)(a,b,c));
               break;
      case 2:  p=min;
               printf("min(a,b,c)=%d\n",(*p)(a,b,c));
               break;
      case 3:  p=sum;
               printf("sum(a,b,c)=%d\n",(*p)(a,b,c));
      case 0:  break;
      default: printf("data error!\n");
    }
  }while(option);
}

int max(int a,int b,int c)
{ int max;
  max=a>b?a:b;
  max=max>c?max:c;
  return max;
}

int min(int a,int b,int c)
{ int min;
  min=a<b?a:b;
  min=min<c?min:c;
  return min;
}

int sum(int a,int b,int c)
{ return (a+b+c);
}
