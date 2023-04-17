#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TotalEmp 100
#define buff 20
#define PASS 20
// Dependent Structure ->
// Address of Employee
typedef struct
{
    char city[buff];
    char state[buff];
    char country[buff];
} address;

// Meeting and Messages
typedef struct
{
    int meetings;
    int messages;
} mnm;

// Parent Structure ->
// Employee Main Structure
typedef struct
{
    char name[20];
    int employeeID;
    long int number;
    char department[20];
    int salary;
    mnm mnm;
    address address;
} employee;

employee emp[100];

#include "adminFunctions.c"

int main();
int admin();

int main()
{
    int loginNum;
    char adminPass[PASS] = "admin123";
    char userPass[PASS];
    char password[20];
    static int chances = 3;

    // Landing Section
    printf("\nEmployee Management System:\n");
    printf("(1)Admin Login");
    printf("\n\nEnter [1] for Admin Login");
    if (chances != 3)
        printf("[Chances Left - %d:]", chances);
    else
        printf(": ");
    scanf("%d", &loginNum);

    // User will get 3 chances to enter valid login otherwise app will close
    if (loginNum != 1 && loginNum != 2)
    {
        chances--;
        printf("Enter a valid login number.");
        if (chances == 0)
        {
            printf("\nUndefined Behaviour");
            return 0;
        }
        else
            main();
    }
    // If User entered valid value then continue
    else
    {

        // Admin Login
        if (loginNum == 1)
        {
            printf("\nEnter Admin Password: ");
            getchar();
            fgets(userPass, PASS, stdin);
            userPass[strcspn(userPass, "\n")] = '\0'; // Replace newline with null
            if (strcmp(userPass, adminPass) == 0)
            {
                admin();
                main();
            }
            else
            {
                printf("\nYou Entered Wrong Password.");
                main();
            }
        }
    }
    return 0;
}