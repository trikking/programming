#include <stdio.h>
main()
{ FILE *fp;
  int n,i,a[255];
  char filename[40];
  printf("input filename:");
  gets(filename);
  if((fp=fopen(filename,"w"))==NULL)
  { printf("cannot open file %s\n",filename);
    exit(1);
  }
  printf("input n:");
  scanf("%d",&n);
  printf("input n numbers:");
  for(i=0;i<n;i++)
  { scanf("%d",&a[i]);
    putw(a[i],fp);
  }
  //fwrite(a,sizeof(int),n,fp);
  fclose(fp);
}
