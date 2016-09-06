#include <stdio.h>
#include <string.h>
main()
{ char c1[80],c2[80],*str1,*str2,*p1,*p2;
  int i,j,n1,n2,found=0;
  str1=c1;
  str2=c2;
  gets(str1);
  gets(str2);
  n1=strlen(str1);
  n2=strlen(str2);
  for(i=0;i<=n1-n2&&!found;i++)
  { p1=str1+i;
    p2=str2;
    found=1;
    for(j=0;j<n2;j++)
    { if(*p1==*p2)
      { p1++;
        p2++;
      }
      else 
      { found=0;
        break;
      }
    }
  }
  if(found)
    printf("Yes,%d\n",i);
  else
    printf("No\n");
}
