#include <stdio.h>
main(int argc,char *argv[])
{ FILE *infp,*outfp;
  char infile[40],outfile[40];
  int c;
  if(argc<3)
    if(argc==2)
    { printf("output filename:");
      gets(outfile);
      argv[2]=outfile;
    }
    else if(argc==1)
    { printf("input filename:");
      gets(infile);
      printf("output filename:");
      gets(outfile);
      argv[1]=infile;
      argv[2]=outfile;
    }
  if((infp=fopen(argv[1],"r"))==NULL)
  { printf("Cannot open file %s.\n",argv[1]);
    exit(1);
  }
  if((outfp=fopen(argv[2],"w"))==NULL)
  { printf("Cannot open file %s.\n",argv[2]);
    exit(1);
  }
  c=fgetc(infp);
  while(!feof(infp))
  { fputc(c,outfp);
    c=fgetc(infp);
  }
  printf("cp OK!\n");
}
