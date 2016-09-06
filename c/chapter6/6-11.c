#include <stdio.h>
#include <string.h>
#define N 4
main()
{ char s[N][60];
  char str[60];
  int i,j;
  for(i=0;i<N;i++)
    gets(s[i]);
  for(i=0;i<N-1;i++)
    for(j=i+1;j<N;j++)
      if(strcmp(s[i],s[j])>0)
      { strcpy(str,s[i]);
        strcpy(s[i],s[j]);
        strcpy(s[j],str);
      }
  printf("\nafter sorted:\n");
  for(i=0;i<N;i++)
    puts(s[i]);
}
