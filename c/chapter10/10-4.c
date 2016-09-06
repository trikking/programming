#include <stdio.h>
#include <string.h>
main()
{ FILE *fp;
  char filename[40],str[81];
  int i,a,b,c,x,y,z;
  printf("input filename:");
  gets(filename);
  if((fp=fopen(filename,"w"))==NULL)
  { printf("filename %s open error!\n",filename);
    exit(1);
  }
  for(i=1;i<3;i++)
  { printf("a,b,c=");
    scanf("%d,%d,%d",&a,&b,&c);
    fprintf(fp,"%d %d %d\n",a,b,c);
  }
  fclose(fp);
  printf("outfile:\n");
  fp=fopen(filename,"r");
  fgets(str,81,fp);
  printf("1.%s",str);
  fscanf(fp,"%d %d %d\n",&x,&y,&z);
  printf("2.%d %d %d\n",x,y,z);
  fclose(fp);
}
