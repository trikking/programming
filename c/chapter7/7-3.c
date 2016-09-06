#include <stdio.h>
int sum(int n)
{ int i, t=0;
  for(i=1;i<=n;i++)
  { t+=i;
  }
  return t;
}

main()
{ int s;
  s=sum(100);
  printf("1+2+3+...+100=%d\n", s);
}
