#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int empID;
    char name[100];
    int age;
};

int main()
{
    int n;
    struct Employee *records;

    // Accepting number of records
    printf("Enter the number of records: ");
    scanf("%d", &n);

    // Allocating memory dynamically
    records = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (records == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Accepting employee details
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for Employee %d\n", i + 1);
        printf("Enter the ID: ");
        scanf("%d", &records[i].empID);
        printf("Enter the name: ");
        scanf("%s", records[i].name);
        printf("Enter the age: ");
        scanf("%d", &records[i].age);
    }

    // Displaying employee details
    printf("\nEmployee Details:\n");
    printf("ID\tName\tAge\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\n", records[i].empID, records[i].name, records[i].age);
    }

    // Deallocating memory
    free(records);

    return 0;
}