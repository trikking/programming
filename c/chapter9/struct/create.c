#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NEW (struct node *)malloc(sizeof(struct node))
struct node *create()
{ static struct node *h;
  struct node *p,*q;
  char name[20];
  h=NULL;
  printf("name:");
  scanf("%s",name);
  while(strlen(name)>0)
  { p=NEW;
    if(p==NULL)
    { printf("Memory Allocation failure!\n");
      exit(0);
    }
    strcpy(p->name,name);
    printf("tel:");
    scanf("%s",p->tel);
    p->next=NULL;
    if(h==NULL)
      h=p;
    else
      q->next=p;
    q=p;
//    name[0]='\0';
    printf("name:");
    scanf("%s",name);
  }
  return h;
}
