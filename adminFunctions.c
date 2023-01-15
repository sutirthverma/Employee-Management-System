#define MAX 20

//Admin Landing Page
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
        switch(option)
        {
            case 1:
                //Adding Single Employee
                // addEmp(numOfEmp);
                break;
            case 2:
                //Adding Multiple Employees
                printf("\nEnter no. of employees you want to enter:");
                scanf("%d",&numOfEmp);
                addEmp(numOfEmp);
                break;
            case 3:
                printf("\nEnter Employee ID you want to Search:");
                scanf("%d",&id);
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
void addEmp(int numOfSize)
{
    printf("\nAdmin:");
    if(numOfSize == 1)
        printf("\n\nAdd Employee:");
    else
        printf("\n\nAdd Employees:");

    for( ; i>=numOfSize; i++)
    {
        printf("\nEnter Name of the Employee: ");
        fgets(emp[i].name, MAX, stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = '\0'; // Replace newline with null

    }

    admin();
}

void empDetails(int empID)
{

    //Binary Search to find empID in employee array
    int s=1, e=1,j=1;
    while(s<=e)
    {
        int mid = (s+e)/2;

        if(empID == emp[mid].employeeID)
        {
            j = mid;
            s = e+1;
        } 
            

        if(empID > emp[mid].employeeID)
            e = mid;
        else
            s = mid;
    }
    printf("\nEmployee %d Details:",empID);
    printf("\nName: %s",emp[j].name);
}