#define MAX 20

void addEmp(int numOfSize, employee emp[]);
void empDetails(int empID);
void nullAtEnd(employee emp[], char *dataMemb);

int totalEmps = 1;

// Admin Landing Page
int admin()
{
    int option = 0, numOfEmp = 1, id = 1;

    printf("\nAdmin:");
    printf("\n(1)ADD EMPLOYEE.");
    printf("\n(2)ADD MULTIPLE EMPLOYEES.");
    printf("\n(3)VIEW EMPLOYEE DETAILS.");
    printf("\n(4)VIEW EMPLOYEES DETAILS ACCORIDING TO DEPARTMENTS.");
    printf("\n(5)ADD EMPLOYEES MEETINGS AND MESSAGES.");
    printf("\n(6)LOG OUT.");

    printf("\nEnter the respective codes to open the options: ");
    scanf("%d", &option);

    if (option >= 1 && option <= 6)
    {
        switch (option)
        {
        case 1:
            addEmp(1, emp);
            break;
        case 2:
            // Adding Multiple Employees
            printf("\nEnter no. of employees you want to enter:");
            scanf("%d", &numOfEmp);
            addEmp(numOfEmp, emp);
            break;
        case 3:
            printf("\nEnter Employee ID you want to Search:");
            scanf("%d", &id);
            empDetails(id);
            break;
        case 4:
            // viewMulEmp();
            break;
        case 5:
            // addempmsg();
            break;
        default:
            return 0;
        }
    }
    else
    {
        printf("\nYou entered invalid code.");
        admin();
    }

    return 0;
}

//(1)Function to Add Employee/Employees:
void addEmp(int numOfSize, employee emp[])
{

    char confirmation;

    printf("\nAdmin:");
    if (numOfSize == 1)
    {
         printf("\n\nAdd Employee:");
         getchar();
    }   
        
    else
    {
        printf("\n\nAdd Employees:");
        getchar();
    }

    for (int j = 1; j <= numOfSize; j++)
    {

        // Name
        printf("\nEnter Name of the Employee: ");
        fgets(emp[totalEmps].name, MAX, stdin);
        nullAtEnd(emp, "name");
        // Employee ID
        printf("\nEnter Employee ID: ");
        scanf("%d", &emp[totalEmps].employeeID);

        getchar();
        //Department
        printf("Eneter Department: ");
        fgets(emp[totalEmps].department, buff, stdin);
        nullAtEnd(emp, "department");

        // Salary
        printf("\nEnter Employee Salary: ");
        scanf("%d", &emp[totalEmps].salary);
        getchar();

        //Address
        printf("\nEnter Address: \nCity: ");
        fgets(emp[totalEmps].address.city, buff, stdin);
        nullAtEnd(emp, "city");

        printf("\nState: ");
        fgets(emp[totalEmps].address.state, buff, stdin);
        nullAtEnd(emp, "state");

        printf("\nCountry: ");
        fgets(emp[totalEmps].address.country, buff, stdin);
        nullAtEnd(emp, "country");

        //GoTo Label for confirmation if entered invalid character
        confirmationSection:
        printf("\nPress Y/y To Confirm Or N/n To Cancel: ");
        scanf("%c", &confirmation);
        getchar();

        if(confirmation == 'Y'|| confirmation == 'y')
        {
        //Increasing strength of employees after entering all the details 
        totalEmps++;
        }
        else if(confirmation == 'N' || confirmation == 'n')
            break;
        else
        {
            printf("\nEnter a valid confirmation character.");
            
            goto confirmationSection;
        }
    }

    admin();
}

//(2)Viewing Employee Details
void empDetails(int empID)
{

    // //Binary Search to find empID in employee array
    // int s=1, e=totalEmps-1,j=1;
    // while(s<=e)
    // {
    //     int mid = s+e/2;

    //     if(empID == emp[mid].employeeID)
    //     {
    //         j = mid;
    //         s = e+1;
    //     }

    //     if(empID > emp[mid].employeeID)
    //         e = mid;
    //     else
    //         s = mid;
    // }
    int j;
    for (j = 1; j < totalEmps; j++)
    {
        if (emp[j].employeeID == empID)
        {
            printf("\nEmployee %d Details:", empID);
            printf("\n\nName: %s", emp[j].name);
            printf("\nEmployee ID: %d",empID);
            printf("\nDepartment: %s", emp[j].department);
            printf("\nSalary: %d", emp[j].salary);
            printf("\nMeetings:(%d)",emp[j].mnm.meetings);
            printf("\nMessages:(%d)",emp[j].mnm.meetings);
            printf("\nAddress: %s,%s,%s",emp[j].address.city, emp[j].address.state, emp[j].address.country);

            printf("\n\n");
        }
        else
            printf("\nEnter a valid ID.");
    }
}

// This function is to check and replace newline character from end of the char
void nullAtEnd(employee emp[], char *dataMemb)
{
    if (strcmp(dataMemb, "name") == 0)
        emp[totalEmps].name[strcspn(emp[totalEmps].name, "\n")] = '\0';
    else if (strcmp(dataMemb, "department") == 0)
        emp[totalEmps].department[strcspn(emp[totalEmps].department, "\n")] = '\0';
    else if (strcmp(dataMemb, "city") == 0)
        emp[totalEmps].address.city[strcspn(emp[totalEmps].address.city, "\n")] = '\0';
    else if (strcmp(dataMemb, "state") == 0)
        emp[totalEmps].address.state[strcspn(emp[totalEmps].address.state, "\n")] = '\0';
    else if (strcmp(dataMemb, "country") == 0)
        emp[totalEmps].address.country[strcspn(emp[totalEmps].address.country, "\n")] = '\0';
}