#include <stdio.h>
void inarr(int *p,int m, int n)
{ int i,j;
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      scanf("%d",p+i*n+j);
}

void outarr(int *p,int m, int n)
{ int i,j;
  for(i=0;i<m;i++)
  { for(j=0;j<n;j++)
      printf("%5d",*(p+i*n+j));
    printf("\n");
  }
}

main()
{ int a[3][4],*p;
  p=&a[0][0];
  inarr(a[0],3,4);
  outarr(p,3,4);
}
