#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL) {
    a3Emp * newEmp = malloc(sizeof(a3Emp)); //creating a new employee and allocating space for the information that will be entered
    int empId = 0;
    int idFound = 0;
    char choice = 'y';
    int numDependents = 0;

    if (newEmp == NULL) {
        printf("Error allocating memory.\n");
        return;
    }
    //Entering basic data for the employee
    printf("\nEnter the first name of the employee: ");
    scanf("%s", newEmp->fname);
    printf("\nEnter the last name of the employee: ");
    scanf("%s", newEmp->lname);
    
    //Taking dependent names and prompting user with choice of continuing or not
    newEmp->dependents = malloc(sizeof(char *));
    while (choice == 'y' || choice == 'Y') {
        printf("\nEnter name of depedent #%d: ", numDependents + 1);
        newEmp->dependents[numDependents] = malloc(sizeof(char) * MAX_LENGTH);
        scanf("%s", newEmp->dependents[numDependents]);
        numDependents++;
        newEmp->dependents = realloc(newEmp->dependents, sizeof(char*) * (numDependents + 1));
        printf("\nDo you have anymore dependents? Please enter 'y' for yes and 'n' for no: " );
        scanf(" %c", &choice);
    }
    newEmp->numDependents = numDependents;
    printf("\nYou have %d dependents.\n", numDependents);

    //Generating empId
    for (int i = 0; i < strlen(newEmp->fname); i++) {
        empId = empId + newEmp->fname[i];
    }

    empId = empId + strlen(newEmp->lname);
    a3Emp * current = *headLL;

    while(idFound){
        idFound = 1;
        while(current != NULL) {
            if (current->empId == empId) {
                idFound = 1;
                empId = empId + rand() % 999 + 1;
                break;
            }
            current = current->nextEmployee;
        }
        if (current == NULL) {
            idFound = 0;
        }
    }
    newEmp->empId = empId;
    printf("\nYour computer-generated empId is %d.\n", empId);

    newEmp->nextEmployee = NULL; //indicating that it is located at the end of the linked list

    a3Emp* temp = *headLL;
    while (temp->nextEmployee != NULL) { //Traversing linked list to add the new node to the end of the list 
        temp = temp->nextEmployee;
    } 

    temp->nextEmployee = newEmp;

    return;
}
