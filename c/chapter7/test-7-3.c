#include <stdio.h>
void func(char s[])
{ int i=0;
  while(s[i]!='\0')
  { if(s[i]>='A' && s[i]<='Z')
      s[i]=s[i]+('a'-'A');
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
