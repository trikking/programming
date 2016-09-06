#include <stdio.h>
void dtob(int,int *,int *);
void fb(int *,int);

main()
{ int x,a[20],n,i;
  printf("Input x:");
  scanf("%d",&x);
  dtob(x,a,&n);
  printf("[%d](10)=[",x);
  for(i=0;i<n;i++)
    printf("%d",a[i]);
  printf("](2)\n");
}

void dtob(int x,int *p,int *m)
{ int i=0,b;
  do
  { p[i++]=x%2;
    x=x/2;
  }while(x);
  *m=i;
  fb(p,i);
}

void fb(int *p,int n)
{ int i,t;
  for(i=0;i<n/2;i++)
  { t=p[i];
    p[i]=p[n-i-1];
    p[n-i-1]=t;
  }
}
