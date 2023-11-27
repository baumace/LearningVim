/* This is the program for option 1
 * print student scores for a specific student ID#
 */
#include "lab4.h"

void printLine(Node *head, char *Category_Names)
{
	Node *NodePtr;
	int StudentID;

#ifdef DEBUG
	printf("Student Data. Head List is %x\n", head);
#endif
	/* get studentID to use from user	*/
	printf("Enter the Student ID #: ");
	scanf("%i", &StudentID);
	printf("Hunting for %d\n", StudentID);

	/* look for the correct student Node	*/
	NodePtr = get_NodeforID(head, StudentID);

	/* we found it or not	*/
	if(NodePtr == NULL){
		printf("\nERROR: Student ID number %i was not found in the list\n",StudentID);
	}
	else {
		printHeader(Category_Names);
		printStudent(NodePtr);
	}
}

