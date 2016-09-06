#include <stdio.h>

main()
{ int a[5],i,*p,*q,*pp,t;
  for(i=0;i<5;i++)
    scanf("%d",a+i);
  for(p=a;p<a+5;p++)
  { pp=p;
    for(q=p+1;q<a+5;q++)
      if(*pp>*q)
        pp=q;
    if(pp!=p)
    { t=*p;
      *p=*pp;
      *pp=t;
    }
  }
  for(i=0;i<5;i++)
    printf("%4d",*(a+i));
  printf("\n");
}
