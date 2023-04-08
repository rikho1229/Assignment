#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {
    int pos = 1;
    a3Emp *temp = headLL;

    while(temp != NULL) { //Traverses through the LL
        char *fn = malloc(sizeof(char) * (25 * 2 + 1)); //Allocates memory for full name using MAX_LENGTH (25) * 2 (because fname and lname) + 1 for null terminator
        strcpy(fn, temp->fname); //copies fname into fn 
        strcat(fn, " ");         //concatenates " " for the space between fname and lname
        strcat(fn, temp->lname); //concatenates lname into fn

        if(strcmp(fn, whichName) == 0) { //When found, if statement returns the position
            free(fn);
            return pos;
        }
        free(fn);                       //Otherwise memory is freed, continues to traverse, and increments position 
        temp = temp->nextEmployee;
        pos++;
    }
    return -1; //indicates that employee was not found
}