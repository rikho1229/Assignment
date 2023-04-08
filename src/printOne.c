#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) {
    int found = 1;
    a3Emp *temp;
    temp = headLL;

    if (temp == NULL) {             //Checking for NULL
        printf("Error, list is empty.\n");
        return;
    }

    while (temp != NULL) {
        if (found == whichOne) { //Will print that employees info only if it matches
        printf("Employee ID: %d\n", temp->empId);
        printf("First Name: %s\n", temp->fname);
        printf("Last Name: %s\n", temp->lname);
        printf("Dependents[%d]: ", temp->numDependents);
        for(int i = 0; i < temp->numDependents; i++) {
            printf("%s ", temp->dependents[i]);
        }
        printf("\n");
        return;  
        }
        found++;                   //found is incremented to move to the next position
        temp = temp->nextEmployee; //moves to next pointer such that temp != NULL
    }
    printf("Employee Found!\n");
}