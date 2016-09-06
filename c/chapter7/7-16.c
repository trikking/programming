#include <stdio.h>
long fact(int n);
main()
{ int n;
  long f;
  scanf("%d",&n);
  f=fact(n);
  printf("%d!=%ld\n",n,f);
}

long fact(int n)
{ long f=0;
  if(n<0) printf("data error!");
  else if(n==0 || n==1) f=1;
  else f=n*fact(n-1);
  return f;
}
