#include <stdio.h>
#include <stdlib.h>
main()
{ struct st
  { int n;
    struct st *next;
  } *p;
  int *q;
  p=(struct st *)malloc(sizeof(struct st));
  q=(int *)malloc(sizeof(int));
  p->n=5;
  p->next=NULL;
  *q=20;
  printf("p->n=%d\tp->next=%x\n",p->n,p->next);
  printf("*q=%d\n",*q);
}
