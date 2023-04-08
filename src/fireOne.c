#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne) {
    a3Emp *temp = *headLL;
    a3Emp *next = (*headLL)->nextEmployee;

    if(*headLL == NULL) {
        printf("Error, Linked list is empty");
        return;
    }

    //First check if the employee is at the head of the LL, position 1

    if (whichOne == 1) { 
        a3Emp *temp = *headLL;
        *headLL = (*headLL)->nextEmployee;  //Sets the new head of the LL to nextEmployee
        printf("Employee [Id: %d] fired.\n", temp->empId);
        free(temp);
        return;
    }

    //Otherwise, check the remaining spots in the LL
    int count = 2;      //Initializes count at 2 to start at the 2nd position
    while(next != NULL) { //Traverses through LL to search for employee
        if(count == whichOne) {
            temp->nextEmployee = next->nextEmployee;
            printf("Employee [Id: %d] fired.\n", temp->empId);
            return;
        }
        temp = next;               //These two lines update to the next pointer in LL, count increments for the next position
        next = next->nextEmployee;
        count++;
    }
    printf("Employee could not be found in LL.\n");   //If employee was not found and could not be fired
}