#include <stdio.h>
#include <string.h>

struct node *insert(struct node *head,struct node *p0,char *x)
{ struct node *q,*p;
  static struct node *h;
  if(head==NULL)
  { head=p0;
    p0->next=NULL;
  }
  p=head;
  while(strcmp(p->name,x)!=0 && p->next!=NULL)
  { q=p;
    p=p->next;
  }
  if(strcmp(p->name,x)==0)
  { if(p==head)
      head=p0;
    else
      q->next=p0;
    p0->next=p;
  }
  else
  { p->next=p0;
    p0->next=NULL;
  }
  h=head;
  return h;
}
