#include <stdio.h>

void turn(int arra[][4],int arrb[][3]);

main()
{ int i,j;
  int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int b[4][3];
  printf("array a:\n");
  for(i=0;i<3;i++)
  { for(j=0;j<4;j++)
      printf("%5d",a[i][j]);
    printf("\n");
  }
  turn(a,b);
  printf("array b:\n");
  for(i=0;i<4;i++)
  { for(j=0;j<3;j++)
      printf("%5d",b[i][j]);
    printf("\n");
  }
}

void turn(int arra[][4],int arrb[][3])
{ int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<4;j++)
      arrb[j][i]=arra[i][j];
}
