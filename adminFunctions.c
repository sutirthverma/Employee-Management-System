#define MAX 20

void addEmp(int numOfSize, employee emp[]);
void empDetails(int empID);
void editEmpDetails(int empID);
void nullAtEnd(employee emp[], char *dataMemb);
void confirmationFunc();

int totalEmps = 1;

// Admin Landing Page
int admin()
{
    int option = 0, numOfEmp = 1, id = 1;

    printf("\nAdmin:");
    printf("\n(1)ADD EMPLOYEE.");
    printf("\n(2)ADD MULTIPLE EMPLOYEES.");
    printf("\n(3)EDIT EMPLOYEE DETAILS.");
    printf("\n(4)VIEW EMPLOYEE DETAILS.");
    printf("\n(5)VIEW EMPLOYEES DETAILS ACCORIDING TO DEPARTMENTS.");
    printf("\n(6)ADD EMPLOYEES MEETINGS AND MESSAGES.");
    printf("\n(7)LOG OUT.");

    printf("\nEnter the respective codes to open the options: ");
    scanf("%d", &option);

    if (option >= 1 && option <= 7)
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
            printf("\nEnter Employee ID you want to Edit:");
            scanf("%d", &id);
            editEmpDetails(id);
            break;
        case 4:
            printf("\nEnter Employee ID you want to Search:");
            scanf("%d", &id);
            empDetails(id);
            break;
        case 5:
            // viewMulEmp();
            break;
        case 6:
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

    if(option == 7)
        return 0;

    admin();
}

//(1)Function to Add Employee/Employees:
void addEmp(int numOfSize, employee emp[])
{

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

        // Mobile Number
        printf("\nEnter Employee Mobile Number: ");
        scanf("%ld", &emp[totalEmps].number);
        getchar();

        // Department
        printf("Eneter Department: ");
        fgets(emp[totalEmps].department, buff, stdin);
        nullAtEnd(emp, "department");

        // Salary
        printf("\nEnter Employee Salary: ");
        scanf("%d", &emp[totalEmps].salary);
        getchar();

        // Address
        printf("\nEnter Address: \nCity: ");
        fgets(emp[totalEmps].address.city, buff, stdin);
        nullAtEnd(emp, "city");

        printf("\nState: ");
        fgets(emp[totalEmps].address.state, buff, stdin);
        nullAtEnd(emp, "state");

        printf("\nCountry: ");
        fgets(emp[totalEmps].address.country, buff, stdin);
        nullAtEnd(emp, "country");

        // Using confFunc to confirm a new employee addition
        confirmationFunc();
    }

    admin();
}

//(3) Edit Employee Details
void editEmpDetails(int empID)
{

    // Binary Search to find empID in employee array
    int s = 1, e = totalEmps - 1, j = 1;
    while (s <= e)
    {
        int mid = s + e / 2;
        int editOpt;

        if (empID == emp[mid].employeeID)
        {
            j = mid;

            //Calling view employee details function to get reference to what to edit
            empDetails(empID);

            printf("\n(1)EDIT NAME.");
            printf("\n(2)EDIT EMPLOYEE ID.");
            printf("\n(3)EDIT MOBILE NUMBER.");
            printf("\n(4)EDIT DEPARTMENT.");
            printf("\n(5)EDIT SALARY.");
            printf("\n(6)EDIT CITY.");
            printf("\n(7)EDIT STATE.");
            printf("\n(8)EDIT COUNTRY.");
            printf("\n(9)GO BACK.");
            printf("\nEnter the respective codes to edit the detail: ");
            scanf("%d", &editOpt);
            getchar();

            switch (editOpt)
            {
            case 1:
                // Name
                printf("\nEnter Name of the Employee: ");
                fgets(emp[j].name, MAX, stdin);
                nullAtEnd(emp, "name");
                break;

            case 2:
                // Employee ID
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[j].employeeID);
                getchar();
                break;

            case 3:
                // Mobile Number
                printf("\nEnter Employee Mobile Number: ");
                scanf("%ld", &emp[j].number);
                getchar();
                break;

            case 4:
                // Department
                printf("Eneter Department: ");
                fgets(emp[j].department, buff, stdin);
                nullAtEnd(emp, "department");
                break;

            case 5:
                // Salary
                printf("\nEnter Employee Salary: ");
                scanf("%d", &emp[j].salary);
                getchar();
                break;

            case 6:
                // Address
                printf("\nEnter City: ");
                fgets(emp[j].address.city, buff, stdin);
                nullAtEnd(emp, "city");
                break;

            case 7:
                printf("\nEnter State: ");
                fgets(emp[j].address.state, buff, stdin);
                nullAtEnd(emp, "state");
                break;

            case 8:
                printf("\nEnter Country: ");
                fgets(emp[j].address.country, buff, stdin);
                nullAtEnd(emp, "country");
                break;
            }
            confirmationFunc();
            break;
        }

        if (empID > emp[mid].employeeID)
            e = mid - 1;
        else
            s = mid + 1;
    }

    if (s > e)
        printf("\nError: Enter a valid ID.\n\n");
}

//(4)Viewing Employee Details
void empDetails(int empID)
{

    // Binary Search to find empID in employee array
    int s = 1, e = totalEmps - 1, j = 1;
    while (s <= e)
    {
        int mid = s + e / 2;

        if (empID == emp[mid].employeeID)
        {
            j = mid;

            printf("\nEmployee %d Details:", empID);
            printf("\n\nName: %s", emp[j].name);
            printf("\nEmployee ID: %d", empID);
            printf("\nMobile Number: %ld", emp[j].number);
            printf("\nDepartment: %s", emp[j].department);
            printf("\nSalary: %d", emp[j].salary);
            printf("\nMeetings:(%d)", emp[j].mnm.meetings);
            printf("\nMessages:(%d)", emp[j].mnm.meetings);
            printf("\nAddress: %s,%s,%s", emp[j].address.city, emp[j].address.state, emp[j].address.country);

            printf("\n\n");

            break;
        }

        if (empID > emp[mid].employeeID)
            e = mid - 1;
        else
            s = mid + 1;
    }

    if (s > e)
        printf("\nError: Enter a valid ID.\n\n");
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

// Confirmation Function

void confirmationFunc()
{
    char confirmation;
    // GoTo Label for confirmation if entered invalid character
confirmationSection:
    printf("\nPress Y/y To Confirm Or N/n To Cancel: ");
    scanf("%c", &confirmation);
    getchar();

    if (confirmation == 'Y' || confirmation == 'y')
    {
        // Increasing strength of employees after entering all the details
        totalEmps++;
    }
    else if (confirmation != 'N' || confirmation != 'n')
    {
        printf("\nEnter a valid confirmation character.");
        goto confirmationSection;
    }
}