#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {
    int pos = 1;
    a3Emp * search = headLL;

    while (search != NULL) {   //Traverse through LL
        if (search->empId == whichEmpId) { //returns position when if statement condition is met
            return pos;
        }
        search = search->nextEmployee; //Moves pointer to the next element in the linked list
        pos++;                         //position is incremeneted to represent the current position in the LL
    }
    return -1; //If empID is not found we indicate to the program it was unsuccessful
}