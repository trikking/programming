#include <stdio.h>
void inarr(int (*p)[4],int m)
{ int i,j;
  for(i=0;i<m;i++)
    for(j=0;j<4;j++)
      scanf("%d",*(p+i)+j);
}

void outarr(int (*p)[4],int m)
{ int i,j;
  for(i=0;i<m;i++)
  { for(j=0;j<4;j++)
      printf("%5d",p[i][j]);
    printf("\n");
  }
}

main()
{ int a[3][4],(*p)[4];
  p=a;
  inarr(a,3);
  outarr(p,3);
}
