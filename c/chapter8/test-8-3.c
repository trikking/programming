#include <stdio.h>
#define N 10
void order (int *p, int *q)
{ int temp;
  if (*p>*q)
  { temp=*p; 
    *p=*q; 
    *q=temp;
  }
}

void sort(int *a)
{ int i,j;
  for(i=1;i<N;i++)
    for(j=0;j<N-i;j++)
      order(a+j,a+j+1);
}

main()
{ int a[N],i;
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  for(i=0;i<N;i++)
    printf("%5d",a[i]);
  printf("\n");
  sort(a);
  for(i=0;i<N;i++)
    printf("%5d",a[i]);
  printf("\n");
}
