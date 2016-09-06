#include <stdio.h>

void scat(char s1[],char s2[]);

main()
{ char s1[50],s2[50];
  gets(s1);
  gets(s2);
  scat(s1,s2);
  printf("s1 --> %s\n",s1);
  printf("s2 --> %s\n",s2);
}

void scat(char s1[],char s2[])
{ int i=0,j=0;
  while(s1[i])
    i++;
  while(s1[i++]=s2[j++]);
}
