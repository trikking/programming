#include <stdio.h>
#include <stdlib.h>
#define NEW (struct node *)malloc(sizeof(struct node))

struct node
{ char name[20];
  char tel[20];
  struct node *next;
};

#include "struct/create.c"
#include "struct/delete.c"
#include "struct/print.c"
#include "struct/insert.c"

main()
{ struct node *create();
  struct node *delnode(struct node *,char *);
  struct node *insert(struct node *,struct node *,char *);
  void print(struct node *);
  struct node *head=NULL,*stu;
  char s[80],name[20];
  int c;
  do
  { do
    { printf("\n****MENU****\n");
      printf("1.Create a list\n");
      printf("2.Print a list\n");
      printf("3.Delete a node\n");
      printf("4.Insert a node\n");
      printf("0.Quit\n");
      printf("Enter your choice(0-4):");
      scanf("%d",&c);
    }while(c<0 || c>4);
    switch(c)
    { case 1:head=create();break;
      case 2:print(head);break;
      case 3:printf("\nInput a name to be deleted:");
             scanf("%s",name);
             head=delnode(head,name);
             break;
      case 4:stu=NEW;
             printf("\nInput a new node\n");
             printf("name:");
             scanf("%s",stu->name);
             printf("tel:");
             scanf("%s",stu->tel);
             stu->next=NULL;
             printf("\nInsert position\n");
             printf("name:");
             scanf("%s",name);
             head=insert(head,stu,name);
    }
  }while(c);
}
