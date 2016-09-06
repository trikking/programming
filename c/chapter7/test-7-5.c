#include <stdio.h>
func(int a[3][3])
{ int max[3],i,j,t;
  for(i=0;i<3;i++)
  { max[i]=a[i][0];
    for(j=1;j<3;j++)
      if(a[i][j]>max[i])
        max[i]=a[i][j];
    printf("row %d:max is %d\n",i+1,max[i]);
  }
}

main()
{ int a[3][3],i,j;
  printf("Input a[3][3]:");
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      scanf("%d",&a[i][j]);
  func(a);
}
