#include <stdio.h>
main()
{ FILE *fp;
  char filename[40];
  int i;
  char a[5][50];
  printf("filename:");
  gets(filename);
  if((fp=fopen(filename,"w"))==NULL)
  { printf("cannot open file %s\n",filename);
    exit(1);
  }
  for(i=0;i<5;i++)
  { printf("input str:");
    gets(a[i]);
    puts(a[i]);
    fputs(a[i],fp);
    fputc('\n',fp);
  }
  fclose(fp);
}
