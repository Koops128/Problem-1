/***********************************************************************************************
* Pcb.c
*
* Programming Team:
* Sean Markus
* Wing-Sea Poon
* Abigail Smith
* Tabi Stein
*
* Date: 1/22/16
*
* Description:
* This C file implements the class and methods for the process control block.
*
************************************************************************************************/

#include "Pcb.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
typedef struct {
	int priority;
	int ID;
	struct PCB * next;
} PCB;
*/

void PCBSetPriority(PcbPtr pcb, int priority) {
	pcb->priority = priority;

}

void PCBSetID(PcbPtr pcb, int id) {
	pcb->ID = id;
}

void PCBSetState(PcbPtr pcb, State newState) {
	pcb->state = newState;
}

/**
 * Sets the PC for this PCB.
 */
void PCBSetPC(PcbPtr pcb, unsigned int newPC) {
	pcb->PC = newPC;
}

/**
 * Returns PC of this PCB.
 */
unsigned int PCBGetPC(PcbPtr pcb) {
	return pcb->PC;
}

int PCBGetPriority(PcbPtr pcb) {
	return pcb->priority;
}

int PCBGetID(PcbPtr pcb) {
	return pcb->ID;
}

State PCBGetState(PcbPtr pcb) {
	return pcb->state;
}

 PcbPtr PCBNew(){
	PcbPtr pcb = (PcbPtr) malloc(sizeof(PcbStr));
	pcb->ID = 1;
	pcb->priority = 1;
	pcb->state = ready;

	return pcb;
}

char *PCBToString(PcbPtr pcb) {
	char * emptyStr = (char*) malloc(sizeof(char) * 100);
	emptyStr[99] = '\0';
	int lenNeeded = sprintf(emptyStr, "ID: %d, Priority: %d, Next PCB ID: ", pcb->ID, pcb->priority);

	char * nextIDString = (char*)malloc(sizeof(char) * 5);
	sprintf(nextIDString, "NULL");

	nextIDString = (char *) malloc(sizeof(char) * 100);
	sprintf(nextIDString, "%d", pcb->state);

	int addedLen = strlen(nextIDString);
	char * retString = (char *) malloc(sizeof(char) * (lenNeeded + addedLen));
	sprintf(retString, "%s %s", emptyStr, nextIDString);
	free(emptyStr);
	free(nextIDString);
	return retString;

}

void PCBDestroy(PcbPtr pcb) {
	//free (pcb->ID);
	//free (pcb->priority);
	free (pcb);
	pcb = NULL;
}

/*
int main() {
	PCB * pcb1;
	pcb1 = newPCB();
	pcb1->ID = 123;
	pcb1->priority = 3;

	PCB * pcb2;
	pcb2 = newPCB();
	pcb2->ID = 456;
	pcb2->priority = 5;

	pcb1->next = pcb2;

	printf("%s\n",toString(pcb1));

	return 0;
}

*/
