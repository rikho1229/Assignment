#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {
    int count = 0;
    a3Emp *temp;
    temp = headLL;
    if (temp == NULL) {
        printf("Error, list is empty.");
        return 0;
    }

    while (temp != NULL) {          //Standard traversing through linked lists
        count++;                    //Increment count before moving onto the next node in the linked list because we are starting at 0
        temp = temp->nextEmployee;  //After increment of count temp moves to the next node and while loop continues for as long as temp != NULL
    }
    return count;
}