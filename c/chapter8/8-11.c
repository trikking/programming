#include <stdio.h>
#include <string.h>
main()
{ char c[80],*str="abcdefghijk",*p;
  int m,n,i;
  printf("m,n=");
  scanf("%d,%d",&m,&n);
  if(m>strlen(str)||m<=0||n<=0)
  { printf("NULL\n");
    return;
  }
  else 
    for(p=str+m-1,i=0;i<n;i++,p++)
    { c[i]=*p;
      if(*p=='\0')
        break;
    }
  if(i==n)
    c[i]='\0';
  puts(str);
  puts(c);
}
