#include "../include/headerA3.h"

void fireAll(a3Emp ** headLL) {
    char choice;
    printf("Are you sure you want to fire everyone: "); //choice for user input
    scanf(" %c", &choice);

    if (choice == 'y') {    //condition for input 'y'
        a3Emp *temp = *headLL;
        while (temp != NULL) {
            a3Emp *temp2 = temp;       //temp2 holds the current node so we can delete it without losing access to next node in LL
            temp = temp->nextEmployee;
            free(temp2);
        }
        *headLL = NULL; //After all nodes are deleted to indicate that LL is empty
        printf("All fired. Linked list is now empty.\n");
    }

    else {   //condition for input 'n'
        printf("No one was fired.\n");
    }
}