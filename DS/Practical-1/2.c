#include <stdio.h>
int main()
   {
    struct student 
    {
    char name[50];
    char Idno[10];
    float marks[4];
    float total;
    float per;
   };

  int i,n=10;
  float temp=0;
  struct student s[n];

  for (i = 0; i < n;i++)
  {
      printf("Enter Student  name  [%d]: ",(i+1));
      scanf("%s", s[i].name);
      printf("Enter Student IDno  [%d]: ",(i+1));
      scanf("%s", s[i].Idno);
      
      for(int j=0;j<5;j++)
      {
         printf("Enter marks for student [%d] Subject [%d]: ",(i+1),(j+1));
         scanf("%f", &s[i].marks[j]);
      }
      printf(" \n ********************************************** \n");
  }

    for (i = 0; i < n;i++)
    {
        printf(" \n **********************************************");
        printf(" \n Student name=%s",s[i].name);
        printf(" \n Student Idno=%s",s[i].Idno);
        //s[i].total=0;
        for(int j=0;j<5;j++)
        {

       printf(" \n Marks for student [%d] Subject [%d]=%f:",(i+1),(j+1),s[i].marks[j]);
       temp=temp+s[i].marks[j];
        }
        printf(" \n Total Marks=%f",temp);
        s[i].total=temp;
        temp=0;
        printf(" \n Total Marks=%f",s[i].total);
        s[i].per=(((s[i].total)*100)/500);
        printf(" \n Total Percentage=%f",s[i].per);
        printf(" \n **********************************************");

    }
    return 0;
 }



