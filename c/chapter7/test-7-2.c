#include <stdio.h>
#include <math.h>
int prime(int m)
{ int prime=1,i;
  if(m<=0) 
  { printf("m<=0,data err!");
    prime=0;
  } 
  else if(m==1) 
    prime=0;
  else if(m==2)
    prime=1;
  else
  { for(i=2;i<=sqrt(m);i++)
    { if(m%i==0)
      { prime=0;
        break;
      }
    }
  }
  if(prime) printf("Yes\n");
  else printf("No\n");
}

main()
{ int n;
  printf("Input n:");
  scanf("%d",&n);
  prime(n);
} 
