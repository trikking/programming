#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NEW (struct node *)malloc(sizeof(struct node))
struct node
{ char name[20],tel[9];
  struct node *next;
};
#include "9-15.c"
#include "9-16.c"
struct node *create()
{ static struct node *h;
  struct node *p,*q;
  char name[20];
  h=NULL;
  printf("name:");
  scanf("%s",name);
  //printf("length is %d\n",strlen(name));
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
    name[0]='\0';
    printf("name:");
    scanf("%s",name);
    //printf("length is %d\n",strlen(name));
  }
  return h;
}
main()
{ struct node *head,*p;
  char s[20];
  head=create();
  p=head;
  while(p!=NULL)
  { printf("%s\t%s\n",p->name,p->tel);
    p=p->next;
  }
/*
  printf("Input a name to be deleted:");
  scanf("%s",s);
  head=delnode(head,s);
  p=head;
  while(p!=NULL)
  { printf("%s\t%s\n",p->name,p->tel);
    p=p->next;
  }
*/
  struct node newnode={"aaa","3345678",NULL};
  printf("Input a name to be inserted:");
  scanf("%s",&newnode.name);
  head=insert(head,&newnode,"xxxx");
  p=head;
  while(p!=NULL)
  { printf("%s\t%s\n",p->name,p->tel);
    p=p->next;
  }
}
