#include <stdio.h>
#include <string.h>
main()
{ char name[5][20],*strp[5],*min,*temp;
  int i,j,t;
  for(i=0;i<5;i++)
  { printf("Input name %d:",i+1);
    scanf("%s",name[i]);
    strp[i]=name[i];
  }
  for(i=0;i<5;i++)
    printf("%10s",strp[i]);
  printf("\n");
  for(i=0;i<4;i++)
  { min=strp[i];
    for(j=i+1;j<5;j++)
    { if(strcmp(min,strp[j])>0)
      { min=strp[j];
        t=j;
      }
    }
    if(min!=strp[i])
    { temp=strp[i];strp[i]=strp[t];strp[t]=temp;}
  }
  for(i=0;i<5;i++)
    printf("%10s",strp[i]);
  printf("\n");
}
