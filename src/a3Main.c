#include "../include/headerA3.h"

int main () {
    int userChoice = 0;
    a3Emp *head = NULL;
    a3Emp *temp;
    char proFile[MAX_LENGTH];
    strcpy(proFile, "proFile.txt");

    loadEmpData(&head, proFile); //Loads data from the proFile.txt file 
    temp = head;

    do {
        //Menu options for every function including exit which terminates program
        printf("\nSelect an option from 1-10:\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of ALL employees\n");
        printf("3. Print data of ONE employee\n");
        printf("4. Search for employee on ID\n");
        printf("5. Search for employee on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort employees on ID number\n");
        printf("8. Fire ONE employee\n");
        printf("9. Fire ALL employees\n");
        printf("10. Exit\n");
        //User input to select which function to use
        printf("\nEnter your choice here: ");
        scanf("%d", &userChoice);
        printf("\n");

        switch (userChoice) {
            case 1: { //Function 1 Add employee to end of LL
                recruitEmployee(&head); 
                break;
            }
            case 2: {
                printAll(temp); //Function 2 print all Employees
                break;
            }
            case 3: {
                int pos; //Function 3, user input to search for employee at position of choice
                printf("Enter a position: ");
                scanf("%d", &pos);
                printOne(head, pos);
                break;
            }
            case 4: {
                int tempID; //Function 4, user input to search for employee based on empId
                printf("Enter the Employee ID you wish to search: ");
                scanf("%d", &tempID);
                int pos = lookOnId(head, tempID);
                if(pos == -1) {
                    printf("Employee was not found.\n");
                }
                else {
                    printf("Employee was found at position %d.\n", pos);
                }
                break;
            }
            case 5: {
                char fn[100];
                printf("Enter the full name of the employee: "); 
                getchar(); //To avoid seg faults
                fgets(fn, sizeof(fn), stdin); //gets string that user enters
                int length = strlen(fn);
                if(fn[length-1] == '\n'){ //getting rid of newline character for null terminator
                    fn[length-1] = '\0';
                }

                int pos = lookOnFullName(head, fn); //Function 5, searches for employee based on name enter and it will either find it and display the result or display a different result
                if(pos == -1) {
                    printf("Employee was not found.\n");
                }
                else {
                    printf("Employee was found at position %d.\n", pos);
                }
                break;
            }
            case 6: {
                printf("The Total number of employees is: %d.\n", countEmployees(head)); //Function 6 counts employees in LL
                break;
            }
            case 7: {
                sortEmployeesId(head); //Function 7 sorts employees based on empId, lowest - highest
                break;
            }
            case 8: {
                int fire;
                printf("There are currently %d employees.\n", countEmployees(head)); //Displays current num of employees
                printf("Which employee do you wish to fire enter a value between 1 and %d: ", countEmployees(head)); //asks user from 1-number of Employees, which ONE to fire
                scanf("%d", &fire); //takes user  input
                fireOne(&head, fire); //passes it to function 8, to delete that node
                printf("\nThere are now %d employees.\n", countEmployees(head)); //prints final statement
                break;
            }
            case 9: {
                fireAll(&head); //Function 9, Deletes all nodes from the LL
                break;
            }
            case 10: { //Exits the program
                break;
            }
        }


    } while (userChoice >= 1 && userChoice <= 9); //do while loop condition

    return 0;
}