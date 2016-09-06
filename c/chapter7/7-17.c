#include <stdio.h>

long xn(int x,int n)
{ long f;
  if(n<0) printf("n<0,data err!\n");
  else if(n==0) f=1;
  else f=x*xn(x,n-1);
  return f;
}

main()
{ int x,n;
  scanf("%d,%d",&x,&n);
  long y;
  y=xn(x,n);
  printf("%d^%d=%ld\n",x,n,y);
}
