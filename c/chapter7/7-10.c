#include <stdio.h>
#include <math.h>

int prime(int x);

main()
{ int a,b,c,n;
  scanf("%d",&n);
  for(a=6;a<=n;a+=2)
    for(b=3;b<=a/2;b++)
      if(prime(b))
      { c=a-b;
        if(prime(a-b))
        {  printf("%d=%d+%d\n",a,b,a-b);
           break;
        }
      }
}

int prime(int x)
{ int i;
  for(i=2;i<=sqrt(x);i++)
    if(!x%i) return 0;
  return 1;
}
