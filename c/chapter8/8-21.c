#include <stdio.h>
int length(char *s)
{ char *t;
  //for(t=s;*t;t++);
  t=s;
  while(*t++);
  return (t-1-s);
}
main()
{ char *s="I am a student!";
  printf("strlen=%d\n",length(s));
}
