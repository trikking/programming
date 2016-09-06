#include <stdio.h>
main()
{ char s[80];
  int dig[10]={0},space=0,letter=0,other=0,i;
  gets(s);
  for(i=0;s[i]!='\0';i++)
  { if(s[i]>='0' && s[i]<='9')
      dig[s[i]-'0']++;
    else if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
      letter++;
    else if(s[i]==' ')
      space++;
    else
      other++;
  }
  for(i=0;i<10;i++)
    printf("数字%d:%d个  ",i,dig[i]);
  printf("\n");
  printf("空格:%d个\n",space);
  printf("字母:%d个\n",letter);
}
