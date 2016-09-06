#include <stdio.h>
#define N 10
int min(int a[])
{ int min=a[0],i;
  for(i=1;i<N;i++)
    if(min>a[i]) 
      min=a[i];
  return min;
}

int max(int a[])
{ int max=a[0],i;
  for(i=1;i<N;i++)
    if(max<a[i]) 
      max=a[i];
  return max;
}

void count(int a[], int c[])
{ int i;
  for(i=0;i<N;i++)
  if(a[i]>=90)
      c[0]++;
  else if(a[i]>=80)
      c[1]++;
  else if(a[i]>=70)
      c[2]++;
  else if(a[i]>=60)
      c[3]++;
  else if(a[i]<60)
      c[4]++;
}

main()
{ int a[N],i,minimum,maximum,c[5]={0};
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  minimum=min(a);
  maximum=max(a);
  printf("min=%d,max=%d\n",minimum,maximum);
  count(a,c);
  for(i=0;i<5;i++)
    printf("%d\n",c[i]);
}
