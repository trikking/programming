#include <stdio.h>
#include <stdlib.h>
struct f
{ int a,b;
  struct f *next;
};
struct f *create(int n)
{ printf("输入一元%d次多项式的指数和系数\n",n);
  int i;
  static struct f *head;
  struct f *q=head;
  do
  { printf("指数:");
    scanf("%d",&i);
    if(i<0)
      break;
    struct f *p=(struct f *)malloc(sizeof(struct f));
    p->b=i;
    printf("系数:");
    scanf("%d",&p->a);
    p->next=NULL;
    if(head==NULL)
      head=p;
    else
      q->next=p;
    q=p;
  }while(1);
  return head;
}
struct f *print(struct f *p,int n)
{ printf("f(x)=");
  while(p!=NULL)
  { printf("+%d",p->a);
    if(p->b>1)
      printf("x^%d",p->b);
    else if(p->b==1)
      printf("x",p->b);
    p=p->next;
  } 
  printf("\n");
}
main()
{ int n;
  printf("输入n:");
  scanf("%d",&n);
  struct f *h=create(n),*p=h;
  print(h,n);
}
