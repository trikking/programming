#include <stdio.h>
main()
{ int x[4]={3,11,8,22},*p=x,i,s=1;
  for(i=0;i<4;i++,p++)
    s*=*p; 
  printf("%d\n",s);
}
