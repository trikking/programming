#include <stdio.h>
struct list
{ int i;
  char name[4];
  float w;
}tab[5]={{1,"H",1.008},{2,"He",4.0026},{3,"Li",6.941},
         {4,"Be",9.01218},{5,"B",10.81}};
main()
{ struct list *p;
  printf("No\tName\tAtomic Weight\n");
  for(p=tab;p<tab+5;p++)
    //printf("%d\t%s\t%f\n",p->i,p->name,p->w);
    //printf("%d\t%s\t%f\n",(*p).i,(*p).name,(*p).w);
    printf("%d\t%s\t%f\n",tab[0].i,tab[0].name,tab[0].w);
}
