#include <stdio.h>
#include <string.h>
#define SIZE 80

char *subcut(char *a,int s,int len);

main()
{ char a[SIZE+1],*p,*substr;
  int s,len;
  p=a;
  printf("Input string:");
  scanf("%s",p);
  printf("Input s,len:");
  scanf("%d,%d",&s,&len);
  substr=subcut(a,s,len);
  printf("%s\n",substr);
}

char *subcut(char *a,int s,int len)
{ static char b[SIZE+1];
  char *p1,*p2=b;
  if(s<1||len<1||strlen(a)<s)
    printf("data input error!\n");
  else
  { for(p1=a+s-1;*p1 && p1<a+s+len-1;)
      *p2++=*p1++;
    *p2='\0';
  }
  return b;
}
