#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node *delnode(struct node *head,char *x)
{ struct node *q,*p;
  static struct node *h;
  if(head==NULL)
  { printf("error,NULL list,return!\n");
    return head;
  }
  p=head;
  while(strcmp(p->name,x)!=0 && p->next!=NULL)
  { q=p;
    p=p->next;
  }
  if(strcmp(p->name,x)==0)
  { if(p==head)
      head=p->next;
    else
    { q->next=p->next;
      free(p);
    }
  }
  else
    printf("Not found!\n");
  h=head;
  return h;
}
