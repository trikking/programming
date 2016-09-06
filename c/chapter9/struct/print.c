#include <stdio.h>
void print(struct node *head)
{ struct node *p;
  p=head;
  while(p!=NULL)
  { printf("%s\t%s\n",p->name,p->tel);
    p=p->next;
  }
}
