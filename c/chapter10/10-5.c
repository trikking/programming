#include <stdio.h>
main()
{ FILE *fp;
  char filename[40];
  int i,n1=5,n2,x[5]={10,22,36,48,59},y[5];
  printf("finename:");
  gets(filename);
  if((fp=fopen(filename,"wb"))==NULL)
  { printf("Can't open the %s\n",filename);
    exit(0);
  }
  putw(n1,fp);
  for(i=0;i<n1;i++)
    putw(x[i],fp);
  fclose(fp);
  printf("outfile:\n");
  fp=fopen(filename,"rb");
  n2=getw(fp);
  for(i=0;i<n2;i++)
  { y[i]=getw(fp);
    printf("%d ",y[i]);
  }
  printf("\n");
  fclose(fp);
}
