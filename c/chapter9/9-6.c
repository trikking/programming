#include <stdio.h>
struct candidate
{ char name[20];
  int count;
}list[]={{"invalid",0},{"Zhao",0},{"Qian",0},{"Sun",0},{"Li",0},{"Zhou",0}};
main()
{ int i,n;
  printf("Enter vote\n");
  scanf("%d",&n);
  while(n!=-1)
  { if(n>=1 && n<=5)
      list[n].count++;
    else
    { printf("invalid\n");
      list[0].count++;
    }
    scanf("%d",&n);
  }
  for(i=1;i<=5;i++)
    printf("%s:%d\n",list[i].name,list[i].count);
  printf("%s:%d\n",list[0].name,list[0].count);
}
