#include <stdio.h>
struct student
{ char no[20];
  char name[20];
  int score[5];
  int sum;
};
void get_score(struct student *stu,int n)
{ int i,j;
  for(i=0;i<n;i++,stu++)
  { printf("number:");
    scanf("%s",stu->no);
    printf("name:");
    scanf("%s",stu->name);
    for(j=0;j<5;j++)
    { printf("score of sub%d:",j+1);
      scanf("%d",&(stu->score)[j]);
    }
  }
}
void cal_sum(struct student *stu,int n)
{ int i,j;
  for(i=0;i<n;i++,stu++)
  { stu->sum=0;
    for(j=0;j<5;j++)
      stu->sum+=stu->score[j];
  }
}
void print_info(struct student *stu,int n)
{ int i;
  printf("no\tname\tsum\n");
  for(i=0;i<n;i++,stu++)
    printf("%s\t%s\t%d\n",stu->no,stu->name,stu->sum);
}
main()
{ struct student s[10],*stu;
  stu=s;
  get_score(stu,10);
  stu=s;
  cal_sum(stu,10);
  stu=s;
  print_info(stu,10);
} 
