#include <stdio.h>

main()
{ int a[3][3]={{0,1,2},{10,11,12},{20,21,22}},i,j,*p;
  for(p=a[0],i=0;i<3;i++)
  { for(j=0;j<3;j++)
      printf("%4d",*(p+i*3+j));
    printf("\n");
  }
  for(p=a[0];p<a[0]+9;p++)
  { if((p-a[0])%3==0)
      printf("\n");
    printf("%4d",*p);
  }
  printf("\n");
}
