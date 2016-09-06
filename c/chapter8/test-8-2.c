#include <stdio.h>
#define N 10
void reverse_array(int *p)
{ int i,t;
  for(i=0;i<N/2;i++)
  { t=*(p+i);
    *(p+i)=*(p+9-i);
    *(p+9-i)=t;
  }
}
main()
{ int a[N],i;
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  reverse_array(a);
  for(i=0;i<N;i++)
    printf("%5d",a[i]);
  printf("\n");
}
