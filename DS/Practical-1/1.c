#include <stdio.h>
int main()
   {
    struct student 
    {
    char name[50];
    char Idno[10];
    float marks;
   };

  int n,m,i; 
  printf("Enter how many Student Data You Want to enter : ");
  scanf("%d",&n);

  struct student s[n];

  for (i = 0; i < n;i++)
  {
      printf("Enter Student  name  [%d]: ",i);
      scanf("%s", s[i].name);
      printf("Enter Student IDno  [%d]: ",i);
      scanf("%s", s[i].Idno);
      printf("Enter marks for student [%d]: ",i);
      scanf("%f", &s[i].marks);
  }

  printf("Enter Mininum marks");
  scanf("%d",&m);


   for (i = 0; i < n;i++)
   {
       if(s[i].marks<m)
       {
           printf("\n---------\nStudent name=%s\n",s[i].name);
           printf("Student Idno=%s\n",s[i].Idno);
           printf("Student Marks=%0.2f\n",s[i].marks);
       }
   }
}