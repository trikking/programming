#include <stdio.h>
int swap1(int x,int y)
{ int t;
  t=x;x=y;y=t;
}

int swap2(int *x,int *y)
{ int t;
  t=*x;*x=*y;*y=t;
}

int swap3(int *x,int *y)
{ int *t;
  t=x;x=y;y=t;
}

main()
{ int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a>b) swap1(a,b);
  if(a>c) swap1(a,c);
  if(b>c) swap1(b,c);
  printf("a=%d,b=%d,c=%d\n",a,b,c);

  scanf("%d%d%d",&a,&b,&c);
  if(a>b) swap2(&a,&b);
  if(a>b) swap2(&a,&c);
  if(b>c) swap2(&b,&c);
  printf("a=%d,b=%d,c=%d\n",a,b,c);

  scanf("%d%d%d",&a,&b,&c);
  if(a>b) swap3(&a,&b);
  if(a>b) swap3(&a,&c);
  if(b>c) swap3(&b,&c);
  printf("a=%d,b=%d,c=%d\n",a,b,c);
}
