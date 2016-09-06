#include<string.h>
main( )
{ char *str1="This is a string.";
char str2[80],*p1,*p2;
int i,j,n1,n2,found;
gets(str2);
n1=strlen(str1); /* 求 str1 的串长 */
n2=strlen(str2); /* 求 str2 的串长 */
found=0; /* 设标志为 0，表示未找到 */
for (i=0; i<=n1-n2 && !found; i++)
{ p1=str1+i; /* 设置每次查找起始位置 */
p2=str2;
found=1; /* 预测本次查找是成功的 */
for (j=0; j<n2; j++)
if (*p1++!=*p2++) /* 有一对字符不等， */
{ found=0; /* 则宣告本次查找失败 */
break; /* 跳出循环结束本轮查找 */
}
}
if(found) 
  printf("%d\n",i);
else 
  printf("0\n");
}
