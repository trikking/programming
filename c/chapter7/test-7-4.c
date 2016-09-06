#include <stdio.h>

void func(char s[])
{ int i=0,j;
  while(s[i]!='\0')
  { j=i;
    if(s[j]=='d')
    { while(s[j]!='\0')
      { s[j]=s[j+1];
        j++;
      }
      continue;
    }
    i++;
  }
}
  

main()
{ char s[50];
  printf("Input s:");
  gets(s);
  func(s);
  puts(s);
}
