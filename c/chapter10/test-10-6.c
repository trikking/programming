#include <stdio.h>
#include <string.h>

struct stock
{ char no[20];
  char name[40];
  float price;
  int inventory;
  int deleted;
};

void create(char *filename)
{ FILE *fp;
  if((fp=fopen(filename,"wb"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  printf("input no:");
  gets(s.no);
  while(strlen(s.no)>0)
  { printf("input name:");
    gets(s.name);
    printf("input price:");
    scanf("%f",&s.price);
    getchar();
    printf("input inventory:");
    scanf("%d",&s.inventory);
    getchar();
    s.deleted=0;
    fwrite(&s,sizeof(struct stock),1,fp);
    printf("input no:");
    gets(s.no);
  }
 printf("records created!\n\n");
 fclose(fp);
}

void insert(char *filename)
{ FILE *fp;
  if((fp=fopen(filename,"ab"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  printf("input no to be inserted:");
  gets(s.no);
  printf("input name:");
  gets(s.name);
  printf("input price:");
  scanf("%f",&s.price);
  getchar();
  printf("input inventory:");
  scanf("%d",&s.inventory);
  getchar();
  s.deleted=0;
  fwrite(&s,sizeof(struct stock),1,fp);
  printf("record inserted!\n\n");
  fclose(fp);
}

void delete(char *filename)
{ FILE *fp;
  char no[20];
  if((fp=fopen(filename,"rb+"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  printf("input no to be deleted:");
  gets(no);
  fread(&s,sizeof(struct stock),1,fp);
  while(!feof(fp))
  { if(strcmp(no,s.no)==0)
    { s.deleted=1;
      fseek(fp,-1*sizeof(struct stock),1);
      fwrite(&s,sizeof(struct stock),1,fp);
      printf("record deleted!\n\n");
      break;
    }
    fread(&s,sizeof(struct stock),1,fp);
  }
  fclose(fp);
}

void print(char *filename)
{ FILE *fp;
  if((fp=fopen(filename,"rb+"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  fread(&s,sizeof(struct stock),1,fp);
  printf("all goods:\n");
  printf("no\tname\tprice\tinventory\n",s.no);
  while(!feof(fp))
  { if(s.deleted==0)
    { printf("%s\t%s\t%6.2f\t%d\n",s.no,s.name,s.price,s.inventory);
    }
    fread(&s,sizeof(struct stock),1,fp);
  }
  fclose(fp);
}
 
void add_inventory(char *filename)
{ FILE *fp;
  char no[20];
  int n;
  if((fp=fopen(filename,"rb+"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  printf("input no to add inventory:");
  gets(no);
  fread(&s,sizeof(struct stock),1,fp);
  while(!feof(fp))
  { if(s.deleted==0)
      if(strcmp(no,s.no)==0)
      { printf("input inventory to add:");
        scanf("%d",&n);
        getchar();
        s.inventory+=n;
        fseek(fp,-1*sizeof(struct stock),1);
        fwrite(&s,sizeof(struct stock),1,fp);
        printf("inventory added!\n");
        break;
      }
    fread(&s,sizeof(struct stock),1,fp);
  }
  fclose(fp);
}
  
void sub_inventory(char *filename)
{ FILE *fp;
  char no[20];
  int n;
  if((fp=fopen(filename,"rb+"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  printf("input no to sub inventory:");
  gets(no);
  fread(&s,sizeof(struct stock),1,fp);
  while(!feof(fp))
  { if(s.deleted==0)
      if(strcmp(no,s.no)==0)
      { printf("input inventory to sub:");
        scanf("%d",&n);
        getchar();
        s.inventory-=n;
        fseek(fp,-1*sizeof(struct stock),1);
        fwrite(&s,sizeof(struct stock),1,fp);
        printf("inventory subed!\n");
        break;
      }
    fread(&s,sizeof(struct stock),1,fp);
  }
  fclose(fp);
}

void print_low_inventory_goods(char *filename)
{ FILE *fp;
  if((fp=fopen(filename,"rb+"))==NULL)
  { printf("cannot open file %s\n,exit!",filename);
    exit(1);
  }
  struct stock s;
  fread(&s,sizeof(struct stock),1,fp);
  printf("goods with low inventory:\n",s.no);
  printf("no\tname\tprice\tinventory\n",s.no);
  while(!feof(fp))
  { if(s.deleted==0 && s.inventory<10)
    { printf("%s\t%s\t%6.2f\t%d\n",s.no,s.name,s.price,s.inventory);
    }
    fread(&s,sizeof(struct stock),1,fp);
  }
  fclose(fp);
}

main()
{ char filename[40];
  int choice;
  printf("input filename:");
  gets(filename);
  printf("\n\n*********\n1.create\n2.insert\n3.delete\n");
  printf("4.print\n5.add inventory\n6.sub inventory\n");
  printf("7.print goods in low inventory\n0.exit\n*********\n\n");
  printf("input choice:");
  scanf("%d",&choice);
  getchar();
  while(choice)
  { switch(choice)
    {case 1:create(filename);
            break;
     case 2:insert(filename);
            break;
     case 3:delete(filename);
            break;
     case 4:print(filename);
            break;
     case 5:add_inventory(filename);
            break;
     case 6:sub_inventory(filename);
            break;
     case 7:print_low_inventory_goods(filename);
            break;
     case 0:break;
    }
    printf("\n\n*********\n1.create\n2.insert\n3.delete\n");
    printf("4.print\n5.add inventory\n6.sub inventory\n");
    printf("7.print goods in low inventory\n0.exit\n*********\n\n");
    printf("input choice:");
    scanf("%d",&choice);
    getchar();
  }
}
