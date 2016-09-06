#include <stdio.h>
main()
{ int a[10],i,*p;
  for(i=0;i<10;i++)
    scanf("%d",a+i);
  for(i=0;i<10;i++)
    printf("%4d",*(a+i));
  printf("\n");
  for(p=a;i<10;i++)
    printf("%4d",*(p+i));
  printf("\n");
  for(p=a;p<a+10;p++)
    scanf("%d",p);
  for(p=a;p<a+10;p++)
    printf("%4d",*p);
  printf("\n");
  for(p=a;p<a+10;)
    printf("%4d",*p++);
  //printf("%4d",p[-2]);
  printf("\n");
}
