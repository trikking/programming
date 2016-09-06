#include <stdio.h>
main()
{ int a=1949;
  FILE *fp;
  fp=fopen("a.data","ab");
  printf("ftell=%d,feof=%d\n",ftell(fp),feof(fp));
  fwrite(&a,sizeof(int),1,fp);
  fclose(fp);
}
