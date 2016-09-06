#include <stdio.h>
main()
{ int y[4][4],(*p)[4]=y,i,j,m=0,n=0;
  for(i=0;i<4;i++)
    for(j=0;j<4;j++)
      scanf("%d",*(p+i)+j);
  for(i=0;i<4;i++)
  { for(j=0;j<4;j++)
    { printf("%5d",*(*(p+i)+j));
      if(i==j)
        m+=*(*(p+i)+j);
      if(i+j==3)
        n+=*(*(p+i)+j);
    }
    printf("\n");
  }
  printf("主对角线=%d,次对角线=%d\n",m,n);
}
