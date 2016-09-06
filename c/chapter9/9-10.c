#include <stdio.h>
struct complex
{ float re;
  float im;
}
main()
{ struct complex x,y,z;
  void multiplier(struct complex *,struct complex *,struct complex *);
  x.re=3.2;
  x.im=1.5;
  y.re=2.7;
  y.im=4.6;
  multiplier(&x,&y,&z);
  printf("(%f+%fi)*(%f+%fi)=%f+%fi\n",x.re,x.im,y.re,y.im,z.re,z.im);
}
void multiplier(struct complex *cx,struct complex *cy,struct complex *cz)
{ cz->re=cx->re*cy->re-cx->im*cy->im;
  cz->im=cx->re*cy->im+cx->im*cy->re;
}
