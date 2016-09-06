#include <stdio.h>

main()
{ int a[3][3]={{0,1,2},{10,11,12},{20,21,22}};
  int i,j,(*p)[3];
  for(p=a,i=0;i<3;i++)
  { for(j=0;j<3;j++)
      printf("%4d",*(*(p+i)+j));
    printf("\n");
  }
  for(p=a;p<a+3;p++)
  { for(j=0;j<3;j++)
      printf("%4d",*(*p+j));
    printf("\n");
  }
}
