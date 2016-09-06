#include <stdio.h>
main()
{ FILE *fp;
  char filename[40];
  int i,n1,n2,x[255],y[255],z,pn;
  printf("filename:");
  gets(filename);
  if((fp=fopen(filename,"rb+"))==NULL)
  { printf("cannot open file %s\n",filename);
    exit(1);
  }
  printf("input n1(length of array x):");
  scanf("%d",&n1);
  printf("input %d numbers:",n1);
  for(i=0;i<n1;i++)
    scanf("%d",&x[i]);
  printf("数组x:");
  for(i=0;i<n1;i++)
    printf("%d  ",x[i]);
  printf("\n");
  pn=sizeof(int);
  fwrite(&n1,pn,1,fp);
  fwrite(x,pn,n1,fp);
  printf("移动前的位置:%d\n",ftell(fp));
  fseek(fp,4*pn,0);
  printf("移动后的位置:%d\n",ftell(fp));
  fread(&z,pn,1,fp);
  printf("第5个数是%d\n",z);
  printf("input z:");
  scanf("%d",&z);
  fseek(fp,-1*pn,1);
  fwrite(&z,pn,1,fp);
  rewind(fp);
  fread(&n2,pn,1,fp);
  printf("%d numbers are:",n2);
  fread(y,pn,n2,fp);
  for(i=0;i<n2;i++)
    printf("%d  ",y[i]);
  printf("\n");
  fclose(fp);
}
