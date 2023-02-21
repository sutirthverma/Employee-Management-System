#define MAX 20

// Global variables for adding and editing employees names
int employeeID, salary, messages, meetings;
long int number;
char city[buff], state[buff], country[buff], name[20], department[20];

void addEmp(int numOfSize, employee emp[]);
int employeeSearch(int empID);
void empDetails(int empID);
void editEmpDetails(int empID);
void deleteEmp(int empID);
void nullAtEnd(char *memb);
int confirmationFunc();

int totalEmps = 0;

// Admin Landing Page
int admin()
{
    int option = 0, numOfEmp = 1, id = 1;

    printf("\nAdmin:");
    printf("\n(1)ADD EMPLOYEE.");
    printf("\n(2)ADD MULTIPLE EMPLOYEES.");
    printf("\n(3)EDIT EMPLOYEE DETAILS.");
    printf("\n(4)VIEW EMPLOYEE DETAILS.");
    printf("\n(5)DELETE EMPLOYEE RECORD.");
    printf("\n(6)VIEW EMPLOYEES DETAILS ACCORIDING TO DEPARTMENTS.");
    printf("\n(7)ADD EMPLOYEES MEETINGS AND MESSAGES.");
    printf("\n(8)LOG OUT.");

    printf("\nEnter the respective codes to open the options: ");
    scanf("%d", &option);

    if (option >= 1 && option <= 8)
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
            printf("\nEnter Employee ID you want to Delete:");
            scanf("%d", &id);
            deleteEmp(id);
            break;
        case 6:

            break;
        case 7:
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

    if (option == 8)
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
        fgets(name, MAX, stdin);
        nullAtEnd(name);

        // Employee ID
        printf("\nEnter Employee ID: ");
        scanf("%d", &employeeID);
        getchar();

        // Mobile Number
        printf("\nEnter Employee Mobile Number: ");
        scanf("%ld", &number);
        getchar();

        // Department
        printf("Eneter Department: ");
        fgets(department, buff, stdin);
        nullAtEnd(department);

        // Salary
        printf("\nEnter Employee Salary: ");
        scanf("%d", &salary);
        getchar();

        // Address
        printf("\nEnter Address: \nCity: ");
        fgets(city, buff, stdin);
        nullAtEnd(city);

        printf("\nState: ");
        fgets(state, buff, stdin);
        nullAtEnd(state);

        printf("\nCountry: ");
        fgets(country, buff, stdin);
        nullAtEnd(country);

        // Using confFunc to confirm a new employee addition
        if (confirmationFunc() == 0)
        {
            strcpy(emp[totalEmps].name, name);
            emp[totalEmps].employeeID = employeeID;
            emp[totalEmps].number = number;
            emp[totalEmps].salary = salary;
            strcpy(emp[totalEmps].department, department);
            strcpy(emp[totalEmps].address.city, city);
            strcpy(emp[totalEmps].address.state, state);
            strcpy(emp[totalEmps].address.country, country);

            totalEmps++;
        }
    }

    admin();
}

//(3) Edit Employee Details
void editEmpDetails(int empID)
{

    // Binary Search to find empID in employee array
    int id = employeeSearch(empID);
    int editOpt;

    if (empID == emp[id].employeeID)
    {
        // Calling view employee details function to get reference to what to edit
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
            fgets(emp[id].name, MAX, stdin);
            nullAtEnd(name);
            break;

        case 2:
            // Employee ID
            printf("\nEnter Employee ID: ");
            scanf("%d", &emp[id].employeeID);
            getchar();
            break;

        case 3:
            // Mobile Number
            printf("\nEnter Employee Mobile Number: ");
            scanf("%ld", &emp[id].number);
            getchar();
            break;

        case 4:
            // Department
            printf("Eneter Department: ");
            fgets(emp[id].department, buff, stdin);
            nullAtEnd(department);
            break;

        case 5:
            // Salary
            printf("\nEnter Employee Salary: ");
            scanf("%d", &emp[id].salary);
            getchar();
            break;

        case 6:
            // Address
            printf("\nEnter City: ");
            fgets(emp[id].address.city, buff, stdin);
            nullAtEnd(city);
            break;

        case 7:
            printf("\nEnter State: ");
            fgets(emp[id].address.state, buff, stdin);
            nullAtEnd(state);
            break;

        case 8:
            printf("\nEnter Country: ");
            fgets(emp[id].address.country, buff, stdin);
            nullAtEnd(country);
            break;
        }
        confirmationFunc();
    }
}

//(4)Viewing Employee Details
void empDetails(int empID)
{

    // Binary Search to find empID in employee array
    int id = employeeSearch(empID);

    if (empID == emp[id].employeeID)
    {
        printf("\nEmployee %d Details:", empID);
        printf("\n\nName: %s", emp[id].name);
        printf("\nEmployee ID: %d", empID);
        printf("\nMobile Number: %ld", emp[id].number);
        printf("\nDepartment: %s", emp[id].department);
        printf("\nSalary: %d", emp[id].salary);
        printf("\nMeetings:(%d)", emp[id].mnm.meetings);
        printf("\nMessages:(%d)", emp[id].mnm.meetings);
        printf("\nAddress: %s,%s,%s", emp[id].address.city, emp[id].address.state, emp[id].address.country);

        printf("\n\n");
    }
}

//(5) Delete Employee Details
void deleteEmp(int empID)
{
    int id = employeeSearch(empID);
    if (empID == emp[id].employeeID)
    {
        empDetails(empID);

        printf("\nDeleted the above employee record.");
        for (int i = id; i < totalEmps - 1; i++)
            emp[i] = emp[i + 1];

        totalEmps--;
        return;
    }
}

// Other Functions

// This function is to search for employee entered in various admin functions
int employeeSearch(int empID)
{
    // Binary Search to find empID in employee array
    int s = 0, e = totalEmps, j = 0;
    while (s <= e)
    {
        int mid = s + e / 2;
        int editOpt;

        if (empID == emp[mid].employeeID)
        {
            return mid;
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
void nullAtEnd(char *memb)
{
    memb[strlen(memb) - 1] = '\0';
}

// Confirmation Function

int confirmationFunc()
{
    char confirmation;
// GoTo Label for confirmation if entered invalid character
confirmationSection:
    printf("\nPress Y/y To Confirm Or N/n To Cancel: ");
    scanf("%c", &confirmation);
    getchar();

    if (confirmation == 'Y' || confirmation == 'y')
        return 0;
    else if (confirmation != 'N' && confirmation != 'n')
    {
        printf("\nEnter a valid confirmation character.");
        goto confirmationSection;
    }
    else
        return 1;
}