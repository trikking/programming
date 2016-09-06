#include <stdio.h>
main()
{ FILE *fp;
  char filename[40],c;
  int n=0;
  printf("filename:");
  gets(filename);
  if((fp=fopen(filename,"a+"))==NULL)
  { printf("cannot open file %s\n",filename);
    exit(1);
  }
  while((c=getchar())!='#')
    fputc(c,fp);
  rewind(fp);
  c=fgetc(fp);
  while(!feof(fp))
  { n++;  
    c=fgetc(fp);
  }
  fputc('#',fp);
  fputc(n+'0',fp);
  fclose(fp);
}
