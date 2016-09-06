#include <stdio.h>

main()
{ void calc(float x,float y, char opr);
  float a,b;
  char opr;
  printf("Input expression:");
  scanf("%f%c%f",&a,&opr,&b);
  calc(a,b,opr);
}

void calc(float x,float y,char opr)
{ switch(opr)
  { case '+' : printf("%f%c%f=%f\n",x,opr,y,x+y);return;
    case '-' : printf("%f%c%f=%f\n",x,opr,y,x-y);return;
    case '*' : printf("%f%c%f=%f\n",x,opr,y,x*y);return;
    case '/' : printf("%f%c%f=%f\n",x,opr,y,x/y);return;
    default : printf("Operation err!\n");
  }
}
