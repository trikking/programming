#include <stdio.h>

int func1(int a,int b)
{ int r;
  r=a%b;
  while(r)
  { a=b;
    b=r;
    r=a%b;
  }
  return b;
}

int func2(int a,int b)
{ int r;
  r=a%b;
  if(r) return func2(b,r);
  else return b;
}

main()
{ int a,b;
  printf("Input a,b:");
  scanf("%d,%d",&a,&b);
  printf("func1:(%d,%d)=%d\n",a,b,func1(a,b));
  printf("func2:(%d,%d)=%d\n",a,b,func2(a,b));
}
