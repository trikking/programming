#include <stdio.h>
#include <string.h>
main()
{ FILE *fp;
  char filename[40],str[81];
  printf("input filename:");
  gets(filename);
  if((fp=fopen(filename,"w"))==NULL)
  { printf("file %s open error\n",filename);
    exit(1);
  }
  printf("input str:\n");
  while(strlen(gets(str))!=0)
  { fputs(str,fp);
    fputc('\n',fp);
  }
  fclose(fp);
  printf("outfile:\n");
  fp=fopen(filename,"r");
  while((fgets(str,81,fp))!=NULL)
    printf("%s",str);
  fclose(fp);
}
