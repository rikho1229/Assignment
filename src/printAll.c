#include "../include/headerA3.h"

void printAll (struct employee * headLL) {
    a3Emp * temp;
    temp = headLL;

    if (temp == NULL) { //Checking for NULL
        printf("Error, list is empty.\n");
        return;
    }

    while (temp != NULL) { //Traverses through LL and prints out each employees info one by one
        printf("Employee ID: %d\n", temp->empId);
        printf("First Name: %s\n", temp->fname);
        printf("Last Name: %s\n", temp->lname);
        printf("Dependents[%d]: ", temp->numDependents);
        for(int i = 0; i < temp->numDependents; i++) {
            printf("%s ", temp->dependents[i]);
        }
        printf("\n\n");
        temp = temp->nextEmployee; //moves to the next pointer such that temp != NULL
    }   
}