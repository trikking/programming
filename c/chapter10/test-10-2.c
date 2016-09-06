#include <stdio.h>
main()
{ FILE *fp;
  int a[5],i;
  char filename[40];
  printf("filename:");
  gets(filename);
  if((fp=fopen(filename,"w"))==NULL)
  { printf("cannot open file %s\n",filename);
    exit(1);
  }
  printf("input a[5]:");
  for(i=0;i<5;i++)
  { scanf("%d",&a[i]);
    //putw(a[i],fp);
    fprintf(fp,"%d ",a[i]);
  }
  fclose(fp);
}
