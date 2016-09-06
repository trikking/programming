#include <stdio.h>
enum weekday
{ Mon=1,Tue,Wed,Thu,Fri,Sat,Sun
};
char *name[8]={"error","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
main()
{ enum weekday d;
  printf("input today's number:");
  scanf("%d",&d);
  if(d>0&&d<7)
    d++;
  else if(d==7)
    d=1;
  else d=0;
  if(d)
    printf("tomorrow is %s\n",name[d]);
  else
    printf("%s\n",name[d]);
}
