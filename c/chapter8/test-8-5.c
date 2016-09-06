#include <stdio.h>
#include <string.h>
char *longstr(char *z[],int n)
{ int i=0;
  char *s=z[0];
  for(i=1;i<n;i++)
    if(strlen(z[i])>strlen(s))
      s=z[i];
  return s;
}

main()
{ char a[5][101],*s[5],*str;
  int i;
  for(i=0;i<5;i++)
  { s[i]=a[i];
    scanf("%s",s[i]);
  }
  str=longstr(s,5);
  printf("The longest string is %s.\n",str);
}
