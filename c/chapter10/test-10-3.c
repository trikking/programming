#include <stdio.h>
main()
{ FILE *fp;
  char filename[40],c;
  printf("filename:");
  gets(filename);
  if((fp=fopen(filename,"r"))==NULL)
  { printf("cannot open file %s\n",filename);
    exit(1);
  }
  c=fgetc(fp);
  while(!feof(fp))
  { putchar(c);
    c=fgetc(fp);
  }
  fclose(fp);
}
