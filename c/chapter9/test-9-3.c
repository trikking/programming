#include <stdio.h>
#include <stdlib.h>
struct ch
{ char c;
  struct ch *next;
};
struct ch *create()
{ char a;
  static struct ch *head=NULL;
  struct ch *q=head;
  while((a=getchar())!='#')
  { struct ch *p=(struct ch *)malloc(sizeof(struct ch));
    p->c=a;
    p->next=NULL;
    if(head==NULL)
      head=p;
    else
      q->next=p;
    q=p;
  } 
  return head;
}
main()
{ struct ch *h=create(),*p;
  printf("head-->");
  for(p=h;p!=NULL;p=p->next)
    printf("%c-->",p->c);
  printf("NULL\n");
}
