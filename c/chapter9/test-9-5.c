#include <stdio.h>
#include <stdlib.h>
struct node
{ int n;
  struct node *next;
};
struct node *insert(struct node *head,int n)
{ struct node *p,*q;
  static struct node *h;
  struct node *p0=(struct node *)malloc(sizeof(struct node));
  p0->n=n;
  if(h==NULL)
  { head=p0;
    p0->next=NULL;
  }
  else
  { p=head;
    while(p->n<n && p->next!=NULL)
    { q=p;
      p=p->next;
    }
    if(p->n>=n)
    { if(p==head)   //在表头插入
        head=p0;
      else
        q->next=p0;
      p0->next=p;   //在表中插入
    }
    else
    { p->next=p0;
      p0->next=NULL;
    }
  }
  h=head;
  return h;
}
void *print(struct node *h)
{ struct node *p=h;
  printf("head-->");
  while(p!=NULL)
  { printf("%d-->",p->n);
    p=p->next;
  }
  printf("NULL\n");
}
main()
{ int i,n;
  struct node *head=NULL;
  for(i=0;i<10;i++)
  { printf("input n:");
    scanf("%d",&n);
    head=insert(head,n);
    print(head);
  }
}
