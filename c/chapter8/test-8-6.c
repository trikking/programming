#include <stdio.h>
void *merge_sort(int *p1,int *p2,int *p)
{ 
  int i,j,k;
  for(i=0,j=0;i<5||j<5;p++)
  { if(*p1<*p2 && i<5)
    { *p=*p1;
      p1++;
      i++;
    }
    else if(*p1>=*p2 && j<5)
    { *p=*p2;
      p2++;
      j++;
    }
  }
}
main()
{ int a[5],b[5],c[10],i;
  printf("Input array a:");
  for(i=0;i<5;i++)
    scanf("%d",&a[i]);
  printf("Input array b:");
  for(i=0;i<5;i++)
    scanf("%d",&b[i]);
  merge_sort(a,b,c);
  printf("merge_sort of array a and b: ");
  for(i=0;i<10;i++)
    printf("%5d",c[i]);
  printf("\n");
}
