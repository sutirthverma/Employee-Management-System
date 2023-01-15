// Functions
/*
1) Add employee
2) Delete employee
3) Show employee
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TotalEmp 100
#define buff 20
// Dependent Structure ->
// Address of Employee
typedef struct
{
    char city[buff];
    char state[buff];
    char country[buff];
} address;

// Parent Structure ->
// Employee Main Structure
typedef struct
{
    char name[20];
    int employeeID;
    char department[20];

    address address;
} employee;

employee emp[100];
// Starting Employees
int i = 0;


void nullAtEnd(int i,employee emp[], char *dataMemb)
{
    if(strcmp(dataMemb, "name") == 0)
        emp[i].name[strlen(emp[i].name) - 1] = '\0';
    else if(strcmp(dataMemb, "department") == 0)
        emp[i].department[strlen(emp[i].department) - 1] = '\0';
    else if(strcmp(dataMemb, "city") == 0)
        emp[i].address.city[strlen(emp[i].address.city) - 1] = '\0';
    else if(strcmp(dataMemb, "state") == 0)
        emp[i].address.state[strlen(emp[i].address.state) - 1] = '\0';
    else if(strcmp(dataMemb, "country") == 0)
        emp[i].address.country[strlen(emp[i].address.country) - 1] = '\0';

}


//(1)Add Employee
void addEmployee(int size)
{
    for (; i < size; i++)
    {
        // printf("\nEnter Employee Name: ");
        // fgets(emp[i].name, buff, stdin);
        // nullAtEnd(i,emp,emp->name);


        printf("\nEnter Employee ID: ");
        scanf("%d", &emp[i].employeeID);

        getchar(); //getchar() is used to clear the buffer.

        printf("\nEnter Department:");
        fgets(emp[i].department, buff, stdin);
        nullAtEnd(i,emp, emp->department);

        printf("\nEnter Address of the Employee %d: ", emp[i].employeeID);

        printf("\nCity: ");
        fgets(emp[i].address.city, buff, stdin);
        nullAtEnd(i,emp, emp->address.city);

        printf("\nState: ");
        fgets(emp[i].address.state, buff, stdin);
        // nullAtEnd(i,emp, emp->address.state);
        emp[i].address.state[strlen(emp[i].address.state) - 1] = '\0';


        printf("\nCountry: ");
        fgets(emp[i].address.country, buff, stdin);
        // nullAtEnd(i,emp, emp->address.country);


    }
}

//(3)Print Employee
void empDetails(int empID)
{
    for(int j = 0; j < i; j++)
    {
        if(emp[j].employeeID == empID)
        {
            printf("\n\n\nEmployee Details: ");
            printf("\n\nEmployee Name: %s", emp[j].name);

            printf("\nEmployee ID: %d",emp[j].employeeID);
            
            printf("\nEmployee Department: %s", emp[j].department);

            printf("Employee Address:%s,%s,%s",emp[j].address.city, emp[j].address.state, emp[j].address.country);
        }
        else
            printf("Error: Enter a valid ID.");
    }
}

 int main()
{
   
    addEmployee(1);
    empDetails(22196);
    return 0;
}