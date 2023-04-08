#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL) {
    a3Emp * temp;
    temp = headLL;
    int num = 0;

    if (temp == NULL) {
        printf("Error, list is unable to sort.\n");
        return;
    }

    while (temp != NULL){ //Traverse through the linked list and keep track of the num of employees which we will use later
        num++;
        temp = temp->nextEmployee;
    }

    a3Emp *empArr[num]; //Creating an array of employee pointers of size num
    temp = headLL;      //Resetting so we can traverse the LL again 

    for (int i = 0; i < num; i++) {     //Iterates through empArr and sets each element to point to the corresponding employee in the LL
        empArr[i] = temp;
        temp = temp->nextEmployee;
    }

    for (int i = 0; i < num - 1; i++) {       //Using the bubble sort algorithm to sort the LL (as seen in lecture slides) 
        for (int j = 0; j < num - i - 1; j++) {
            if (empArr[j]->empId > empArr[j+1]->empId) {
                a3Emp *temp = empArr[j];
                empArr[j] = empArr[j+1];
                empArr[j+1] = temp;
            }
        }
    }
    
    printf("Sorted Linked List:\n\n"); //Printing the sorted link list 
    for (int i = 0;  i < num; i++) {
        printf("Employee ID: %d\n", empArr[i]->empId);
        printf("First Name: %s\n", empArr[i]->fname);
        printf("Last Name: %s\n", empArr[i]->lname);
        printf("Dependents[%d]: ", empArr[i]->numDependents);
        for(int j = 0; j < empArr[i]->numDependents; j++) {
            printf("%s ", empArr[i]->dependents[j]);
        }
        printf("\n\n\n");
    }
}