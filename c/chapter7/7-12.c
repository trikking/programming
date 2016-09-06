#include <stdio.h>

void printarr(int a[]);
void sort(int a[],int n);

main()
{ int a[10]={11,22,63,97,58,80,45, 32,73,36};
  printf("Before sorted:");
  printarr(a);
  putchar('\n');
  sort(a,10);
  printf("After sorted:");
  printarr(a);
  putchar('\n');
}

/* 打印数组函数 */
void printarr(int a[])
{ int i;
  for(i=0;i<10;i++)
    printf("%5d",a[i]);
}

/* 排序数组函数 */
void sort(int a[],int n)
{ int i,j,t;
  for(i=1;i<n;i++)
    for(j=0;j<n-i;j++)
      if(a[j]>a[j+1])
        {t=a[j];a[j]=a[j+1];a[j+1]=t;}
}
