//Employee Landing Page
int employeeFunc(int *message, int *meeting)
{
    printf("\nEmployee:");
    if (*message > 0 || *meeting > 0)
    {
        if (*message > 0 && *meeting == 0)
            printf("Alert: You have message(%d) alert.", *message);
        else if (*meeting > 0 && *message == 0)
            printf("Alert: You have a meeting(%d) alert.", *meeting);
        else
            printf("Alert: You have (%d)meeting and (%d)message alert.", *meeting, *message);
    }

    int option = 0;
    printf("\n\n(1)VIEW YOUR INFORMATION");
    printf("\n(2)VIEW MESSAGES.");
    printf("\n(3)VIEW MEETINGS.");
    printf("\n(4)SEND MESSAGE.");
    printf("\n(5)LOG OUT.");

    printf("\nEnter the respective codes to open the options: ");
    scanf("%d", &option);

    if (option >= 1 && option <= 5)
    {
        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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

    employeeFunc(message, meeting);
}