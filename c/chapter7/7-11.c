#include <stdio.h>

int min(int x,int y)
{ return x<y?x:y;
}

main()
{ int a[5],i,m;
  for(i=0;i<5;i++)
    scanf("%d",&a[i]);
  m=a[0];
  for(i=1;i<5;i++)
    m=min(m,a[i]);
  printf("The minimal value is %d.\n",m);
}
