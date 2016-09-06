#include <stdio.h>
#include <string.h>
main()
{ FILE *fp;
  char filename[40];
  struct tel
  { char name[20];
    char tel[9];
  }inrec,outrec;
  printf("filename:");
  gets(filename);
  if((fp=fopen(filename,"wb"))==NULL)
  { printf("Cannot open file %s\n");
    exit(1);
  }
  printf("name:");
  gets(inrec.name);
  while(strlen(inrec.name)>0)
  { printf("tel:");
    gets(inrec.tel);
    fwrite(&inrec,sizeof(struct tel),1,fp);
    printf("name:");
    gets(inrec.name);
  }
  fclose(fp);
  printf("outfile:\n");
  fp=fopen(filename,"rb");
  fread(&outrec,sizeof(struct tel),1,fp);
  while(!feof(fp))
  { printf("%s,%s\n",outrec.name,outrec.tel);
    fread(&outrec,sizeof(struct tel),1,fp);
  }
  fclose(fp);
}
