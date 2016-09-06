#include <stdio.h>
#include <string.h>
void insert_str(char *a,char *b,int pos)
{ int i,m,n;
  m=strlen(b);
  n=strlen(a);
  for(i=1,b+=m;i<=m-pos+1;i++,b--)
    *(b+n)=*b;
  b++;
  for(i=1;i<=n;i++)
    *b++=*a++;
}

main()
{ char s1[101]="abcde",s2[101]="0123456789";
  char *a=s1,*b=s2;
  int pos=3;
  insert_str(a,b,pos);
  puts(b);
}
